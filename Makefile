NAME = push_swap

SRC = utils/ft_atoi.c\
	utils/array.c\
	utils/spisok.c\
	stack_oper/push_stack.c\
	stack_oper/rotate_stack.c\
	stack_oper/swap_stack.c\
	sort/sort.c\
	sort/sort_max.c\
	sort/sort_max_help.c\
	sort/sort_push.c\
	push_swap.c\

OBJ = $(SRC:.c=.o)

HDRS = push_swap.h

CC = gcc

FLAGS = -Wall -Wextra -Werror

RM = rm -f

$(NAME): $(HDRS) $(OBJ)
		$(CC) $(FLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean
