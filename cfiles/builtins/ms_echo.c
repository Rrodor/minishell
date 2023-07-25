/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 01:16:13 by rrodor            #+#    #+#             */
/*   Updated: 2023/07/26 01:16:14 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_lines(int i, char **str, int out)
{
	while (str[i])
	{
		ft_putstr_fd(str[i++], out);
		if (str[i])
			ft_putchar_fd(' ', out);
	}
}

int	ms_echo(t_tools *tools, t_cmd *cmd)
{
	int i;
	int j;
	int option;

	i = 1;
	option = 0;
	(void) tools;
	while (cmd->str[i] && cmd->str[i][0] == '-'
		&& cmd->str[i][1] == 'n')
	{
		j = 1;
		while (cmd->str[i][j] == 'n')
			j++;
		if (cmd->str[i][j] == '\0')
			option = 1;
		else
			break ;
		i++;
	}
	print_lines(i, cmd->str, STDOUT_FILENO);
	if (option == 0)
		ft_putchar_fd('\n', STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
