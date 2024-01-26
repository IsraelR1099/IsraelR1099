#!/bin/sh

exec "$@"
# Check if the database is using PostgreSQL
if [ "$DBASE" = "postgreSQL" ]
then
    # Wait for the database to be ready
    # This is necessary because the database container may not be ready to accept connections when the web container starts
    echo "Waiting for the database to be ready..."
	/usr/local/bin/wait-for-it.sh $POSTGRES_HOST:$POSTGRES_PORT -t 0
    echo "Database ready"
fi

# Apply database migrations
python manage.py makemigrations
python manage.py migrate

# Run the server
python manage.py runserver 0.0.0.0:8000 2>&1

exec "$@"
