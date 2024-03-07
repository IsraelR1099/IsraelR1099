"""
Django settings for transcendance project.

Generated by 'django-admin startproject' using Django 5.0.

For more information on this file, see
https://docs.djangoproject.com/en/5.0/topics/settings/

For the full list of settings and their values, see
https://docs.djangoproject.com/en/5.0/ref/settings/
"""

import os
from datetime import timedelta

# Build paths inside the project like this: BASE_DIR / 'subdir'.
BASE_DIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


# Quick-start development settings - unsuitable for production
# See https://docs.djangoproject.com/en/5.0/howto/deployment/checklist/

# SECURITY  WARNING: keep the secret key used in production secret!
SECRET_KEY = 'django-insecure-^3mwpr*&go6+nh@jv-dtx)egg^ijuj*$8)4ry_&_3k)qxd61cx'

# SECURITY WARNING: don't run with debug turned on in production!
DEBUG = True

if DEBUG:
    EMAIL_BACKEND = 'django.core.mail.backends.console.EmailBackend' # During development only


AUTH_USER_MODEL = 'user.Users'
AUTHENTICATION_BACKENDS = [
        'django.contrib.auth.backends.AllowAllUsersModelBackend',
        'django.contrib.auth.backends.ModelBackend',
        'allauth.account.auth_backends.AuthenticationBackend',
        ]

ALLOWED_HOSTS = ["*"]

LOGIN_REDIRECT_URL = '/api/accounts/google/login/?process=login'
LOGOUT_REDIRECT_URL = '/api/accounts/google/logout/?process=logout'


# Application definition

SITE_ID = 1

INSTALLED_APPS = [
    "django.contrib.auth",
    "django.contrib.contenttypes",
    "django.contrib.sessions",
    "django.contrib.messages",
    "django.contrib.staticfiles",
    "rest_framework_simplejwt.token_blacklist",
    "user",
    "django.contrib.sites",
    "allauth",
    "allauth.account",
    "allauth.socialaccount",
    "allauth.socialaccount.providers.google",
]

CLIENT_ID = os.environ.get("CLIENT_ID")
CLIENT_SECRET = os.environ.get("CLIENT_SECRET")

SOCIALACCOUNT_PROVIDERS = {
        'google': {
            'APP': {
                'client_id': 'CLIENT_ID',
                'secret': 'CLIENT_SECRET',
                'key': '',
                },
            'SCOPE': [
                'profile',
                'email',
                ],
            'AUTH_PARAMS': {
                'access_type': 'online',
                },
            }
        }

MIDDLEWARE = [
    'django.middleware.security.SecurityMiddleware',
    'django.contrib.sessions.middleware.SessionMiddleware',
    'django.middleware.common.CommonMiddleware',
    'django.middleware.csrf.CsrfViewMiddleware',
    'django.contrib.auth.middleware.AuthenticationMiddleware',
    'django.contrib.messages.middleware.MessageMiddleware',
    'django.middleware.clickjacking.XFrameOptionsMiddleware',
    'allauth.account.middleware.AccountMiddleware',
]

ROOT_URLCONF = 'transcendance.urls'

TEMPLATES = [
    {
        'BACKEND': 'django.template.backends.django.DjangoTemplates',
        'DIRS': [os.path.join(BASE_DIR, 'templates'),
                 os.path.join(BASE_DIR, 'user', 'templates'),],
        'APP_DIRS': True,
        'OPTIONS': {
            'context_processors': [
                'django.template.context_processors.debug',
                'django.template.context_processors.request',
                'django.contrib.auth.context_processors.auth',
                'django.contrib.messages.context_processors.messages',
            ],
        },
    },
]

WSGI_APPLICATION = "transcendance.wsgi.application"
ASGI_APPLICATION = "transcendance.routing.application"


# Database
# https://docs.djangoproject.com/en/5.0/ref/settings/#databases

DATABASES = {
    "default": {
        "ENGINE": "django.db.backends.postgresql",
        "NAME": os.environ.get("POSTGRES_DB"),
        "USER": os.environ.get("POSTGRES_USER"),
        "PASSWORD": os.environ.get("POSTGRES_PASSWORD"),
        "HOST": os.environ.get("POSTGRES_HOST"),
        "PORT": 5432,
    }
}

LOGGING = {
        'version': 1,
        'disable_existing_loggers': False,
        'handlers': {
            'console': {
                'class': 'logging.StreamHandler',
                },
            },
        'root': {
            'handlers': ['console'],
            'level': 'DEBUG',
            },
}

REST_FRAMEWORK = {
        'DEFAULT_AUTHENTICATION_CLASSES': [
            'rest_framework_simplejwt.authentication.JWTAuthentication',
            ],
        }

SIMPLE_JWT = {
        'ACCESS_TOKEN_LIFETIME': timedelta(hours=2),
        'REFRESH_TOKEN_LIFETIME': timedelta(days=1),
        'SIGNING_KEY': SECRET_KEY,
        'AUTH_HEADER_TYPES': ('Bearer',),
        }

# Password validation
# https://docs.djangoproject.com/en/5.0/ref/settings/#auth-password-validators

AUTH_PASSWORD_VALIDATORS = [
    {
        'NAME': 'django.contrib.auth.password_validation.UserAttributeSimilarityValidator',
    },
    {
        'NAME': 'django.contrib.auth.password_validation.MinimumLengthValidator',
    },
    {
        'NAME': 'django.contrib.auth.password_validation.CommonPasswordValidator',
    },
    {
        'NAME': 'django.contrib.auth.password_validation.NumericPasswordValidator',
    },
]


# Internationalization
# https://docs.djangoproject.com/en/5.0/topics/i18n/

LANGUAGE_CODE = 'en-us'

TIME_ZONE = 'UTC'

USE_I18N = True

USE_TZ = True

# Set SESSION_EXPIRE_AT_BROWSER_CLOSE to true
SESSION_EXPIRE_AT_BROWSER_CLOSE = True


# Static files (CSS, JavaScript, Images)
# https://docs.djangoproject.com/en/5.0/howto/static-files/

STATICFILES_DIRS = [
        os.path.join(BASE_DIR, 'static'),
        os.path.join(BASE_DIR, 'media'),
        ]
STATIC_URL = '/static/'
MEDIA_URL = '/media/'

# Default primary key field type
# https://docs.djangoproject.com/en/5.0/ref/settings/#default-auto-field

DEFAULT_AUTO_FIELD = 'django.db.models.BigAutoField'

# CSRF settings
CSRF_TRUSTED_ORIGINS = ['http://localhost:8080', 'https://localhost:8080',
                        'http://127.0.0.1:8080', 'https://127.0.0.1:8080']

# Media settings
STATIC_ROOT     = os.path.join(BASE_DIR, 'static_cdn')
MEDIA_ROOT      = os.path.join(BASE_DIR, 'media_cdn')

TEMP            = os.path.join(BASE_DIR, 'media_cdn/temp')
BASE_URL        = "https://127.0.0.1:8080"

DATA_UPLOAD_MAX_MEMORY_SIZE = 10485760  # 10MB

