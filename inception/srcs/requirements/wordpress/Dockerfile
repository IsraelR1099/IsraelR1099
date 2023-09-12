##syntax=docker/dockerfile:1
#FROM debian:buster
#
## Install necessary packages
#RUN apt-get update && apt-get install -y \
#	php7.3-fpm \
#	php7.3-mysqli \
#	mariadb-client \
#	wget \
#	&& rm -rf /var/lib/apt/lists/*
#
## Download Wordpress and move it to the html folder
#RUN wget https://wordpress.org/wordpress-6.3.tar.gz -P /var/www \
#	&& cd /var/www \
#	&& tar -xzf wordpress-6.3.tar.gz \
#	&& rm wordpress-6.3.tar.gz
#
## Copy the configuration files
#COPY ./conf/www.conf /etc/php/7.3/fpm/pool.d/
#
#RUN chown -R www-data:www-data /var/www/wordpress
#
## Install wp-cli
#RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
#	&& chmod +x wp-cli.phar \
#	&& mv wp-cli.phar /usr/local/bin/wp
#
#COPY ./conf/wp-config.sh /usr/local/bin/wp-config.sh
#RUN chmod +x /usr/local/bin/wp-config.sh
#
#EXPOSE 9000
#
#WORKDIR /var/www/wordpress
#
#ENTRYPOINT ["/usr/local/bin/wp-config.sh"]

FROM debian:buster

RUN apt-get update && apt-get -y install \
	curl \
	php7.3-fpm \
	php7.3-mysqli \
	mariadb-client

RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
	&& chmod +x wp-cli.phar \
	&& mv wp-cli.phar /usr/local/bin/wp

COPY conf/www.conf /etc/php/7.3/fpm/pool.d/

RUN mkdir -p /run/php
RUN chmod 755 /run/php

COPY ./conf/wp-config.sh /usr/local/bin/wp-config.sh
RUN chmod +x /usr/local/bin/wp-config.sh

EXPOSE 9000

WORKDIR /var/www/html/

ENTRYPOINT [ "/usr/local/bin/wp-config.sh" ]
