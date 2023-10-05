
PATH_YML = ./srcs/docker-compose.yml
RED = \033[1;31m
GREEN = \033[1;32m
RESET = \033[0m

ifneq (, $(wildcard srcs/requirements/tools/path.txt))
	dir_path := srcs/requirements/tools/path.txt
	variable := $(shell cat ${dir_path})
	wordpress_dir := $(shell echo ${variable}/wordpress)
	mariadb_dir := $(shell echo ${variable}/mariadb)
endif

all:
ifeq (,$(wildcard ./srcs/requirements/tools/path.txt))
	@bash ./srcs/requirements/tools/set.sh
	@echo "$(GREEN)Everything is set up!$(RESET)"
	@echo "Please run make to start the server"
else
ifeq (,$(wildcard $(mariadb_dir)))
	@sudo mkdir -p $(mariadb_dir)
	@sudo mkdir -p $(wordpress_dir)
	@sudo chmod 777 $(mariadb_dir)
	@sudo chmod 777 $(wordpress_dir)
endif
	@echo "$(GREEN)Starting the server...$(RESET)"
	@sleep 1
	@sudo docker compose -f $(PATH_YML) up -d --build
endif

stop:
	@echo "$(RED)Stopping the server...$(RESET)"
	@sudo docker compose -f $(PATH_YML) stop

clean:
	@echo "$(RED)Removing the server...$(RESET)"
	@sudo docker compose -f $(PATH_YML) down -v

fclean:
	@echo "$(RED)Removing the server...$(RESET)"
	@sudo rm -rf $(mariadb_dir)
	@sudo rm -rf $(wordpress_dir)
	@sudo rm ./srcs/requirements/tools/path.txt
	@sudo docker system prune -af

re: fclean all

reset: clean
	@echo "$(GREEN)Resetting the server...$(RESET)"
	@rm ./srcs/requirements/tools/path.txt
	@printf "\nPath has been reset\n"

.PHONY: all stop clean fclean reset re
