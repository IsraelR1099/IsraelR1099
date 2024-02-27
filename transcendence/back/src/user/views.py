from django.shortcuts import render, redirect, get_object_or_404
from django.http import HttpResponseRedirect, HttpRequest, JsonResponse
from django.http import HttpResponse
from django.urls import reverse
from django.contrib.auth import authenticate, login, logout
from django.contrib.auth.forms import UserCreationForm
from django.views.decorators.csrf import csrf_exempt
from django.contrib.auth.decorators import login_required
from django.conf import settings
from django.core.serializers.json import DjangoJSONEncoder
from django.core.serializers import serialize
from django.db.models.fields.files import FieldFile
from django.middleware.csrf import get_token

from rest_framework_simplejwt.tokens import RefreshToken, TokenError
from rest_framework.decorators import api_view, authentication_classes, permission_classes
from rest_framework_simplejwt.authentication import JWTAuthentication
from rest_framework.permissions import IsAuthenticated


import json
import logging
import os

from .models import Users, FriendRequest, FriendList
from .forms import RegistrationForm, UsersAuthenticationForm, UsersUpdateForm
from .utils import get_friend_request_or_false
from .utils import process_profile_image, save_image_to_folder
from .utils import generate_response, get_image_as_base64
from .friend_request_status import FriendRequestStatus
from .tokens import create_jwt_pair_for_user


# Create your views here.

@csrf_exempt
def index(request):
    if not request.user.is_authenticated:
        return (HttpResponseRedirect(reverse("login")))
    return (render(request, "user/user.html"))


def get_redirect_if_exists(request):
    """
    This function checks if in the URL there is a next parameter
    if so then it returns to the URL to redirect
    https://example.com/login/?next=/dashboard/
    """

    redirect = None
    if request.GET:
        if request.GET.get("next"):
            redirect = str(request.GET.get("next"))
    return (redirect)


def get_csrf_token(request):
    """ This function returns the csrf token. """
    token = get_token(request)
    logging.debug("token csrf is %s", token)
    return (JsonResponse({"csrf_token": token}))


# @csrf_exempt
def login_view(request, *args, **kwargs: HttpRequest) -> JsonResponse:
    context = {}
    user = request.user
    if user.is_authenticated:
        context["error"] = "You are already logged in."
        return (JsonResponse(context, encoder=DjangoJSONEncoder))
    destination = get_redirect_if_exists(request)
    if request.method == "POST":
        try:
            json_data = request.body.decode("utf-8")
            json_data = json.loads(json_data)
            form = UsersAuthenticationForm(json_data)
            if form.is_valid():
                username = json_data["username"]
                password = json_data["password"]
                user = authenticate(username=username, password=password)
                if user:
                    login(request, user)
                    tokens = create_jwt_pair_for_user(user)
                    context = generate_response(
                            "200", user=user, tokens=tokens)
                    if destination:
                        return (redirect(destination))
                    return (JsonResponse(context, encoder=DjangoJSONEncoder))
                else:
                    logging.debug("user is not valid")
            else:
                context["login_form"] = form
                errors = {}
                for field, field_errors in form.errors.items():
                    errors[field] = field_errors
        except json.JSONDecodeError:
            errors = {"JSONDecodeError": "Please provide a valid JSON."}
            context = generate_response("401", error_message=errors)
            return (JsonResponse(context, encoder=DjangoJSONEncoder))
        context = generate_response("401", error_message=errors)
    return (JsonResponse(context, encoder=DjangoJSONEncoder))


@login_required
@csrf_exempt
@api_view(["POST"])
def logout_view(request: HttpRequest) -> JsonResponse:
    """ Blacklist the refresh token: extract the token from the request
    object. Refresh token is blacklisted because this token has a longer
    lifetime than the access token. """
    logout(request)
    refresh_token = request.data.get("refresh_token")
    if refresh_token:
        try:
            token = RefreshToken(refresh_token)
            token.blacklist()
            context = {
                    "message": "Logout successful.",
                    "status": "success",
                    }
            logging.debug("context is %s", context)
            return (JsonResponse(
                context, encoder=DjangoJSONEncoder, status=200))
        except TokenError as e:
            context = {
                    "message": "Logout failed.",
                    "status": "failed",
                    "error": str(e),
                    }
            logging.debug("context is %s", context)
            return (JsonResponse(
                context, encoder=DjangoJSONEncoder, status=401))
    else:
        context = {
            "message": "Refresh token not provided.",
            "status": "error",
                }
    return (JsonResponse(context, encoder=DjangoJSONEncoder, status=401))


@csrf_exempt
def register_user(request, *args, **kwargs: HttpRequest) -> JsonResponse:
    context = {}
    user = request.user
    if user.is_authenticated:
        context["error"] = "You are already registered and logged in."
        return (JsonResponse(context, encoder=DjangoJSONEncoder, status=400)) 
    if request.method == "POST":
        try:
            json_data = request.body.decode("utf-8")
            json_data = json.loads(json_data)
            logging.debug("json_data is %s", json_data)
            form = RegistrationForm(json_data)
            if form.is_valid():
                form.save()
                username = form.cleaned_data.get("username")
                raw_password = form.cleaned_data.get("password1")
                account = authenticate(
                        username=username, password=raw_password)
                login(request, account)
                tokens = create_jwt_pair_for_user(account)
                destination = get_redirect_if_exists(request)
                if destination:
                    return (redirect(destination))
                context = generate_response("201", user=account, tokens=tokens)
                logging.debug("context on succes %s", context)
                return (JsonResponse(
                    context, encoder=DjangoJSONEncoder, status=201))
            else:
                errors = {"error": form.errors}
                context = generate_response("401", error_message=form.errors)
        except json.JSONDecodeError:
            errors = {"JSONDecodeError": "Please provide a valid JSON."}
            context = generate_response("401", error_message=errors)
            logging.debug("context is %s", context)
            return (JsonResponse(
                context, encoder=DjangoJSONEncoder, status=401))
    else:
        context = {"error": "Method not allowed."}
    logging.debug("context before is %s", context)
    return (JsonResponse(context, encoder=DjangoJSONEncoder, status=400))


@permission_classes([IsAuthenticated])
@authentication_classes([JWTAuthentication])
@api_view(['GET', 'POST'])
def account_view(request, *args, **kwargs):
    """
    Logic for viewing user account
        is_self -> Boolean
        is_friend -> Boolean
            -1: NO_REQUEST_SENT
            0: THEM_SENT_TO_YOU
            1: YOU_SENT_TO_THEM
    """

    logging.debug("entro en account_view")
    context = {}
    user_id = kwargs.get("user_id")
    # if user does not exist we return a 404
    try:
        account = Users.objects.get(pk=user_id)
    except Users.DoesNotExist:
        context['error'] = "User not found."
        return (JsonResponse(context, encoder=DjangoJSONEncoder, status=404))
    # if user exists we check if they are a friend
    if account:
        context['id'] = account.id
        context['username'] = account.username
        context['email'] = account.email
        context['hide_email'] = account.hide_email

        if account.profile_image:
            image_path = os.path.join(
                    settings.MEDIA_ROOT, str(account.profile_image))
            encoded_string = get_image_as_base64(image_path)
            if encoded_string:
                context['profile_image_base64'] = encoded_string
            else:
                context['profile_image_base64'] = None
        else:
            context['profile_image_base64'] = None

        try:
            friend_list = FriendList.objects.get(user=account)
        except FriendList.DoesNotExist:
            friend_list = FriendList(user=account)
            friend_list.save()
        # Friend List of the authenticated user
        friends = friend_list.friends.all()
        serialized_friends = []
        for friend in friends:
            serialized_friend = {
                    "id": friend.id,
                    "username": friend.username,
                    }
            if serialized_friend:
                serialized_friends.append(serialized_friend)
        context['friends'] = serialized_friends
        # Define template variables
        is_self = True
        is_friend = False
        user = request.user
        request_sent = FriendRequestStatus.NO_REQUEST_SENT.value
        friend_requests = None
        # If user is authenticated we check if they are a friend
        # If the user is authenticated and the user is not the same as the
        # account
        if user.is_authenticated and user != account:
            is_self = False
            # We check if we are friends on the friend list of the other user
            if friends.filter(pk=user.id):
                is_friend = True
            else:
                is_friend = False
                # Case 1: Request has been sent from THEM to YOU:
                # FriendRequestStatus.THEM_SENT_TO_YOU
                if get_friend_request_or_false(sender=account, receiver=user) != False:
                    request_sent = FriendRequestStatus.THEM_SENT_TO_YOU.value
                    # We get the id/pk of that specific friend request
                    context['pending_friend_request_id'] = get_friend_request_or_false(sender=account, receiver=user).id
                # Case 2: Request has been sent from YOU to THEM:
                # FriendRequestStatus.YOU_SENT_TO_THEM
                elif get_friend_request_or_false(sender=user, receiver=account) != False:
                    request_sent = FriendRequestStatus.YOU_SENT_TO_THEM.value
                # Case 3: No request sent from YOU or THEM:
                # FriendRequestStatus.NO_REQUEST_SENT
                else:
                    request_sent = FriendRequestStatus.NO_REQUEST_SENT.value
        elif not user.is_authenticated:
            is_self = False
        # If you are looking at your own profile we get all the friend requests
        # that we have set to is_active to true
        else:
            try:
                friend_requests = FriendRequest.objects.filter(receiver=user, is_active=True)
            except:
                pass

        context['is_self'] = is_self
        context['is_friend'] = is_friend
        context['BASE_URL'] = settings.BASE_URL
        context['request_sent'] = request_sent
    logging.debug("context in account view is %s", context)
    return (JsonResponse(context, encoder=DjangoJSONEncoder, status=200))


@csrf_exempt
@api_view(['GET', 'POST'])
@authentication_classes([JWTAuthentication])
@permission_classes([IsAuthenticated])
def edit_account_view(request, *arg, **kwargs):
    if not request.user.is_authenticated:
        context = {"error": "You must be authenticated to edit your profile."}
        return (JsonResponse(context, encoder=DjangoJSONEncoder, status=403))
    user_id = kwargs.get("user_id")
    context = {}
    try:
        user = Users.objects.get(pk=user_id)
    except Users.DoesNotExist:
        context['error'] = "User not found."
        return (JsonResponse(context, encoder=DjangoJSONEncoder, status=400))

    if user.pk != request.user.pk:
        context['error'] = "You cannot edit someone elses profile."
        return (JsonResponse(context, encoder=DjangoJSONEncoder, status=400))
    if request.method == "POST":
        # json_data = request.body.decode("utf-8")
        # json_data = json.loads(json_data)

        # Extract and process the profile image
        form = UsersUpdateForm(
                request.POST, request.FILES, instance=request.user)
        if form.is_valid():
            logging.debug("form is valid")
            # Delete the old profile image so the name is preserved
            # user.profile_image.delete()
            form.save()
            # We redirect to the same page to see the changes
            context['success'] = "Profile updated successfully."
            return (JsonResponse(context, encoder=DjangoJSONEncoder, status=200))
            # return (redirect("view", user_id=user_id))
        else:
            logging.debug("form is not valid")
            form = UsersUpdateForm(
                    request.POST, instance=request.user, initial={
                                      "id": user.pk,
                                      "email": user.email,
                                      "username": user.username,
                                      "profile_image": user.profile_image,
                                      "hide_email": user.hide_email,
                                      })
            context['error'] = form.errors
    else:
        logging.debug("request method is not post")
        form = UsersUpdateForm(
                initial={
                    "id": user.pk,
                    "email": user.email,
                    "username": user.username,
                    "profile_image": user.profile_image,
                    "hide_email": user.hide_email,
                    })
        context['error'] = form.errors
    context['DATA_UPLOAD_MAX_MEMORY_SIZE'] = settings.DATA_UPLOAD_MAX_MEMORY_SIZE
    logging.debug("context leaving edit: %s", context)
    return (JsonResponse(context, encoder=DjangoJSONEncoder, status=200))


def account_search_view(request, *args, **kwargs):
    context = {}
    if request.method == "GET":
        # This search query looks for the q on the url.
        search_query = request.GET.get("q")
        if len(search_query) > 0:
            # We use icontains to not take in consideration upper case and
            # lower case. filter allows us to search for different queries
            # inside our db. distinct takes care if there is multiple results
            # in our search and eliminates them, showing just one result.
            # We search for username or email
            search_results = Users.objects.filter(
                    email__icontains=search_query).filter(
                    username__icontains=search_query).distinct()
            # The structure of accounts is the followed:
            # accounts = [(User1, True(depending if they are friends or not)),
            # User2, False]
            accounts = []
            user = request.user
            if user.is_authenticated:
                # We get all the friends of the user
                auth_user_friend_list = FriendList.objects.get(user=user)
                for account in search_results:
                    accounts.append({
                        "id": account.id,
                        "username": account.username,
                        "is_friend": auth_user_friend_list.is_mutual_friend(account)
                    })
                context['accounts'] = accounts
            else:
                for account in search_results:
                    account_info = {
                            "id": account.id,
                            "username": account.username,
                            "is_friend": False,
                            }
                    accounts.append(account_info)
                context['accounts'] = accounts
        else:
            context['error'] = "Please enter a valid search query."
    else:
        context['error'] = "Please provide a valid method."
    logging.debug("context on search is %s", context)
    return (JsonResponse(context, encoder=DjangoJSONEncoder, status=200))


@csrf_exempt
@login_required
def send_friend_request(request, *args, **kwargs):
    payload = {}
    user_id = None
    username = None
    user = request.user
    if request.method == "POST" and user.is_authenticated:
        # The receiver_user_id must be sent by the front end
        body_unicode = request.body.decode("utf-8")
        body_data = json.loads(body_unicode)
        if 'username' in body_data and body_data['username']:
            username = body_data['username']
        else:
            user_id = body_data['receiver_user_id']
        if user_id or username:
            try:
                if username:
                    logging.debug("using username")
                    receiver = Users.objects.get(username=username)
                else:
                    receiver = Users.objects.get(pk=user_id)
                try:
                    # Get any friend requests (active and not-active)
                    friend_requests = FriendRequest.objects.filter(
                            sender=user, receiver=receiver)
                    # find if any of them are active (pending)
                    try:
                        for request in friend_requests:
                            if request.is_active:
                                raise Exception(
                                        "You already sent them a friend request.")
                        # If none are active create a new friend request
                        friend_request = FriendRequest(
                                sender=user, receiver=receiver)
                        friend_request.save()
                        payload['response'] = "Friend request sent."
                    except Exception as e:
                        payload['response'] = str(e)
                except FriendRequest.DoesNotExist:
                    # There are no friend requests so create one.
                    friend_request = FriendRequest(sender=user, receiver=receiver)
                    friend_request.save()
                    payload['response'] = "Friend request sent."
            except Users.DoesNotExist:
                payload['error'] = "The specified username does not exist."

            if payload['response'] == None:
                payload['error'] = "Something went wrong."
        else:
            payload['error'] = "Unable to sent a friend request."
    else:
        payload['error'] = "You must be authenticated to send a friend request."
    logging.debug("payload on send_friend_request: %s", payload)
    return (HttpResponse(json.dumps(payload), content_type="application/json"))


def friend_requests(request, *args, **kwargs):
    context = {}
    user = request.user
    if user.is_authenticated:
        user_id = kwargs.get("user_id")
        account = Users.objects.get(pk=user_id)
        if account == user:
            friend_requests = FriendRequest.objects.filter(receiver=account,
                                                           is_active=True)
            serialized_friend_requests = []
            for request in friend_requests:
                sender_username = request.sender.username
                receiver_username = request.receiver.username
                if request.sender.profile_image:
                    image_path = os.path.join(
                            settings.MEDIA_ROOT, str(account.profile_image))
                    encoded_string = get_image_as_base64(image_path)
                    if encoded_string:
                        serialized_data = {
                                "pk": request.pk,
                                "sender": sender_username,
                                "receiver": receiver_username,
                                "sender_profile_image": encoded_string,
                        }
                    else:
                        serialized_data = {
                                "pk": request.pk,
                                "sender": sender_username,
                                "receiver": receiver_username,
                                "sender_profile_image": "",
                        }
                else:
                    serialized_data = {
                            "pk": request.pk,
                            "sender": sender_username,
                            "receiver": receiver_username,
                            "sender_profile_image": "",
                    }
                serialized_friend_requests.append(serialized_data)
            context['friend_requests'] = serialized_friend_requests
        else:
            context['error'] = "That is not your account."
            logging.debug("context 1 on friend_requests is %s", context)
            return (JsonResponse(
                context, encoder=DjangoJSONEncoder, status=401))
    else:
        context['error'] = "You must be authenticated to view friend requests."
        logging.debug("context 2 on friend_requests is %s", context)
        return (JsonResponse(context, encoder=DjangoJSONEncoder, status=401))
    logging.debug("context 3 on friend_requests is %s", context)
    return (JsonResponse(context, encoder=DjangoJSONEncoder, status=200))


def accept_friend_request(request, *args, **kwargs):
    user = request.user
    payload = {}
    if request.method == "GET" and user.is_authenticated:
        friend_request_id = kwargs.get("friend_request_id")
        if friend_request_id:
            friend_request = FriendRequest.objects.get(pk=friend_request_id)
            # confirm is the correct request
            if friend_request.receiver == user:
                if friend_request:
                    # Found the request, Not accept it.
                    friend_request.accept()
                    payload['response'] = "Friend request accepted."
                else:
                    payload['error'] = "Friend request not found."
            else:
                payload['error'] = "That is not your request to accept."
        else:
            payload['error'] = "Unable to accept that friend request."
    else:
        payload['error'] = "You must be authenticated to accept a friend request."
    logging.debug("payload on accept_friend_request: %s", payload)
    return (JsonResponse(payload, encoder=DjangoJSONEncoder, status=200))


@csrf_exempt
def remove_friend(request, *args, **kwars):
    payload = {}
    user = request.user
    if request.method == "POST" and user.is_authenticated:
        # The receiver_user_id must be sent by the front end
        # the receiver_user_id is the user we are removing from our friend list
        body_unicode = request.body.decode("utf-8")
        body_data = json.loads(body_unicode)
        user_id = body_data.get("receiver_user_id")
        # user_id = request.POST.get("receiver_user_id")
        logging.debug("user_id en remove friend is %s", user_id)
        if user_id:
            try:
                removee = Users.objects.get(pk=user_id)
                friend_list = FriendList.objects.get(user=user)
                friend_list.unfriend(removee)
                payload['response'] = "Successfully removed that friend."
            except Exception as e:
                payload['error'] = str(e)
        else:
            payload['error'] = "Unable to remove that friend."
    else:
        payload['error'] = "You must be authenticated to remove a friend."
    logging.debug("payload on remove_friend: %s", payload)
    return (JsonResponse(payload, encoder=DjangoJSONEncoder, status=200))


def decline_friend_request(request, *args, **kwargs):
    payload = {}
    user = request.user
    if request.method == "GET" and user.is_authenticated:
        friend_request_id = kwargs.get("friend_request_id")
        if friend_request_id:
            friend_request = FriendRequest.objects.get(pk=friend_request_id)
            # confirm it is the correct request
            if friend_request.receiver == user:
                if friend_request:
                    # Found the request. Now decline it.
                    friend_request.decline()
                    payload['response'] = "Friend request declined."
                else:
                    payload['error'] = "Friend request not found."
            else:
                payload['error'] = "That is not your request to decline."
        else:
            payload['error'] = "Unable to decline that friend request."
    else:
        payload['error'] = "You must be authenticated to decline a friend request."
    logging.debug("payload on decline_friend_request: %s", payload)
    return (JsonResponse(payload, encoder=DjangoJSONEncoder, status=200))


@csrf_exempt
def cancel_friend_request(request, *args, **kwargs):
    payload = {}
    user = request.user
    if request.method == "POST" and user.is_authenticated:
        body_unicode = request.body.decode("utf-8")
        body_data = json.loads(body_unicode)
        user_id = body_data.get("receiver_user_id")
        if user_id:
            receiver = Users.objects.get(pk=user_id)
            try:                # for account in search_results:
                    # accounts.append((account,
                                    # auth_user_friend_list.is_mutual_friend(account)))
                    # context['accounts'] = accounts

                friend_requests = FriendRequest.objects.filter(sender=user,
                                                            receiver=receiver,
                                                              is_active=True)
            except FriendRequest.DoesNotExist:
                payload['error'] = "Friend request not found."
            # There should only be a single active friend request at any given
            # time.
            if len(friend_requests) > 1:
                # This is an error. There should only ever be one active friend
                # request at a time.
                for request in friend_requests:
                    request.cancel()
                payload['error'] = "Somehow you have more than one request."
            else:
                # Found the request. Cancel it.
                friend_requests.first().cancel()
                payload['response'] = "Friend request cancelled."
        else:
            payload['error'] = "Unable to cancel that friend request."
    else:
        payload['error'] = "You must be authenticated to cancel a friend request."
    logging.debug("payload on cancel_friend_request: %s", payload)
    return (JsonResponse(payload, encoder=DjangoJSONEncoder, status=200))


def friend_list_view(request, *args, **kwargs):
    context = {}
    user = request.user
    if user.is_authenticated:
        user_id = kwargs.get("user_id")
        if user_id:
            try:
                this_user = Users.objects.get(pk=user_id)
                this_user_dict = []
                for field in this_user._meta.fields:
                    username = this_user.username
                    email = this_user.email

                    if this_user.profile_image:
                        image_path = os.path.join(
                                settings.MEDIA_ROOT, str(this_user.profile_image))
                        encoded_string = get_image_as_base64(image_path)
                        if encoded_string:
                            this_user_dict = {
                                "username": username,
                                "email": email,
                                "profile_image": encoded_string,
                            }
                        else:
                            this_user_dict = {
                                "username": username,
                                "email": email,
                                "profile_image": None,
                            }
                    else:
                        this_user_dict = {
                            "username": username,
                            "email": email,
                            "profile_image": None,
                        }
                    # if not isinstance(getattr(this_user, field.name), FieldFile):
                        # this_user_dict[field.name] = getattr(this_user, field.name)
                context['this_user'] = this_user_dict
            except Users.DoesNotExist:
                context['error'] = "That user does not exist."
            try:
                friend_list = FriendList.objects.get(user=this_user)
            except FriendList.DoesNotExist:
                context['error'] = "Could not find a friend list for this user."

            # Must be friends to view a friends list
            if user != this_user:
                if not user in friend_list.friends.all():
                    context['error'] = "You must be friends to view their friends list."

            friends = []  # [(friend1, True), (friend2, False), ...]
            auth_user_friend_list = FriendList.objects.get(user=user)
            for friend in friend_list.friends.all():
                friends.append(({'friend': friend.username,
                                 'is_friend:':
                                 auth_user_friend_list.is_mutual_friend(friend)}))
            context['friends'] = friends
        else:
            context['error'] = "No user id provided."
    else:
        context['error'] = "You must be authenticated to view a friends list."
    logging.debug("context on friend_list_view: %s", context)
    return JsonResponse(context, encoder=DjangoJSONEncoder, status=200)
