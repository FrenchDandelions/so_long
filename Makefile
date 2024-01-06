NAME = so_long
NAME_B = so_long_bonus
VERMILION_RED=\033[1;31m
AZURE_BLUE=\033[1;34m
GOLD_COLOR=\033[38;5;220m
GREEN=\033[0;32m
RESET=\033[0m
LIB_DIR = ./libft/
LIB_FILE = $(LIB_DIR)/libft.a
MLX_DIR = ./minilibx-linux/
MINI_LINUX = mini_linux.a
MLX_FILE = $(MLX_DIR)/libmlx.a
SRC_FILES = src/check_counter.c \
			src/render_all.c\
			src/check_map2.c \
			src/check_map.c \
			src/validpath.c \
			src/utils_check.c \
			src/error.c \
			src/get_next_line_utils.c \
			src/get_next_line.c \
			src/render_mouv.c \
			src/render_mouv2.c \
			src/utils_mlx.c \
			src/utils_mlx2.c \

SRC_FILES_B = src_bonus/check_counter_bonus.c \
			src_bonus/render_all_bonus.c\
			src_bonus/check_map2_bonus.c \
			src_bonus/check_map_bonus.c \
			src_bonus/validpath_bonus.c \
			src_bonus/utils_check_bonus.c \
			src_bonus/error_bonus.c \
			src_bonus/get_next_line_utils.c \
			src_bonus/get_next_line.c \
			src_bonus/render_mouv_bonus.c \
			src_bonus/render_mouv2_bonus.c \
			src_bonus/utils_mlx_bonus.c \
			src_bonus/utils_mlx2_bonus.c \
			src_bonus/anima_bonus.c \
			src_bonus/anima_2_bonus.c \
			src_bonus/render_enemy_mouv_bonus.c \

OBJECTS = $(patsubst %.c, %.o, $(SRC_FILES))
OBJECTS_B = $(patsubst %.c, %.o, $(SRC_FILES_B))
INCLUDE = $(LIB_DIR)/libft.h ./src/so_long.h ./src/get_next_line.h
INCLUDE_B = $(LIB_DIR)/libft.h ./src_bonus/so_long_bonus.h ./src_bonus/get_next_line.h
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
LDFLAGS = -L./minilibx-linux/ -lmlx_Linux -lX11 -lXext -lm
MLX_EX = $(MLX_FILE) $(LDFLAGS)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME) $(INCLUDE)
	@echo "$(VERMILION_RED)Credits to: "Penzilla", "Cainos", "Tofame", "Raphael Hatencia" and "Pixxilandartstudio"$(RESET)"
	@echo "$(VERMILION_RED)Go check their work on Itch.io :)$(RESET)"

bonus: $(NAME_B) $(INCLUDE_B)
	@echo "$(VERMILION_RED)Credits to: "Penzilla", "Cainos", "Tofame", "Raphael Hatencia" and "Pixxilandartstudio"$(RESET)"
	@echo "$(VERMILION_RED)Go check their work on Itch.io :)$(RESET)"

lib:
	@if [ ! -f "$(LIB_FILE)" ]; then \
		echo "$(GREEN)Compiling Libft...$(RESET)"; \
		make -C$(LIB_DIR) > /dev/null 2>&1; \
	fi

mlx:
	@if [ ! -f "$(MLX_FILE)" ]; then \
		echo "$(GREEN)Compiling Minilibx...$(RESET)"; \
		make -sC $(MLX_DIR) > /dev/null 2>&1; \
	fi
	

minilibx:
	@if [ ! -d "$(MLX_DIR)" ]; then \
		echo "$(VERMILION_RED)Cloning minilibx-linux...$(RESET)"; \
		git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR) > /dev/null 2>&1; \
	fi

$(NAME_B):minilibx lib  mlx $(OBJECTS_B)
	@echo "$(GOLD_COLOR)Compiling $@...$(RESET)"
	@$(CC) $(OBJECTS_B) $(LIB_FILE) $(MLX_EX) -o $(NAME_B)
	@echo "$(GOLD_COLOR)$@ compiled !$(RESET)"

$(NAME): minilibx lib mlx $(OBJECTS)
	@echo "$(GOLD_COLOR)Compiling $@...$(RESET)"
	@$(CC) $(OBJECTS) $(LIB_FILE) $(MLX_EX) -o $(NAME)
	@echo "$(GOLD_COLOR)$@ compiled !$(RESET)"

clean:
	@echo "$(AZURE_BLUE)Cleaning in progress...$(RESET)"
	@rm -f $(OBJECTS)
	@rm -f $(OBJECTS_B)
	@echo "$(AZURE_BLUE)Cleanup done ! :)$(RESET)"

fclean: clean
	@echo "$(AZURE_BLUE)Deep cleaning in progress...$(RESET)"
	@make fclean -C$(LIB_DIR) > /dev/null 2>&1
	@rm -f $(NAME)
	@rm -f $(NAME_B)
	@echo "$(AZURE_BLUE)Deep Cleaning over ! :)$(RESET)"	

u_clean : fclean
	@echo "$(VERMILION_RED)Getting rid of the minilibx...$(RESET)"
	@rm -rf $(MLX_DIR)
	@echo "$(VERMILION_RED)RIP minilibx :($(RESET)"

re: fclean $(NAME)

re_bonus: fclean $(NAME_B)

re_all: fclean $(NAME) $(NAME_B)

re_u: u_clean $(NAME) $(NAME_B)

.PHONY: all clean fclean re lib mlx minilibx bonus re_u re_all re_bonus u_clean