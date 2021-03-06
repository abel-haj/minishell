NAME	= minishell

SRCS	= main.c \
		./gnl/get_next_line_utils.c ./gnl/get_next_line.c


OBJS	= $(SRCS:.c=.o)

CFLAGS	= -Wall -Wextra -Werror -g -fsanitize=address
DFLAGS	= -g -fsanitize=address

all		: $(NAME)

$(NAME)	:
	@make -C ./libft/
	@make clean -C ./libft/

	@gcc $(DFLAGS) $(SRCS) ./libft/libft.a -o $(NAME) && echo "\033[1;37mCollecting sea shells...\033[0;38m"

clean	:
	rm -rf *.o
	make clean -C ./libft

fclean	: clean
	rm -rf $(NAME)
	make fclean -C ./libft

re		: fclean all
	./minishell
