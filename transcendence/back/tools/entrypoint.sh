#!/bin/sh

# Check if the database is using PostgreSQL
if [ "$DBASE" = "postgreSQL" ]
then
    # Wait for the database to be ready
    # This is necessary because the database container may not be ready to accept connections when the web container starts
    echo "Waiting for the database to be ready..."
    while ! nc -z $POSTGRES_HOST $POSTGRES_PORT;
    do
        sleep 0.1;
    done;
    echo "Database ready"
fi

# Apply database migrations
python manage.py makemigrations
python manage.py migrate

# Create superuser
DJANGO_SUPERUSER_PASSWORD=$DJANGO_SUPERUSER_PASSWORD python manage.py \
    createsuperuser --no-input \
    --username $DJANGO_SUPERUSER_USERNAME \
    --email $DJANGO_SUPERUSER_EMAIL

# Run the server
python manage.py runserver 0.0.0.0:8000 2>&1

exec "$@"
