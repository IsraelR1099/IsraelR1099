from django.db import models

# Create your models here.

class   Users(models.Model):
    first_name = models.CharField(max_length=64)
    last_name = models.CharField(max_length=64)
    birth_date = models.DateField()
    username = models.CharField(max_length=64)
    password = models.CharField(max_length=64)
    created_date_time = models.DateField()

    def __str__(self):
        return (f"{self.id}: {self.username}")

class   Friendship_Request(models.Model):
    requester_id = models.ForeignKey(
            Users, on_delete=models.CASCADE, related_name="requester_id")
    addressee_id = models.ForeignKey(
            Users, on_delete=models.CASCADE, related_name="addressee_id")
    created_date_time = models.DateField()

    def __str__(self):
        return (f"user id requester: {self.requester_id} to {self.addressee_id}")
