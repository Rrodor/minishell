#ifndef ERROR_H
# define ERROR_H
# include "minishell.h"

void	parser_error(int error, t_tools *tools, t_lexer *lexer_list);
int		parser_double_token_error(t_tools *tools, t_lexer *lexer_list, int token);
void	lexer_error(int error, t_tools *tools);
int		cmd_not_found(char *str);
int     export_error(char *c);
int		ft_error(int error, t_tools *tools);

#endif