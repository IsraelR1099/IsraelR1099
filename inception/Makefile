
PATH = ./srcs/docker-compose.yml

ifneq (, $(wildcard srcs/requirements/tools/path.txt))
	dir_path := srcs/requirements/tools/path.txt
	variable := $(shell cat $(dir_path))
	wordpress_dir := $(shell echo ${variable}/wordpress)
	mariadb_dir := $(shell echo ${variable}/mariadb)
endif

all:
ifeq (,$(wildcard ./srcs/requirements/tools/path.txt))
	@bash ./srcs/requirements/tools/set.sh
	@echo "Everything is set up!"
	@echo "Please run make to start the server"
else
ifeq (,$(wildcard $(mariadb_dir)))
	@sudo mkdir -p $(mariadb_dir)
	@sudo mkdir -p $(wordpress_dir)
	@sudo chmod 777 $(mariadb_dir)
	@sudo chmod 777 $(wordpress_dir)
endif
	@echo "Starting the server..."
	@sleep 1
	@sudo docker compose -f $(PATH) up -d --build
endif

stop:
	@echo "Stopping the server..."
	@sleep 1
	@sudo docker compose -f $(PATH) stop

clean:
	@echo "Removing the server..."
	@sleep 1
	@sudo docker compose -f $(PATH) down -v

fclean:
	@echo "Removing the server..."
	@sleep 1
	@sudo rm -rf $(mariadb_dir)
	@sudo rm -rf $(wordpress_dir)
	@sudo docker system prune -af

re: fclean all

reset: clean
	@echo "Resetting the server..."
	@rm ./srcs/requirements/tools/path.txt
	@printf "\nPath has been reset\n"

.PHONY: all stop clean fclean reset re
