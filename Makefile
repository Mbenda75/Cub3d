NAME = cub3D

SRCS = 	gnl/get_next_line_utils.c \
		gnl/get_next_line.c \
		init/init_mlx.c \
		init/init_play.c \
		check/check_if_close.c \
		check/check_map.c \
		check/check_utils.c \
		check/check_name.c \
		check/check_all.c \
		check/check_position.c\
		move/move_all.c \
		move/move_wasd.c \
		move/rotate_move.c \
		get_option/get_opt.c \
		get_option/get_opt_utils.c \
		draw/draw2.c \
		draw/raycast.c \
		draw/display.c \
		catch_size.c \
		ft_split.c \
		utils.c \
		utils2.c \
		hook.c \
		exit/free_map.c \
		exit/free_data.c \
		main.c
				
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