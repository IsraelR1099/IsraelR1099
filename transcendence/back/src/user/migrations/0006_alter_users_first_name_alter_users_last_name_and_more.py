# Generated by Django 5.0 on 2023-12-30 15:22

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('user', '0005_alter_users_email_alter_users_username'),
    ]

    operations = [
        migrations.AlterField(
            model_name='users',
            name='first_name',
            field=models.CharField(max_length=61),
        ),
        migrations.AlterField(
            model_name='users',
            name='last_name',
            field=models.CharField(max_length=62),
        ),
        migrations.AlterField(
            model_name='users',
            name='password',
            field=models.CharField(max_length=65),
        ),
        migrations.AlterField(
            model_name='users',
            name='username',
            field=models.CharField(max_length=63, unique=True),
        ),
    ]
