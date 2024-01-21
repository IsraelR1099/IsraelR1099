FROM nginx:1.25-alpine

RUN apk update && apk add --no-cache nginx openssl

RUN mkdir -p -m 777 /etc/nginx/ssl
RUN openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes \
	-out /etc/nginx/ssl/transcendence.crt \
	-keyout /etc/nginx/ssl/transcendence.key \
	-subj "/C=/ST=/L=/O=/OU=/CN=/"

COPY nginx.conf /etc/nginx/conf.d/default.conf
