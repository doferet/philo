#-------Makefile-------#

NAME = philo

CC = cc 
CFLAGS = -Wall -Werror -Wextra -fsanitize=thread

SRC = check_error.c \
      die.c \
      eat.c \
      free_philo.c \
	  init_philo.c \
	  monitor.c \
	  parsing.c \
	  philo.c \
	  routine.c \
	  safe_print.c \
	  sleep.c \
	  think.c \
	  utils.c \

OBJ = $(SRC:.c=.o)

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compilation..."
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "Philo is ready !"

clean:
	@echo "Clean..."
	@$(RM) *.o
	@echo "Done !"

fclean: clean
	@echo "Remove all..."
	@$(RM) $(NAME)
	@echo "Done !"

re: fclean all

.PHONY: all re clean fclean
