NAME 	= philo

DIR 	= .

LIST 	=	main.c untils_func.c memory_alloc.c philo_start.c waiting.c check_status.c

OBJ 	=	$(LIST:.c=.o)

FLAGS 	= -Wall -Wextra -Werror -I$(DIR)

CC		= gcc

.c.o:
	$(CC)  -c $< -o $(<:.c=.o) #после СС флаги

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(OBJ) -o $(NAME) -fsanitize=address #после СС флаги
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
