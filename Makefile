# Nome do executável
NAME = so_long

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# Diretórios
SRC_DIR = src
INC_DIR = src
LIBFT_DIR = libft
MLX_DIR = minilibx-linux

# Includes
INCLUDES = -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)

# Fontes do projeto (especificados manualmente)
SRC = \
	$(SRC_DIR)/animations.c \
	$(SRC_DIR)/key_handler.c \
	$(SRC_DIR)/free.c \
	$(SRC_DIR)/error.c \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/innit.c \
	$(SRC_DIR)/render_map.c \
	$(SRC_DIR)/move_check.c \
	$(SRC_DIR)/map/map_parsing.c \
	$(SRC_DIR)/map/map_check.c \
	$(SRC_DIR)/map/map_to_struct.c \
	$(SRC_DIR)/map/final_parsing.c \
	$(SRC_DIR)/map/main_parser.c \

# Objetos
OBJ = $(SRC:.c=.o)

# Bibliotecas externas
LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a

# Flags da MiniLibX (para Linux)
MLX_FLAGS = -lX11 -lXext -lm

# Regra principal
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT) $(MLX) -o $(NAME) $(MLX_FLAGS)

# Compilar libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Compilar mlx
$(MLX):
	$(MAKE) -C $(MLX_DIR)

# Limpar objetos
clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

# Limpar tudo
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MLX_DIR) clean

# Recompilar tudo
re: fclean all

.PHONY: all clean fclean re

