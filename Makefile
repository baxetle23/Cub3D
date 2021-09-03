NAME	= cub3D

SRCS	= main.c\
		parser/map_validation.c\
		parser/map_utils.c\
		parser/check_walls_start.c\
		parser/check_walls_end.c\
		parser/make_map_check_starting_position.c\
		parser/get_paths_colors_map_info.c\
		parser/get_and_check_path.c\
		parser/map_validation_utils.c\
		render/main_raycaster.c\
		render/inizilization.c\
		render/texture.c\
		render/render_map.c\
		render/lodev.c\
		render/print.c\
		render/moving.c\
		render/move_function.c

OBJS	= ${SRCS:.c=.o}

CFLAGS	= -Wall -Wextra -Werror

MLX_DIR = minilibx_opengl_20191021

LIBFT_DIR = libft

%.o: %.c cub.h
	gcc -c ${CFLAGS} -I . $< -o ${<:.c=.o}

${NAME}: ${OBJS} cub.h
	ar rc libcub.a ${OBJS}
	ranlib libcub.a
	make -C ${MLX_DIR}
	cd ..
	make -C ${LIBFT_DIR}
	cd ..
	gcc ${CFLAGS} ${LIBFT_DIR}/libft.a ${MLX_DIR}/libmlx.a -lmlx -framework OpenGL -framework AppKit ${OBJS} -L. -lcub -lm -o ${NAME}

all:	${NAME}

clean:
	rm -f ${OBJS}
	make -C ${MLX_DIR} clean
	cd ..
	make -C ${LIBFT_DIR} clean
	cd ..

fclean:	clean
	rm -f ${NAME} libcub.a ${LIBFT_DIR}/libft.a

re: fclean all

.PHONY:	all fclean clean re








