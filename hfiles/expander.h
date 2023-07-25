/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 01:13:48 by rrodor            #+#    #+#             */
/*   Updated: 2023/07/26 01:13:49 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H
# include "minishell.h"

char	*delete_quotes(char *str, char c);
int		question_mark(char **tmp);
char	*char_to_str(char c);
size_t	dollar_sign(char *str);
char	*expander_str(t_tools *tools, char *str);
char	**expander(t_tools *tools, char **str);

#endif
