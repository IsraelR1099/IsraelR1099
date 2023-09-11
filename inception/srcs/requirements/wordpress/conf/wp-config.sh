#!/bin/sh

# First we check if the wp-config.php file exists
# If it does not exist, we create it
# If it does exist, we do nothing
# wp config create: this command creates the wp-config.php file
# wp core install: this command installs WordPress
# wp user create: this command creates a new user

sleep 10

if [ ! -f ./wp-config.php ]
then
	wp config create --allow-root \
		--dbname=${SQL_DB_NAME} \
		--dbuser=${SQL_DB_USER} \
		--dbpass=${SQL_DB_PASSWORD} \
		--dbhost=mariadb:3306 \
		--path='/var/www/wordpress'
	sleep 2
	wp core install --url=$DOMAIN_NAME \
		--title=$SITE_TITLE \
		--admin_user=$ADMIN_USER \
		--admin_password=$ADMIN_PASSWORD \
		--admin_email=$ADMIN_EMAIL \
		--allow-root \
		--path='/var/www/wordpress'
	wp user create --allow-root \
		$USER_NAME \
		$USER_EMAIL \
		--user_pass=$USER_PASSWORD \
		--role=author \
		--path='/var/www/wordpress'
fi

if [ ! -d /run/php ]
then
	mkdir -p /run/php
	chmod 755 /run/php
fi

# We start the php-fpm service in the foreground
/usr/sbin/php-fpm7.3 -F
