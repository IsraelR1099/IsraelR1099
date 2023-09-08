#syntax=docker/dockerfile:1
FROM debian:buster

# Install necessary packages
RUN apt-get update && apt-get install -y \
	php7.3 \
	php7.3-fpm \
	php7.3-mysql \
	curl \
	&& rm -rf /var/lib/apt/lists/*

# Set up Wordpress configuration
RUN curl -O https://wordpress.org/latest.tar.gz \
	&& tar xf latest.tar.gz \
	&& rm latest.tar.gz \
	&& mv wordpress/* /var/www/html

EXPOSE 9000
CMD ["php-fpm7.3", "--nodaemonize"]
