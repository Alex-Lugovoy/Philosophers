NAME 	= philo

DIR 	= .

LIST 	=	main.c untils_func.c \
			memory_alloc.c philo_start.c \
			waiting.c check_status.c printf_mutex.c

OBJ 	=	$(LIST:.c=.o)

FLAGS 	= -Wall -Wextra -Werror -I$(DIR)

CC		= gcc

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(FLAGS) $(OBJ) -o $(NAME)
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
