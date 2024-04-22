# Description: This file contains utility functions for the friend app.
from django.conf import settings

from .models import Users, FriendRequest
from .utils import get_image_as_base64

import os


def get_receiver_by_username(username):
    try:
        receiver = Users.objects.get(username=username)
        return receiver
    except Users.DoesNotExist:
        return None


def get_receiver_by_id(user_id):
    try:
        receiver = Users.objects.get(pk=user_id)
        return receiver
    except Users.DoesNotExist:
        return None


def validate_sender_receiver(sender, receiver):
    if sender == receiver:
        raise ValueError("Cannot send friend request to yourself.")

    friend_requests = FriendRequest.objects.filter(
            sender=sender, receiver=receiver)
    for request in friend_requests:
        if request.is_active:
            raise ValueError("You already sent them a friend request.")


def create_friend_request(sender, receiver):
    friend_request = FriendRequest(sender=sender, receiver=receiver)
    friend_request.save()


def serialize_friend_request(request):
    sender_username = request.sender.username
    receiver_username = request.receiver.username
    sender_profile_image = ""

    if request.sender.profile_image:
        image_path = os.path.join(
                settings.MEDIA_ROOT, str(request.sender.profile_image))
        encoded_string = get_image_as_base64(image_path=image_path)
        if encoded_string:
            sender_profile_image = encoded_string
        else:
            sender_profile_image = ""
    else:
        sender_profile_image = ""

    return ({
        "pk": request.pk,
        "sender": sender_username,
        "receiver": receiver_username,
        "sender_profile_image": sender_profile_image,
        "is_active": request.is_active
    })
