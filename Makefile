NAME = cub3D

SRCS = 	SRCS/GNL/get_next_line_utils.c \
		SRCS/GNL/get_next_line.c \
		SRCS/INIT/hook.c \
		SRCS/INIT/init_mlx.c \
		SRCS/INIT/init_play.c \
		SRCS/CHECK/check_if_close.c \
		SRCS/CHECK/check_map.c \
		SRCS/CHECK/check_name.c \
		SRCS/CHECK/check_all.c \
		SRCS/CHECK/check_position.c\
		SRCS/MOVE/move_all.c \
		SRCS/MOVE/move_wasd.c \
		SRCS/MOVE/rotate_move.c \
		SRCS/GET_OPTION/get_opt.c \
		SRCS/GET_OPTION/get_texture.c \
		SRCS/DRAW/draw2.c \
		SRCS/DRAW/raycast.c \
		SRCS/DRAW/display.c \
		SRCS/UTILS/catch_size.c \
		SRCS/UTILS/ft_split.c \
		SRCS/UTILS/utils.c \
		SRCS/UTILS/utils2.c \
		SRCS/EXIT/free_map.c \
		SRCS/EXIT/free_data.c \
		SRCS/main.c
				
OBJS 		= 	${SRCS:.c=.o}

PATH_MLX	=	./mlx
CC 			= 	gcc

CFLAGS		= 	-Wall -Wextra -Werror -g3 #-fsanitize=address
RM			= 	rm -f
FLAGS		=	-ldl -Imlx -Lmlx -lmlx -lm -lXext -lX11

all: 			${NAME}

.c.o:
				${CC} ${CFLAGS} -Imlx -Ibass -c $< -o ${<:.c=.o}

$(NAME): 		$(OBJS)
				@make -C $(PATH_MLX)
				${CC} $(CFLAGS) $(OBJS) $(FLAGS) -o $(NAME)


clean:
				make -C $(PATH_MLX) clean
				${RM} ${OBJS}

fclean: 		clean
				${RM} ${NAME}

re: 			fclean all

.SILENT:		$(NAME)

.PHONY:			all clean fclean re