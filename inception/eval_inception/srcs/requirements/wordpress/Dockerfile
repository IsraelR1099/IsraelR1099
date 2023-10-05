#syntax=docker/dockerfile:1
FROM debian:buster

# Install necessary packages
RUN apt-get update && \
	apt-get -y install \
	php7.3-fpm \
	php7.3-mysqli \
	mariadb-client \
	curl \
	&& rm -rf /var/lib/apt/lists/*

# Install wp-cli
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
	&& chmod +x wp-cli.phar \
	&& mv wp-cli.phar /usr/local/bin/wp

COPY ./conf/www.conf /etc/php/7.3/fpm/pool.d/

COPY ./tools/wp-config.sh /usr/local/bin/wp-config.sh
RUN chmod +x /usr/local/bin/wp-config.sh

EXPOSE 9000

WORKDIR /var/www/html

ENTRYPOINT ["bash" , "/usr/local/bin/wp-config.sh"]
