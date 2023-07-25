/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 01:16:07 by rrodor            #+#    #+#             */
/*   Updated: 2023/07/26 01:16:08 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	(*builtin_arr(char *str))(t_tools *tools, t_cmd *cmd)
{
	static void	*builtins[7][2] = {
	{"echo", ms_echo},
	{"cd", ms_cd},
	{"pwd", ms_pwd},
	{"export", ms_export},
	{"unset", ms_unset},
	{"env", ms_env},
	{"exit", ms_exit}
	};
	int			i;

	i = 0;
	while (i < 7)
	{
		if (str)
		{
			if (!ft_strncmp(builtins[i][0], str, ft_strlen((builtins[i][0]))))
				return (builtins[i][1]);
		}
		i++;
	}
	return (NULL);
}
