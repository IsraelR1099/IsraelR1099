from django.shortcuts import render, redirect, get_object_or_404
from django.http import HttpResponseRedirect, HttpRequest, JsonResponse
from django.urls import reverse
from django.contrib.auth import authenticate, login, logout
from django.contrib.auth.forms import UserCreationForm
from django.views.decorators.csrf import csrf_exempt
from django.contrib.auth.decorators import login_required
from django.conf import settings

from .models import Users, FriendRequest, FriendList
from .forms import RegistrationForm, UsersAuthenticationForm


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
    print(f"Destination: {destination}")
    if request.POST:
        form = UsersAuthenticationForm(request.POST)
        if form.is_valid():
            email = request.POST["email"].lower()
            password = request.POST["password"]
            user = authenticate(email=email, password=password)
            if user:
                login(request, user)
                if destination:
                    return (redirect(destination))
                return (redirect("index"))
        else:
            context["login_form"] = form
    return (render(request, "user/login.html", context))
#    if request.method == "POST":
#        username = request.POST.get("username")
#        password = request.POST.get("password")
#        # authenticate user
#        user = authenticate(request, username=username, password=password)
#        # check if authentication successful
#        if user is not None:
#            login(request, user)
#            data = {
#                    "id": user.id,
#                    "username": user.username,
#                    "status": "online",
#                    "created_at": user.date_joined.isoformat(),
#                    "updated_at": user.last_login.isoformat(),
#                    "code": "200",
#                    }
#            return (JsonResponse(data))
#        else:
#            data =  {
#                    "error": "User does not exist.",
#                    "code": "404",
#                    }
#            return (JsonResponse(data))
#    return (render(request, "user/login.html"))

@login_required
def logout_view(request: HttpRequest) -> JsonResponse:
    logout(request)
    data = {
        "message": "Logout successful.",
        "status": "success",
            }
    return (JsonResponse(data))

@csrf_exempt
def register_user(request, *args, **kwargs: HttpRequest) -> JsonResponse:
    user = request.user
    if user.is_authenticated:
        data = {
                "error": "User already logged in.",
                "code": "409",
                }
        return (JsonResponse(data))
    context = {}
    if request.POST:
        form = RegistrationForm(request.POST)
        if form.is_valid():
            form.save()
            email = form.cleaned_data.get("email").lower()
            raw_password = form.cleaned_data.get("password1")
            account = authenticate(email=email, password=raw_password)
            login(request, account)
            destination = get_redirect_if_exists(request)
            if destination:
                return (redirect(destination))
            return (redirect("index"))
        else:
            context["registration_form"] = form
    return (render(request, "user/register.html", context))
#    form = UserCreationForm()
#    if request.method == "POST":
#        form = UserCreationForm(request.POST)
#        if form.is_valid():
#            form.save()
#            username = form.cleaned_data.get("username")
#            password1 = form.cleaned_data.get("password1")
#            password2 = form.cleaned_data.get("password2")
#            # authenticate user
#            user = authenticate(request, username=username, password=password1)
#            login(request, user)
#            data = {
#                    "id": user.id,
#                    "username": user.username,
#                    "status": "online",
#                    "created_at": user.date_joined.isoformat(),
#                    "updated_at": user.last_login.isoformat(),
#                    "code": "201",
#                    }
#
#            return (JsonResponse(data))
#        else:
#            # Check if username is taken
#            if "username" in form.errors:
#                username_errors = form.errors["username"]
#                user_exists_error = "A user with that username already exists." in username_errors
#                data = {
#                        "error": username_errors,
#                        "code": "409",
#                        }
#                return (JsonResponse(data))
#            else:
#                error_message = form.errors.as_json()
#                data = {
#                        "error_message": error_message,
#                        "code": "422",
#                        }
#                return (JsonResponse(data))
#    return (render(request, "user/register.html", {
#        "form": form
#        }))

@login_required
def send_friend_request(request, user_id):
    print(f"Sending friend requests to user {user_id}")
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

        # Define template variables
        is_self = True
        is_friend = False
        user = request.user
        if user.is_authenticated and user != account:
            is_self = False
        elif not user.is_authenticated:
            is_self = False

        context['is_self'] = is_self
        context['is_friend'] = is_friend
        context['BASE_URL'] = settings.BASE_URL

        return (render(request, "user/account.html", context))

def account_search_view(request, *args, **kwargs):
    context = {}
    if request.method == "GET":
        #This search query looks for the q on the url.
        search_query = request.GET.get("q")
        if len(search_query) > 0:
            # We use icontains to not take in consideration upper case and
            # lower case. filter allows us to search for different queries
            # inside our db. distinct takes care if there is multiple results
            # in our search
            search_results = Users.objects.filter(email__icontains=search_query).filter(
                    username__icontains=search_query).distinct()
            # The structure of accounts is the followed:
            # accounts = [(User1, True(depending if they are friends or not)),
            # User2, False]
            accounts = []
            for account in search_results:
                accounts.append((account, False))
            context['accounts'] = accounts

    return (render(request, "user/search_results.html", context))
