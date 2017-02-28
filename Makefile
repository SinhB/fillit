NAME = fillit.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

SOURCES = 	check_errors.c\
			fill_base.c\
			fill_grid.c\
			fillit.c\
			functions_lib.c\
			main.c\
			print_grid.c\
			set_grid.c\

OBJ = $(SOURCES:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -c $(SOURCES)
		ar rc $(NAME) $(OBJ)
			ranlib $(NAME)
all: $(NAME)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re