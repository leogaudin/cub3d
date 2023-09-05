# COLORS
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = include

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

LIBFT_PATH = include/libft
LIBFT = $(LIBFT_PATH)/libft.a

MLX				= libmlx.dylib

NAME = cub3D

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(MLX) $(OBJ_FILES) $(LIBFT)
	@$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_PATH) -Lmlx -framework OpenGL -framework AppKit
	@echo "$(GREEN)+ $(NAME)$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -Imlx -I$(LIBFT_PATH) -c -o $@ $<

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

$(MLX):
	@$(MAKE) -C mlx
	@mv mlx/$(MLX) .
	@echo "$(GREEN)+ $(MLX)$(RESET)"

clean:
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(MAKE) -C mlx clean
	@$(RM) -r $(OBJ_DIR)

fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME) $(MLX)
	@echo "$(RED)- $(NAME)$(RESET)"

re: fclean all
