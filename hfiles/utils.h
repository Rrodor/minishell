#ifndef UTILS_H
# define UTILS_H
# include "minishell.h"

void	free_arr(char **split_arr);
char	**dup_arr(char **arr);
int     count_quotes(char *line);

#endif