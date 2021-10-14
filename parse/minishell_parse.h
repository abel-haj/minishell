#ifndef MINISHELL_PARSE_H

# define MINISHELL_PARSE_H

/*
 * cmd[*1, *2, *3, NULL]
 * 
 * options
 * arguments
 * 
 * type :
 *   1 : redirection
 *   2 :
 * 
 * text :
 *   command as it is
 * 
 * redir_before :
 * redir_after :
 *   1 : <
 *   2 : >
 *   3 : <<
 *   4 : >>
 * 
 * is_builtin :
 *   0 OR 1
 */
typedef struct s_cmd {
	// char	*cmd;
	// char	**options;
	// char	**arguments;
	char	*text;
	int		redir_before;
	int		redir_after;
	char	is_builtin;
	int		error;
}				t_cmd;

typedef struct s_lst_cmd {
	t_cmd				*content;
	struct s_lst_cmd	*next;
}				t_lst_cmd;

void			handle_line(char *s);
void			ft_lstprint(t_lst_cmd *list);
t_lst_cmd		*ft_lstnew(void *content);
void			ft_lstadd_front(t_lst_cmd **alst, t_lst_cmd *new);
int				ft_lstsize(t_lst_cmd *lst);
t_lst_cmd		*ft_lstlast(t_lst_cmd *lst);
void			ft_lstadd_back(t_lst_cmd **alst, t_lst_cmd *new);
void			ft_lstdelone(t_lst_cmd *lst, void (*del)(void *));
void			ft_lstclear(t_lst_cmd **lst, void (*del)(void *));
void			ft_lstiter(t_lst_cmd *lst, void (*f)(void *));
t_lst_cmd		*ft_lstmap(t_lst_cmd *l, void *(*f)(void *), void (*d)(void *));

#endif
