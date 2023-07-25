/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 01:13:56 by rrodor            #+#    #+#             */
/*   Updated: 2023/07/26 01:13:57 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H
# include "minishell.h"

void	cmd_clear(t_cmd **lst);
void	cmd_rm_first(t_cmd **lst);
void	cmd_add_back(t_cmd **lst, t_cmd *new);
t_cmd	*cmd_new(char **str, int n_redir, t_lexer *redirs);
t_cmd	*cmd_first(t_cmd *lst);

char	*join_split_str(char **split_str, char *new_str);
char	**resplit_str(char **double_arr);

#endif
