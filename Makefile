NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Iheaders/

SOURCE = 	main.c \
			ft_controls.c \
			ft_count.c \
			ft_images.c \
			ft_map.c \
			ft_search.c

OBJ = ${SOURCE:.c=.o}

PRINTF := ft_printf/libftprintf.a
GETNEXTLINE := get_next_line/*c
LIBRARY := -Lminilibx -lmlx -framework OpenGL -framework AppKit
MINILIBX := minilibx/libmlx.a

all: $(NAME)

$(NAME): $(OBJ)
		@${MAKE} -C ./ft_printf
		@${MAKE} -C ./minilibx
		@${CC} ${CFLAGS} $(SOURCE) $(LIBRARY) $(PRINTF) $(GETNEXTLINE) -o $(NAME)

clean:
	@${MAKE} -C ./ft_printf clean
	@${MAKE} -C ./minilibx clean
	rm -rf $(OBJ)

fclean: clean
	@${MAKE} -C ./ft_printf fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
