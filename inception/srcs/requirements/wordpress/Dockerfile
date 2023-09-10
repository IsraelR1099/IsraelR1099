#syntax=docker/dockerfile:1
FROM debian:buster

# Install necessary packages
RUN apt-get update && apt-get install -y \
	php7.3-fpm \
	php7.3-mysqli \
	mariadb-client \
	wget \
	&& rm -rf /var/lib/apt/lists/*

ENV SQL_DB_NAME=wordpress
ENV SQL_USER=wordpress
ENV SQL_DB_PASSWORD=wordpress
ENV DOMAIN_NAME=irifarac.42.fr
ENV SITE_TITLE=irifarac
ENV ADMIN_USER=admin
ENV ADMIN_PASSWORD=admin
ENV ADMIN_EMAIL=admin@gmail.com
ENV USER_NAME=irifarac
ENV USER_PASSWORD=irifarac
ENV USER_EMAIL=irifarac@gmail.com

# Download Wordpress and move it to the html folder
RUN wget https://wordpress.org/wordpress-6.3.tar.gz -P /var/www \
	&& cd /var/www \
	&& tar -xzf wordpress-6.3.tar.gz \
	&& rm wordpress-6.3.tar.gz

# Copy the configuration files
COPY ./conf/www.conf /etc/php/7.3/fpm/pool.d/

RUN chown -R www-data:www-data /var/www/wordpress

# Install wp-cli
RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
	&& chmod +x wp-cli.phar \
	&& mv wp-cli.phar /usr/local/bin/wp

COPY ./conf/wp-config.sh /usr/local/bin/wp-config.sh
RUN chmod +x /usr/local/bin/wp-config.sh

EXPOSE 9000

ENTRYPOINT ["/usr/local/bin/wp-config.sh"]
