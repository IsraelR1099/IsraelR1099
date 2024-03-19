RED = \033[1;31m
GREEN = \033[1;32m
RESET = \033[0m

all: reset_migrations create_certificates
	@echo "$(GREEN)Starting server...$(RESET)"
	@sleep 1
	@docker compose -f compose.yaml up -d --build

reset_migrations:
	@if ! grep -q '^RESET_MIGRATIONS=false' .env; then \
		read -p "Do you want to reset migrations? [yes/no]: " reset_migrations; \
			if [ $$reset_migrations = "yes" ]; then \
				sed -i 's/RESET_MIGRATIONS=.*/RESET_MIGRATIONS=true/' .env; \
			else \
				echo "$(RED)Skipping migrations...$(RESET)"; \
				sed -i 's/RESET_MIGRATIONS=.*/RESET_MIGRATIONS=false/' .env; \
			fi \
	else \
		echo "$(RED)Migrations already reset, skippping...$(RESET)"; \
		sed -i 's/RESET_MIGRATIONS=.*/RESET_MIGRATIONS=false/' .env; \
	fi

create_certificates:
	chmod +x create_certificates.sh
	@bash create_certificates.sh

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

.PHONY: all stop clean fclean re create_certificates
