from django.conf import settings

import base64
import logging
import os

from .models import FriendRequest


def get_friend_request_or_false(sender, receiver):
    try:
        return FriendRequest.objects.get(
                sender=sender, receiver=receiver, is_active=True)
    except FriendRequest.DoesNotExist:
        return False


def generate_response(status, user=None, error_message=None, tokens=None):
    response = {}

    # Login
    if status == "200":
        if user:
            response["code"] = status
            response["id"] = user.id
            response["username"] = user.username
            response["email"] = user.email
            response["status"] = "online"

            if tokens:
                access_token = tokens.get("access", "")
                refresh_token = tokens.get("refresh", "")

                # Access token info
                if access_token:
                    response["token_access"] = access_token

                # Refresh token info
                if refresh_token:
                    response["token_refresh"] = refresh_token

    # Register
    elif status == "201":
        if user:
            response["code"] = status
            response["id"] = user.id
            response["username"] = user.username
            response["email"] = user.email
            response["status"] = "online"
            response["created_at"] = user.created_date_time.isoformat()

            if tokens:
                access_token = tokens.get("access", "")
                refresh_token = tokens.get("refresh", "")

                # Access token info
                if access_token:
                    response["token_access"] = access_token

                # Refresh token info
                if refresh_token:
                    response["token_refresh"] = refresh_token

    elif status == "401":
        if error_message:
            response["code"] = status
            response["error"] = error_message
    return (response)


def get_image_as_base64(image_path):
    """
    Convert the image at the given path to Base64
    """
    try:
        with open(image_path, "rb") as img_file:
            enconded_string = base64.b64encode(img_file.read()).decode("utf-8")
        return (enconded_string)
    except FileNotFoundError:
        logging.debug(f"File not found: {image_path}")
        return (None)


def process_profile_image(profile_image_data):
    decoded_image_data = base64.b64decode(profile_image_data)
    return (decoded_image_data)


def save_image_to_folder(image_data, user_id):
    folder_path = f"media_cdn/profile_images/{user_id}"
    os.makedirs(folder_path, exist_ok=True)
    image_path = f"{folder_path}/profile_image.png"

    with open(image_path, "wb") as f:
        f.write(image_data)

    return (image_path)


def serialize_friend_request(request):
    sender_username = request.sender.username
    receiver_username = request.receiver.username
    sender_profile_image = ""

    if request.sender.profile_image:
        image_path = os.path.join(
                settings.MEDIA_ROOT, str(request.sender.profile_image))
        enconded_string = get_image_as_base64(image_path)
        if enconded_string:
            sender_profile_image = enconded_string

    return ({
        "pk": request.pk,
        "sender": sender_username,
        "receiver": receiver_username,
        "sender_profile_image": sender_profile_image,
        "is_active": request.is_active,
        })
