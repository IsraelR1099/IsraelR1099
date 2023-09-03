#syntax=docker/dockerfile:1
FROM debian:buster

# Create directory for SSL certificate
RUN mkdir -p /etc/nginx/ssl

# Install Nginx
# -y: yes to all prompts
RUN apt-get -y update && apt-get -y upgrade \
	&& apt-get -y install nginx openssl

# Generate SSL certificate
# -x509: generate a self-signed certificate
# -nodes: do not encrypt the private key
# -days: number of days the certificate is valid for
# -subj: specify the subject of the certificate
# -newkey: generate a new certificate request and a new private key
# -keyout: specify the filename to write the newly created private key to
# -out: specify the filename to write the newly created certificate to
RUN openssl req -newkey rsa:4096 \
	-x509 \
	-sha256 \
	-days 365 \
	-nodes \
	-out /etc/nginx/ssl/certificate.crt \
	-keyout /etc/nginx/ssl/certificate.key \
	-subj "/C=ES/ST=BARCELONA/L=BARCELONA/O=42/OU=irifarac/CN=irifarac"

# Copy configuration files
COPY ./conf/nginx.conf /etc/nginx/conf.d

# Port to expose
EXPOSE 443

# Running Nginx
# -g: global directives
# daemon off: run in foreground, so that Docker can track the process properly
# (otherwise, Docker will think the process has exited and stop the container)
CMD ["/usr/sbin/nginx", "-g", "daemon off;"]
