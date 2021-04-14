NAME	= minishell

SRCS	= main.c \
		./gnl/get_next_line_utils.c ./gnl/get_next_line.c


OBJS	= $(SRCS:.c=.o)

CFLAGS	= -Wall -Wextra -Werror

all		: $(NAME)

$(NAME)	:
	make -C ./libft/
	make clean -C ./libft/

	gcc $(SRCS) ./libft/libft.a -o $(NAME)

clean	:
	rm -rf *.o
	make clean -C ./libft

fclean	: clean
	rm -rf $(NAME)
	make fclean -C ./libft

re		: fclean all
