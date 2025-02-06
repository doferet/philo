#-------Makefile-------#

NAME = philo

CC = cc 
CFLAGS = -Wall -Werror -Wextra -pthread -g3

SRC = philo.c \
      utils.c \
      init_philo.c \
      check_error.c \
	  parsing.c \
	  routine.c \
	  die.c \
	  eat.c \
	  sleep.c \
	  think.c \
	  safe_print.c \

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
