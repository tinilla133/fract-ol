# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvizcaya <fvizcaya@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/14 18:42:48 by fvizcaya          #+#    #+#              #
#    Updated: 2024/08/09 13:33:07 by fvizcaya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang 
#CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address,undefined,leak
CFLAGS = -Wall -Wextra -Werror
LINKER_FLAGS = -lm -lXext -lX11 -lc
NAME = fractol
LIBFT_DIR = libft/
LIBFT = libft.a
MINILIBX_DIR = minilibx_linux/
MINILIBX = libmlx.a
SRC = \
	arguments_parsing.c \
	calculate_fractal.c \
	change_color.c \
	change_set.c \
	colors.c \
	draw.c \
	fractal_init.c \
	julia.c \
	keyboard_events.c \
	main.c \
	mandelbrot.c \
	mlx_init.c \
	memory_alloc.c \
	mouse_events.c \
	move_and_zoom.c \
	multibrot.c \
	print_help.c \
	utils.c \
	window_events.c
	
OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(MINILIBX) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_DIR)$(LIBFT) $(MINILIBX_DIR)$(MINILIBX) $(LINKER_FLAGS) -o $(NAME)
	
$(LIBFT):
	make -C $(LIBFT_DIR)

$(MINILIBX):
	make -C $(MINILIBX_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(MINILIBX_DIR)
	rm -rf $(OBJ)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	make clean -C $(MINILIBX_DIR)
	rm -rf $(NAME)
	
re: fclean all

.PHONY: all clean fclean re
