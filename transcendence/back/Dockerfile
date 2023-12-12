FROM python:3.12-alpine

WORKDIR /srv

COPY requirements.txt .

RUN apk update && \
    apk add --no-cache vim && \
    pip install -r requirements.txt

COPY src /srv

CMD ["python", "manage.py", "runserver", "0.0.0.0:8000"]
