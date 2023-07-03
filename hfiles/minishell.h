/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:13:44 by rrodor            #+#    #+#             */
/*   Updated: 2023/07/03 23:26:23 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_parse
{
	char	*str;
	int		type;
}				t_parse;

// ms_parsing.c
t_list *ms_parsing(char *line);
t_list *ms_pipesplit(char *line);
t_list	*ms_firstsplit(char *line);
char	*ms_fsquote(char *line, int *i, char *str, t_list **list);
char	*ms_fsspecial(char *line, int *i, char *str, t_list **list);

// ms_parsing_utils.c
char	*ms_strjoinc(char *str, char c);

// error.c
int	ms_error(char *line);
int	ms_error2(char *line, int i);
int	ms_errorpipe(char *line, int *i);
int ms_errorquote(char *line, int *i);
int ms_errorredir(char *line, int *i);

#endif
