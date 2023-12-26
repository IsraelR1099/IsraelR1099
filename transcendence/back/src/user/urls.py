from django.urls import path
from . import views

urlpatterns = [
        path("", views.index, name="index"),
        path("login/", views.login_view, name="login"),
        path("logout/", views.logout_view, name="logout"),
        path("register/", views.register_user, name="register"),
        path("<int:user_id>/send_friend_request/", views.send_friend_request, name="send_friend_request"),
        path("<int:user_id>/accept_friend_request/", views.accept_friend_request, name="accept_friend_request"),
        ]
