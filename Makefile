NAME	= minishell

SRCS	= main.c \
		shared_utils/minishell_utils_one.c shared_utils/minishell_utils_two.c \
		parse/*.c \
		execute/*.c


OBJS	= $(SRCS:.c=.o)

CFLAGS	= -Wall -Wextra -Werror -lreadline
DFLAGS	= -g -fsanitize=address

all		: $(NAME)

$(NAME)	:
	@make -C ./libft/
	@make clean -C ./libft/

	@gcc $(CFLAGS) $(DFLAGS) $(SRCS) ./libft/libft.a -o $(NAME) && echo "\033[1;37mCollecting sea shells...\033[0;38m"

clean	:
	rm -rf *.o
	make clean -C ./libft

fclean	: clean
	rm -rf $(NAME)
	make fclean -C ./libft

re		: fclean all
	./minishell

.PHONY	: re fclean clean all
