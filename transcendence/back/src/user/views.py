from django.shortcuts import render
from django.http import HttpResponseRedirect, HttpRequest, JsonResponse
from django.urls import reverse
from django.contrib.auth import authenticate, login, logout
from django.contrib.auth.forms import UserCreationForm
from django.views.decorators.csrf import csrf_exempt

# Create your views here.

@csrf_exempt
def index(request):
    if not request.user.is_authenticated:
        return (HttpResponseRedirect(reverse("login")))
    return (render(request, "user/user.html"))

@csrf_exempt
def login_view(request: HttpRequest) -> JsonResponse:
    if request.method == "POST":
        username = request.POST["username"]
        password = request.POST["password"]
        # authenticate user
        user = authenticate(request, username=username, password=password)
        # check if authentication successful
        if user is not None:
            login(request, user)
            data = {
                "message": "Login successful.",
                "status": "success",
                "username": username,
                "password": password,
                    }
            return (JsonResponse(data))
        else:
            data = {
                "message": "Invalid username and/or password.",
                "status": "error",
                "username": username,
                "password": password,
                }
            return (JsonResponse(data))
    return (render(request, "user/login.html"))

@csrf_exempt
def logout_view(request: HttpRequest) -> JsonResponse:
    logout(request)
    data = {
        "message": "Logout successful.",
        "status": "success",
            }
    return (JsonResponse(data))

def register_user(request: HttpRequest) -> JsonResponse:
    form = UserCreationForm()
    if request.method == "POST":
        form = UserCreationForm(request.POST)
        if form.is_valid():
            form.save()
            username = form.cleaned_data.get("username")
            password = form.cleaned_data.get("password1")
            # authenticate user
            user = authenticate(request, username=username, password=password)
            login(request, user)
            data = {
                "message": "Registration successful.",
                "status": "success",
                    }
            return (JsonResponse(data))
        else:
            error_message = form.errors.as_json()
            data = {
                    "message": "Registration failed.",
                    "status": "error",
                    "error_message": error_message,
                    }
            return (JsonResponse(data))
    return (render(request, "user/register.html", {
        "form": form
        }))
