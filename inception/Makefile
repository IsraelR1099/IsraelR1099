all:
	docker compose ./srcs/docker-compose.yml up -d --build
down:
	docker compose ./srcs/docker-compose.yml down
clean:
	docker rm -f $(docker ps -a -q)
	docker rmi -f $(docker images -a -q)
	docker volume rm $(docker volume ls -q)
	docker network rm $(docker network ls -q)

.PHONY: all down clean
