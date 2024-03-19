from django import forms
from django.contrib.auth.forms import UserCreationForm
from django.contrib.auth import authenticate
from django.core.files.uploadedfile import InMemoryUploadedFile
from django.core.files.base import ContentFile

import logging
import base64

from .models import Users
from .models import OAuth42Users


class RegistrationForm(UserCreationForm):
    email = forms.EmailField(max_length=64, help_text='Required. Add a valid email address')

    class Meta:
        model = Users
        fields = ("email", "username", "password1", "password2")

    def clean_email(self):
        email = self.cleaned_data['email'].lower()
        try:
            user = Users.objects.get(email=email)
        except Exception as e:
            return (email)
        raise forms.ValidationError(f"Email {email} is already in use.")

    def clean_username(self):
        username = self.cleaned_data['username']
        try:
            user = Users.objects.get(username=username)
        except Exception as e:
            return username
        raise forms.ValidationError(f"Username {username} is already in use.")


class UsersAuthentication42Form(UserCreationForm):
    email = forms.EmailField(max_length=64, help_text='Required. Add a valid email address')

    class Meta:
        model = OAuth42Users
        fields = ("email", "login")

    def clean_email(self):
        email = self.cleaned_data['email'].lower()
        try:
            user = OAuth42Users.objects.get(email=email)
        except Exception as e:
            return (email)
        raise forms.ValidationError(f"Email {email} is already in use.")

    def clean_login(self):
        login = self.cleaned_data['login']
        try:
            user = OAuth42Users.objects.get(login=login)
        except Exception as e:
            return login
        raise forms.ValidationError(f"Login {login} is already in use.")

    def clean(self):
        if self.is_valid():
            login = self.cleaned_data['login']
            if not authenticate(login=login):
                raise forms.ValidationError("Invalid login")


class UsersAuthenticationForm(forms.ModelForm):
    password = forms.CharField(label='Password', widget=forms.PasswordInput)

    class Meta:
        model = Users
        fields = ('username', 'password')

    def clean(self):
        if self.is_valid():
            username = self.cleaned_data['username']
            password = self.cleaned_data['password']
            if not authenticate(username=username, password=password):
                raise forms.ValidationError("Invalid email or password")


class UsersUpdateForm(forms.ModelForm):

    class Meta:
        model = Users
        fields = ('username', 'email', 'profile_image', 'hide_email')

    # def __init__(self, *args, **kwargs):
        # initial = kwargs.get('initial', {})
        # logging.debug("Initial values in init")
        # for field_name, field in self.base_fields.items():
        #    value = initial.get(field_name)
        #    logging.debug(f"{field_name}: {value}")
        # super().__init__(*args, **kwargs)

    def clean_email(self):
        email = self.cleaned_data['email'].lower()
        logging.debug(f"email in form: {email}")
        try:
            user = Users.objects.get(email=email)
        except Users.DoesNotExist:
            return email
        raise forms.ValidationError(f"Email {email} is already in use.")

    def clean_username(self):
        username = self.cleaned_data['username']
        logging.debug(f"username in form: {username}")
        try:
            user = Users.objects.get(username=username)
        except Users.DoesNotExist:
            return username
        raise forms.ValidationError(f"Username {username} is already in use.")

    def save(self, commit=True):
        user = super(UsersUpdateForm, self).save(commit=False)
        user.username = self.cleaned_data['username']
        user.email = self.cleaned_data['email']
        user.hide_email = self.cleaned_data['hide_email']
        user.profile_image = self.cleaned_data['profile_image']
        logging.debug(f"Profile image: {self.cleaned_data['profile_image']}")
        if commit:
            user.save()
        return (user)
