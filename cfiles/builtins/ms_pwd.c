/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 20:38:53 by aramon            #+#    #+#             */
/*   Updated: 2023/07/26 01:16:23 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*int	ms_pwd(t_tools *tools, t_cmd *simple_cmd)
{
	(void) simple_cmd;
	ft_putendl_fd(tools->pwd, STDOUT_FILENO);
	return (EXIT_SUCCESS);
}*/

int	ms_pwd(void)
{
	char	*buf;
	int		i;

	i = 2;
	buf = malloc (20);
	if (!buf)
		return (EXIT_FAILURE);
	buf = getcwd(buf, 20);
	while (!buf)
	{
		free(buf);
		buf = malloc (20 * i);
		if (!buf)
			return (EXIT_FAILURE);
		buf = getcwd(buf, 20 * i);
		i++;
	}
	ft_printf("%s\n", buf);
	free (buf);
	return (EXIT_SUCCESS);
}

char	*ms_getpwd(void)
{
	char	*buf;
	int		i;

	i = 2;
	buf = malloc (20);
	if (!buf)
		return (NULL);
	buf = getcwd(buf, 20);
	while (!buf)
	{
		free(buf);
		buf = malloc (20 * i);
		if (!buf)
			return (NULL);
		buf = getcwd(buf, 20 * i);
		i++;
	}
	return (buf);
}
