NAME = cub3D

SRCS =	test_main.c \
		map_parse/ft_check_args.c \
		map_parse/ft_check_map_file.c \
		map_parse/ft_check_map.c \
		map_parse/ft_clear_map.c \
		map_parse/ft_extract_map.c \
		map_parse/ft_walls_check.c \
		map_parse/get_next_line_utils.c \
		map_parse/get_next_line.c \
		utils/free_matrix.c \
		utils/ft_matrix_len.c\
		utils/ft_rgb_to_hex.c\
		raycasting/ft_open_window.c\
		raycasting/ft_perp_dist.c\
		raycasting/ft_renders.c\
		raycasting/ft_ray_step.c\
		move/handle_move.c\
		move/moves.c\
		map_parse/colors_textures.c\
		map_parse/ft_check_textures.c\

MLX = mlx_linux/

LIBFT_DIR = libs/libft
LIBFT = libs/libft/libft.a

PRINTF_DIR = libs/ft_printf
PRINTF = libs/ft_printf/libftprintf.a

GNL = includes/

CC = gcc

FLAGS = -Wextra -Wall -Werror -g

LINKS = -L${LIBFT_DIR} -lft -L${PRINTF_DIR} -lftprintf

RM = rm -f

OBJS = ${SRCS:.c=.o}

INCLUDE = -I${LIBFT_DIR} -I${PRINTF_DIR} -I${MLX} -I${GNL}

%.o:%.c
	${CC} ${FLAGS} ${INCLUDE} -I/usr/include -Imlx_linux -O3 -c $< -o $@ -lXext -lX11 -lmlx_Linux

all: ${LIBFT} ${PRINTF} ${NAME}

${NAME}: ${OBJS}
	@${CC} ${FLAGS} ${LIBFT} ${PRINTF} ${OBJS} -o ${NAME} ${LINKS} -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

${LIBFT}:
	@make -C ${LIBFT_DIR}

${PRINTF}:
	@make -C ${PRINTF_DIR}

clean:
	@${RM} ${OBJS}
	@make clean -C ${LIBFT_DIR}
	@make clean -C ${PRINTF_DIR}

fclean: clean
	@${RM} ${NAME} ${OBJS}
	@make fclean -C ${LIBFT_DIR}
	@make fclean -C ${PRINTF_DIR}

re: fclean all

.PHONY: all clean fclean re

run-valgrind:
	@clear
	-valgrind --leak-check=full --show-leak-kinds=all --log-file="val_log" ./cub3D maps/map1.cub
