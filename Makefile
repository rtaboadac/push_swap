# Colores
GREEN = \033[0;32m
CYAN = \033[0;36m
RED = \033[0;31m
NC = \033[0m

NAME = push_swap
BONUS = checker

INC_DIR = inc/
SRC_DIR = src/
BONUS_DIR = bonus/

SRC_FILES = main.c operations.c operations_combined.c utils.c sort.c
BONUS_FILES = main_bonus.c checker_bonus.c

SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
SRCS_BONUS = $(addprefix $(BONUS_DIR), $(BONUS_FILES))
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

COMPILER = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -I$(INC_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(CYAN)Compiling $(NAME)...$(NC)"
	$(COMPILER) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)$(NAME) compiled successfully! ✅$(NC)"

bonus: $(OBJS_BONUS)
	@echo "$(CYAN)Compiling $(BONUS)...$(NC)"
	$(COMPILER) $(CFLAGS) -o $(BONUS) $(OBJS_BONUS)
	@echo "$(GREEN)$(BONUS) compiled successfully! ✅$(NC)"

clean:
	@echo "$(RED)Cleaning object files... 🧹$(NC)"
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	@echo "$(RED)Removing binaries... 🗑️$(NC)"
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all bonus clean fclean re
