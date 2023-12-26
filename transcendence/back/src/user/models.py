from django.db import models
from django.utils import timezone
from django.conf import settings

# Create your models here.

class   Users(models.Model):
    first_name = models.CharField(max_length=64)
    last_name = models.CharField(max_length=64)
    birth_date = models.DateField(default = timezone.now)
    username = models.CharField(max_length=64)
    password = models.CharField(max_length=64)
    created_date_time = models.DateField(default = timezone.now)
    friends = models.ManyToManyField("Users", blank=True)

    def __str__(self):
        return (f"{self.id}: {self.username}")

class FriendList(models.Model):
    user = models.OneToOneField(
            settings.AUTH_USER_MODEL, on_delete=models.CASCADE, related_name="user")
    friends = models.ManyToManyField(
            settings.AUTH_USER_MODEL, blank=True, related_name="friends")
    def __str__(self):
        return (f"{self.user.username}")
    def add_friend(self, account):
        """
        Add a new friend.
        """
        if not account in self.friends.all():
            self.friends.add(account)

    def remove_friend(self, account):
        """
        Remove a friend.
        """
        if account in self.friends.all():
            self.friends.remove(account)

    def unfriend(self, removee):
        """
        Initiate the action of unfriending someone.
        """
        remover_friends_list = self # person terminating the friendship
        # Remove friend from remover friend list
        remover_friends_list.remove_friend(removee)
        # Remove friend from removee friend list
        friends_list = FriendList.objects.get(user=removee)
        friends_list.remove_friend(self.user)

    def is_mutual_friend(self, friend):
        """
        Is this a friend?
        """
        if friend in self.friends.all():
            return (True)
        return (False)

class FriendRequest(models.Model):
    """
    1. Sender
    -- The person sending the friend request
    2. Receiver
    -- The person receiving the friend request
    """
    sender = models.ForeignKey(
            settings.AUTH_USER_MODEL, on_delete=models.CASCADE, related_name="sender")
    receiver = models.ForeignKey(
            settings.AUTH_USER_MODEL, on_delete=models.CASCADE, related_name="receiver")
    is_active = models.BooleanField(blank=True, null=False, default=True)
    timestamp = models.DateTimeField(auto_now_add=True)

    def __str__(self):
        return (f"{self.sender.username}")

    def accept(self):
        """
        Accept a friend request.
        Update both SENDER and RECEIVER friend lists.
        """
        receiver_friend_list = FriendList.objects.get(user=self.receiver)
        if receiver_friend_list:
            receiver_friend_list.add_friend(self.sender)
            sender_friend_list = FriendList.objects.get(user=self.sender)
            if sender_friend_list:
                sender_friend_list.add_friend(self.receiver)
                self.is_active = False
                self.save()
    def decline(self):
        """
        Decline a friend request.
        It is "declined" by setting is_active to False.
        """
        self.is_active = False
        self.save()

    def cancel(self):
        """
        Cancel a friend request.
        This is when the sender decides to cancel their friend request.
        This is only different with respect to "declining" through notification
        is generated.
        """
        self.is_active = False
        self.save()

