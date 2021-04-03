NAME	= minishell.a

SRCS	= main.c

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -Wall -Wextra -Werror

all		: $(NAME)

$(NAME)	:
	make -C ./libft/
	make clean -C ./libft/
	make -C ./gnl/
	make clean -C ./gnl/
	gcc -s $(SRCS)
	ar rc $(NAME) $(OBJS)

clean	:

fclean	: clean

re		: fclean all
