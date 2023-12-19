FROM python:3.12-alpine

WORKDIR /srv

COPY requirements.txt .

RUN apk update && \
    apk add --no-cache vim && \
    apk add --no-cache netcat-openbsd && \
    pip install -r requirements.txt

COPY src /srv
COPY ./tools/entrypoint.sh /usr/local/bin/entrypoint.sh

RUN chmod +x /usr/local/bin/entrypoint.sh

ENTRYPOINT ["/bin/sh", "/usr/local/bin/entrypoint.sh"]
