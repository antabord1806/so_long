
NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror


SRC_DIR = src
INC_DIR = src
LIBFT_DIR = libft
MLX_DIR = minilibx-linux


INCLUDES = -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)

SRC = \
	$(SRC_DIR)/animations.c \
	$(SRC_DIR)/key_handler.c \
	$(SRC_DIR)/free.c \
	$(SRC_DIR)/error.c \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/innit.c \
	$(SRC_DIR)/load_img.c \
	$(SRC_DIR)/render_map.c \
	$(SRC_DIR)/move_check.c \
	$(SRC_DIR)/map/map_parsing.c \
	$(SRC_DIR)/map/map_check.c \
	$(SRC_DIR)/map/map_to_struct.c \
	$(SRC_DIR)/map/final_parsing.c \
	$(SRC_DIR)/map/main_parser.c \

OBJ = $(SRC:.c=.o)

LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a

MLX_FLAGS = -lX11 -lXext -lm

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT) $(MLX) -o $(NAME) $(MLX_FLAGS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re

