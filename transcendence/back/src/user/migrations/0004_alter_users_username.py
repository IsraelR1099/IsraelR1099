# Generated by Django 5.0 on 2023-12-30 15:16

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('user', '0003_alter_users_profile_image'),
    ]

    operations = [
        migrations.AlterField(
            model_name='users',
            name='username',
            field=models.CharField(max_length=100, unique=True),
        ),
    ]
