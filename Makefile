NAME = fillit

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
			backtracking.c\

OBJ = $(SOURCES:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(FLAiGS) -o $(NAME) $(SOURCES)

all: $(NAME)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
