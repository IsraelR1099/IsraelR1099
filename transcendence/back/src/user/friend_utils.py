# Description: This file contains utility functions for the friend app.
from .models import Users, FriendRequest


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
