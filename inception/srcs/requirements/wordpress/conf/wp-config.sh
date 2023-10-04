#!/bin/bash

 #First we check if the wp-config.php file exists
 #If it does not exist, we create it
 #If it does exist, we do nothing
 #wp config create: this command creates the wp-config.php file
 #wp core install: this command installs WordPress
 #wp user create: this command creates a new user

if [ -f ./wp-config.php ]
then
	echo -e "\033[0;31mWordPress is already installed\033[0m"
else
	wp core download --allow-root
	wp config create --allow-root \
		--dbname=$MYSQL_DATABASE \
		--dbuser=$MYSQL_USER \
		--dbpass=$MYSQL_PASSWORD \
		--dbhost=mariadb
	wp core install --url=$DOMAIN_NAME \
		--title="$SITE_TITLE" \
		--admin_user=$ADMIN_USER \
		--admin_password=$ADMIN_PASSWORD \
		--admin_email=$ADMIN_EMAIL \
		--skip-email \
		--allow-root
	wp user create --allow-root \
		$USER_NAME \
		$USER_EMAIL \
		--user_pass=$USER_PASSWORD \
		--role=author
	wp theme install --allow-root \
		--activate \
		neve
	echo -e "\033[0;32mwp-config.php file created\033[0m"
fi

if [ ! -d /run/php ]
then
	echo -e "\033[0;32mCreating /run/php directory\033[0m"
	mkdir -p /run/php
	chmod 755 /run/php
else
	echo -e "\033[0;31m/run/php directory already exists\033[0m"
fi

# We start the php-fpm service in the foreground
/usr/sbin/php-fpm7.3 -F
