# syntax=docker/dockerfile:1
FROM debian:buster

# Install MariaDB
# the command apt-get update is used to update the package cache
# It is important to use apt-get update and install in the same RUN command
# the command rm -rf /var/lib/apt/lists/* is used to clean up the package cache
RUN apt-get update && apt-get install -y \
	mariadb-server && \
	rm -rf /var/lib/apt/lists/*

# Copy the database initialization script
# the directory /usr/local/bin is used to store user scripts
COPY ./tools/mariadb.sh /usr/local/bin/mariadb.sh

# Make the script executable
RUN chmod +x /usr/local/bin/mariadb.sh
