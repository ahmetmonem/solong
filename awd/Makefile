NAME=so_long
SRC= get_next_line_utils.c get_next_line.c so_long1.c ft_itoa.c
CFLAGS = -framework OpenGl -framework Appkit -Lminilibx -lmlx
LIB = ./minilibx/libmlx.a
CC=gcc
all: $(NAME)

$(NAME): $(LIB) $(SRC)
	$(CC) $(CFLAGS) $(LIB) $(SRC) -o $(NAME)

$(LIB):
	make -C ./minilibx


re: clean all
