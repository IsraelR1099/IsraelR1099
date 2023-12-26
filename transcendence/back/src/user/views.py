from django.shortcuts import render
from django.http import HttpResponseRedirect, HttpRequest, JsonResponse
from django.urls import reverse
from django.contrib.auth import authenticate, login, logout
from django.contrib.auth.forms import UserCreationForm
from django.views.decorators.csrf import csrf_exempt
from django.contrib.auth.decorators import login_required
from .models import Users, FriendRequest, FriendList
from django.shortcuts import get_object_or_404

# Create your views here.

@csrf_exempt
def index(request):
    if not request.user.is_authenticated:
        return (HttpResponseRedirect(reverse("login")))
    return (render(request, "user/user.html"))

@csrf_exempt
def login_view(request: HttpRequest) -> JsonResponse:
    if request.method == "POST":
        username = request.POST.get("username")
        password = request.POST.get("password")
        # authenticate user
        user = authenticate(request, username=username, password=password)
        # check if authentication successful
        if user is not None:
            login(request, user)
            data = {
                    "id": user.id,
                    "username": user.username,
                    "status": "online",
                    "created_at": user.date_joined.isoformat(),
                    "updated_at": user.last_login.isoformat(),
                    "code": "200",
                    }
            return (JsonResponse(data))
        else:
            data =  {
                    "error": "User does not exist.",
                    "code": "404",
                    }
            return (JsonResponse(data))
    return (render(request, "user/login.html"))

@login_required
def logout_view(request: HttpRequest) -> JsonResponse:
    logout(request)
    data = {
        "message": "Logout successful.",
        "status": "success",
            }
    return (JsonResponse(data))

@csrf_exempt
def register_user(request: HttpRequest) -> JsonResponse:
    form = UserCreationForm()
    if request.method == "POST":
        form = UserCreationForm(request.POST)
        if form.is_valid():
            form.save()
            username = form.cleaned_data.get("username")
            password1 = form.cleaned_data.get("password1")
            password2 = form.cleaned_data.get("password2")
            # authenticate user
            user = authenticate(request, username=username, password=password1)
            login(request, user)
            data = {
                    "id": user.id,
                    "username": user.username,
                    "status": "online",
                    "created_at": user.date_joined.isoformat(),
                    "updated_at": user.last_login.isoformat(),
                    "code": "201",
                    }

            return (JsonResponse(data))
        else:
            # Check if username is taken
            if "username" in form.errors:
                username_errors = form.errors["username"]
                user_exists_error = "A user with that username already exists." in username_errors
                data = {
                        "error": username_errors,
                        "code": "409",
                        }
                return (JsonResponse(data))
            else:
                error_message = form.errors.as_json()
                data = {
                        "error_message": error_message,
                        "code": "422",
                        }
                return (JsonResponse(data))
    return (render(request, "user/register.html", {
        "form": form
        }))

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
