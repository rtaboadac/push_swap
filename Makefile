
NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = ./src/
INC_DIR = ./includes
LIBFT_DIR = ./lib/libft
FT_PRINTF_DIR = ./lib/ft_printf


SRC_FILES = combined_operations.c check.c operations.c push_swap.c sort_utils.c sort.c stack_helpers.c stack_setter.c stack_utils.c stack.c

SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS = $(SRCS:.c=.o)

LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

INCLUDES = -I$(INC_DIR) -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR)

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF) -o $(NAME)

%.o: %.c $(INC_DIR)/push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	@$(MAKE) -C $(FT_PRINTF_DIR)

all: $(NAME)

clean:
	@rm -f $(OBJS)
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(FT_PRINTF_DIR)

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(MAKE) fclean -C $(FT_PRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re
