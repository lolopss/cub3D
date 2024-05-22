CC = @gcc -Wall -Wextra -Werror -g
RM = @rm -f
NAME = cub3D
SRC =	main.c main_functions.c \
		cub3d_exec.c cub3d_exec2.c \
		check_args.c check_args2.c check_args3.c \
		utils.c utils2.c ft_strlen.c ft_split.c minimap.c \
		map_utils.c map_utils2.c map_utils3.c get_textures.c get_texture2.c pixel_color_door.c\
		key.c key_rotate.c \


OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) mlx-linux/libmlx.a -lXext -lX11 -lm -o $(NAME)

all: $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re:	fclean all
