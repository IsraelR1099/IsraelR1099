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
import json
import logging

from .models import Users, FriendRequest, FriendList
from .forms import RegistrationForm, UsersAuthenticationForm, UsersUpdateForm
from .utils import get_friend_request_or_false
from .utils import generate_response
from .friend_request_status import FriendRequestStatus


# Create your views here.

@csrf_exempt
def index(request):
    if not request.user.is_authenticated:
        return (HttpResponseRedirect(reverse("login")))
    return (render(request, "user/user.html"))


def get_redirect_if_exists(request):
    redirect = None
    if request.GET:
        if request.GET.get("next"):
            redirect = str(request.GET.get("next"))
    return (redirect)


@csrf_exempt
def login_view(request, *args, **kwargs: HttpRequest) -> JsonResponse:
    context = {}
    user = request.user
    if user.is_authenticated:
        return (redirect("index"))
    destination = get_redirect_if_exists(request)
    if request.method == "POST":
        try:
            json_data = request.body.decode("utf-8")
            json_data = json.loads(json_data)
            logging.debug("json_data is %s", json_data)
            form = UsersAuthenticationForm(json_data)
            if form.is_valid():
                email = json_data["email"].lower()
                password = json_data["password"]
                logging.debug("email is despues %s", email)
                user = authenticate(email=email, password=password)
                if user:
                    login(request, user)
                    context = generate_response("200", user=user)
                    if destination:
                        return (redirect(destination))
                    return (JsonResponse(context, encoder=DjangoJSONEncoder))
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
def logout_view(request: HttpRequest) -> JsonResponse:
    logout(request)
    context = {
        "message": "Logout successful.",
        "status": "success",
            }
    return (JsonResponse(context, encoder=DjangoJSONEncoder))


@csrf_exempt
def register_user(request, *args, **kwargs: HttpRequest) -> JsonResponse:
    context = {}
    user = request.user
    if user.is_authenticated:
        context["error"] = "You are already registered and logged in."
        return (HttpResponse(
            json.dumps(context), content_type="application/json"))
    if request.method == "POST":
        try:
            json_data = request.body.decode("utf-8")
            json_data = json.loads(json_data)
            form = RegistrationForm(json_data)
            if form.is_valid():
                form.save()
                email = form.cleaned_data.get("email").lower()
                raw_password = form.cleaned_data.get("password1")
                account = authenticate(email=email, password=raw_password)
                login(request, account)
                destination = get_redirect_if_exists(request)
                if destination:
                    return (redirect(destination))
                context = generate_response("201", user=account)
                return (JsonResponse(context, encoder=DjangoJSONEncoder))
            else:
                context["registration_form"] = form
        except json.JSONDecodeError:
            errors = {"JSONDecodeError": "Please provide a valid JSON."}
            context = generate_response("401", error_message=errors)
            return (JsonResponse(context, encoder=DjangoJSONEncoder))
    return (JsonResponse(context, encoder=DjangoJSONEncoder))


@login_required
def send_friend_request(request, user_id):
    user = get_object_or_404(Users, id=user_id)
    friend_request, created = Friendship_Request.objects.get_or_create(
            from_user=request.user,
            to_user=user
            )
    if created:
        print("Friend request sent")
        return (render(request, "user/profile.html"))
    else:
        print("Friend request already sent")
        data = {
                "message": "Friend request already sent.",
                "status": "success",
                }
        return (JsonResponse(data))
#    from_user = request.user
#    to_user = Users.objects.get_object_or_404(Users, id=user_id)
#    friend_request, created = Friendship_Request.objects.get_or_create(
#            requester_id=from_user, addressee_id=to_user)
#    if created:
#        data = {
#                "message": "Friend request sent.",
#                "status": "success",
#                }
#        return (JsonResponse(data))
#    else:
#        data = {
#                "message": "Friend request already sent.",
#                "status": "success",
#                }
#        return (JsonResponse(data))


@login_required
def accept_friend_request(request, request_id):
    from_user = get_object_or_404(Users, id=request_id)
    friend_request = Friendship_Request.objects.filter(
            from_user=from_user,
            to_user=request.user
            ).first()
    user1 = friend_request.to_user
    user2 = from_user
    user1.profile.friends.add(user2.profile)
    user2.profile.friends.add(user1.profile)
    friend_request.delete()
    data = {
            "message": "Friend request accepted.",
            "status": "success",
            }
    return (JsonResponse(data))
#    friend_request = Friendship_Request.objects.get(id=request_id)
#    if friend_request.addressee_id == request.user:
#        friend_request.addressee_id.friends.add(friend_request.requester_id)
#        friend_request.requester_id.friends.add(friend_request.addressee_id)
#        friend_request.delete()
#        data = {
#                "message": "Friend request accepted.",
#                "status": "success",
#                }
#        return (JsonResponse(data))
#    else:
#        data = {
#                "message": "You are not authorized to accept this friend request.",
#                "status": "error",
#                }
#        return (JsonResponse(data))


def account_view(request, *args, **kwargs):
    """
    Logic for viewing user account
        is_self -> Boolean
        is_friend -> Boolean
            -1: NO_REQUEST_SENT
            0: THEM_SENT_TO_YOU
            1: YOU_SENT_TO_THEM
    """
    context = {}
    user_id = kwargs.get("user_id")
    # if user does not exist we return a 404
    try:
        account = Users.objects.get(pk=user_id)
    except Users.DoesNotExist:
        return (HttpResponse("That user does not exist."))
    # if user exists we check if they are a friend
    if account:
        context['id'] = account.id
        context['username'] = account.username
        context['email'] = account.email
        context['profile_image'] = account.profile_image.url
        context['hide_email'] = account.hide_email

        try:
            friend_list = FriendList.objects.get(user=account)
        except FriendList.DoesNotExist:
            friend_list = FriendList(user=account)
            friend_list.save()
        friends = friend_list.friends.all()
        context['friends'] = friends
        # Define template variables
        is_self = True
        is_friend = False
        user = request.user
        request_sent = FriendRequestStatus.NO_REQUEST_SENT.value
        friend_requests = None
        # If user is authenticated we check if they are a friend
        if user.is_authenticated and user != account:
            is_self = False
            if friends.filter(pk=user.id):
                is_friend = True
            else:
                is_friend = False
                # Case 1: Request has been sent from THEM to YOU:
                # FriendRequestStatus.THEM_SENT_TO_YOU
                if get_friend_request_or_false(sender=account, receiver=user) != False:
                    request_sent = FriendRequestStatus.THEM_SENT_TO_YOU.value
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
        else:
            try:
                friend_requests = FriendRequest.objects.filter(receiver=user, is_active=True)
            except:
                pass

        context['is_self'] = is_self
        context['is_friend'] = is_friend
        context['BASE_URL'] = settings.BASE_URL
        context['request_sent'] = request_sent
        context['friend_requests'] = friend_requests
        return (render(request, "user/account.html", context))


def account_search_view(request, *args, **kwargs):
    context = {}
    if request.method == "GET":
        # This search query looks for the q on the url.
        search_query = request.GET.get("q")
        if len(search_query) > 0:
            # We use icontains to not take in consideration upper case and
            # lower case. filter allows us to search for different queries
            # inside our db. distinct takes care if there is multiple results
            # in our search
            search_results = Users.objects.filter(
                    email__icontains=search_query).filter(
                    username__icontains=search_query).distinct()
            # The structure of accounts is the followed:
            # accounts = [(User1, True(depending if they are friends or not)),
            # User2, False]
            accounts = []
            for account in search_results:
                accounts.append((account, False))
            context['accounts'] = accounts

    return (render(request, "user/search_results.html", context))


def edit_account_view(request, *arg, **kwargs):
    if not request.user.is_authenticated:
        return (redirect("login"))
    user_id = kwargs.get("user_id")
    try:
        user = Users.objects.get(pk=user_id)
    except Users.DoesNotExist:
        return (HttpResponse("Something went wrong."))
    if user.pk != request.user.pk:
        return (HttpResponse("You cannot edit someone elses profile."))
    context = {}
    if request.POST:
        form = UsersUpdateForm(
                request.POST, request.FILES, instance=request.user)
        if form.is_valid():
            # Delete the old profile image so the name is preserved
            user.profile_image.delete()
            form.save()
            # We redirect to the same page to see the changes
            return (redirect("view", user_id=user_id))
        else:
            form = UsersUpdateForm(
                    request.POST, instance=request.user, initial={
                                      "id": user.pk,
                                      "email": user.email,
                                      "username": user.username,
                                      "profile_image": user.profile_image,
                                      "hide_email": user.hide_email,
                                      })
            context['form'] = form
    else:
        form = UsersUpdateForm(
                initial={
                    "id": user.pk,
                    "email": user.email,
                    "username": user.username,
                    "profile_image": user.profile_image,
                    "hide_email": user.hide_email,
                    })
        context['form'] = form
    context['DATA_UPLOAD_MAX_MEMORY_SIZE'] = settings.DATA_UPLOAD_MAX_MEMORY_SIZE
    return (render(request, "user/edit_account.html", context))


def send_friend_request(request, *args, **kwargs):
    user = request.user
    payload = {}
    if request.method == "POST" and user.is_authenticated:
        user_id = request.POST.get("receiver_user_id")
        if user_id:
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

            if payload['response'] == None:
                payload['response'] = "Something went wrong."
        else:
            payload['response'] = "Unable to sent a friend request."
    else:
        payload['response'] = "You must be authenticated to send a friend request."
    return (HttpResponse(json.dumps(payload), content_type="application/json"))
