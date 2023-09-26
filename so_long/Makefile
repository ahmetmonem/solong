NAME=so_long
SRC= ./get_next_line/get_next_line_utils.c ./get_next_line/get_next_line.c so_long.c map_error.c map_error1.c map_error2.c put_images.c put_images2.c starttheconnection.c
CFLAGS = -framework OpenGl -framework Appkit -Lminilibx -lmlx
LIB = ./minilibx/libmlx.a
LIB1 = ./ft_printf/libftprintf.a
CC=gcc
all: $(NAME)

$(NAME): $(LIB) $(LIB1) $(SRC)
	$(CC) $(CFLAGS) $(LIB1) $(LIB) $(SRC) -o $(NAME)

$(LIB):
	make -C ./minilibx

$(LIB1):
	make -C ./ft_printf

clean:
	make clean -C ./ft_printf

fclean:
	make fclean -C ./ft_printf
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re