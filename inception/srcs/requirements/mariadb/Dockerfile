# syntax=docker/dockerfile:1
FROM debian:buster

# Install MariaDB
# the command apt-get update is used to update the package cache
# It is important to use apt-get update and install in the same RUN command
# the command rm -rf /var/lib/apt/lists/* is used to clean up the package cache
RUN apt-get update && apt-get install -y \
	mariadb-server && \
	rm -rf /var/lib/apt/lists/*

COPY ./conf/mariadb.conf /etc/mysql/mariadb.conf/mariadb.conf

RUN mkdir -p /var/run/mysqld \
	&& chown -R mysql:mysql /var/run/mysqld \
	&& chmod 777 /var/run/mysqld

EXPOSE 3306

ENV MYSQL_ROOT_PASSWORD=root
ENV MYSQL_DATABASE=wordpress
ENV MYSQL_USER=wordpress
ENV MYSQL_PASSWORD=wordpress
ENV WP_USER=wordpress
ENV WP_PASSWORD=wordpress
# Copy the database initialization script
# the directory /usr/local/bin is used to store user scripts
COPY ./tools/mariadb.sh /usr/local/bin/mariadb.sh

# Make the script executable
RUN chmod +x /usr/local/bin/mariadb.sh
RUN mysql_install_db

ENTRYPOINT [ "/usr/local/bin/mariadb.sh" ]

CMD [ "mysqld", "--bind-address=0.0.0.0" ]
