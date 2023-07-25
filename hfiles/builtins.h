/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 01:13:58 by rrodor            #+#    #+#             */
/*   Updated: 2023/07/26 01:13:59 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H
# include "minishell.h"

int		(*builtin_arr(char *str))(t_tools *tools, t_cmd *cmd);

void	change_path(t_tools *tools);
int		ms_echo(t_tools *tools, t_cmd *cmd);
int		ms_cd(t_tools *tools, t_cmd *cmd);
int		ms_pwd(void);
char	*ms_getpwd(void);
int		ms_export(t_tools *tools, t_cmd *cmd);
int		ms_unset(t_tools *tools, t_cmd *cmd);
int		ms_env(t_tools *tools, t_cmd *cmd);
int		ms_exit(t_tools *tools, t_cmd *cmd);

size_t	equal_sign(char *str);
int		check_valid_identifier(char c);
char	*delete_quotes_value(char *str);
int		after_dollar_lenght(char *str, int j);

#endif
