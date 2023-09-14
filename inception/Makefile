all:
	@mkdir -p ./srcs/app
	docker compose -f ./srcs/docker-compose.yml up -d --build
down:
	docker compose -f ./srcs/docker-compose.yml down
clean:
	rm -rf ./srcs/app
	docker rm $(docker ps -a -q)
	docker rmi $(docker images -a -q)
	docker volume rm $(docker volume ls -q)
	docker network rm $(docker network ls -q)

.PHONY: all down clean
