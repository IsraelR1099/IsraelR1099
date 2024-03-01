from django.urls import path
from django.contrib.auth import views as auth_views
from rest_framework_simplejwt import views as jwt_views
from . import views

urlpatterns = [
        path("", views.index, name="index"),
        path("account/<int:user_id>/", views.account_view, name="view"),
        path("account/<int:user_id>/edit/", views.edit_account_view, name="edit"),
        path("friend_list/<int:user_id>/", views.friend_list_view, name="friend-list"),
        path("friend_remove/", views.remove_friend, name="remove-friend"),
        path("friend_request/", views.send_friend_request, name="friend-request"),
        path("friend_request/<int:user_id>/", views.friend_requests, name="friend-requests"),
        path("get_is_auth/", views.get_is_auth, name="get-is-auth"),
        path("accept_friend_request/<int:friend_request_id>/",
             views.accept_friend_request, name="accept-friend-request"),
        path("decline_friend_request/<int:friend_request_id>/",
             views.decline_friend_request, name="decline-friend-request"),
        path("get_csrf_token/", views.get_csrf_token, name="get-csrf-token"),
        path("login/", views.login_view, name="login"),
        path("logout/", views.logout_view, name="logout"),
        path("register/", views.register_user, name="register"),
        path("search/", views.account_search_view, name="search"),
        path("token/", jwt_views.TokenObtainPairView.as_view(), name="token_obtain_pair"),
        path("token/refresh/", jwt_views.TokenRefreshView.as_view(), name="token_refresh"),


        path('password_change/done/', auth_views.PasswordChangeDoneView.as_view(template_name='password_reset/password_change_done.html'),
        name='password_change_done'),

        path('password_change/', auth_views.PasswordChangeView.as_view(template_name='password_reset/password_change.html'),
        name='password_change'),

        path('password_reset/done/', auth_views.PasswordResetCompleteView.as_view(template_name='password_reset/password_reset_done.html'),
     name='password_reset_done'),

        path('reset/<uidb64>/<token>/', auth_views.PasswordResetConfirmView.as_view(
            template_name='password_reset/password_reset_confirm.html'
            ), name='password_reset_confirm'),
        path('password_reset/', auth_views.PasswordResetView.as_view(template_name='password_reset/password_reset_form.html', html_email_template_name='password_reset/password_reset_email.html', email_template_name='password_reset/password_reset_email.html'), name='password_reset'),
        path('reset/done/', auth_views.PasswordResetCompleteView.as_view(template_name='password_reset/password_reset_complete.html'),
     name='password_reset_complete'),
        path("<int:user_id>/accept_friend_request/", views.accept_friend_request, name="accept_friend_request"),
        ]
