RED = \033[1;31m
GREEN = \033[1;32m
RESET = \033[0m

all:
	@echo "$(GREEN)Starting server...$(RESET)"
	@sleep 1
	@docker compose -f compose.yaml up -d --build

stop:
	@echo "$(RED)Stopping server...$(RESET)"
	@docker compose -f compose.yaml stop

clean:
	@echo "$(RED)Stop and remove containers $(RESET)"
	docker compose -f compose.yaml down -v

remove-images:
	@echo "$(RED)Removing images...$(RESET)"
	@docker rmi -f $$(docker images -q)

remove-containers:
	@echo "$(RED)Removing containers...$(RESET)"
	@docker container prune -f

remove-all: remove-containers remove-images
	@echo "$(RED)Removing all...$(RESET)"

fclean:
	@echo "$(RED)Removing server...$(RESET)"
	@docker system prune -af

re: fclean all

.PHONY: all stop clean fclean re
