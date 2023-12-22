from django.shortcuts import render
from django.http import HttpResponseRedirect, HttpRequest, JsonResponse
from django.urls import reverse
from django.contrib.auth import authenticate, login, logout
from django.contrib.auth.forms import UserCreationForm
from django.views.decorators.csrf import csrf_exempt
from django.contrib.auth.decorators import login_required

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
