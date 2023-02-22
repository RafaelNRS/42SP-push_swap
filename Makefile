CC				= gcc
CFLAGS			= -Wall -Wextra -Werror

NAME_PROJECT		= push_swap

LIBFT_DIR		= ./libft/
LIBFT 			= ./libft/libft.a
HEADER_LIBFT	= ./libft/

INCLUDE_DIR		= ./include/
HEADER			= push_swap.h
HEADER_PATH		= ./include/push_swap.h

SRC_DIR			= ./src/
SRC_CLIENT		= push_swap.c
SRC_CLIENT_PATH	= ./src/push_swap.c ./src/swap_ops.c ./src/push_ops.c ./src/rotate_ops.c ./src/rev_rotate_ops.c

BIN						= ./bin/
BINARY_OUT_PROJ		= ./bin/push_swap

all: $(BINARY_OUT_PROJ)

$(BINARY_OUT_PROJ): $(SRC_CLIENT_PATH)
	@ $(MAKE) -C $(LIBFT_DIR)
	@ cp $(LIBFT) $(NAME_PROJECT)
	@ mkdir -p $(BIN)
	@ $(CC) $(CFLAGS) $(SRC_CLIENT_PATH) -I $(INCLUDE_DIR) -I $(HEADER_LIBFT) -L $(LIBFT_DIR) -lft -o $(NAME_PROJECT)
	@ mv $(NAME_PROJECT) $(BIN)

clean:
	@ $(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	@ $(MAKE) fclean -C $(LIBFT_DIR)
	@ rm -f $(BINARY_OUT_PROJ)
	@ rm -rf $(BIN)

re: fclean all

.PHONY: all clean fclean re