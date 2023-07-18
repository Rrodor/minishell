/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:22:27 by rrodor            #+#    #+#             */
/*   Updated: 2023/07/17 21:57:37 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ms_redirout(t_list *av, char **env)
{
	int		fd;
	char	**tmp;
	char 	**file;

	tmp = av->content;
	file = av->next->next->content;
	fd = open(file[0], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	ms_exec(tmp, env);
}

void	ms_rediroutdouble(t_list *av, char **env)
{
	int		fd;
	char	**tmp;
	char 	**file;

	tmp = av->content;
	file = av->next->next->content;
	fd = open(file[0], O_WRONLY | O_CREAT | O_APPEND, 0664);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	ms_exec(tmp, env);
}

void	ms_redirin(t_list *av, char **env)
{
	int		fd;
	char	**tmp;
	char 	**file;

	tmp = av->content;
	file = av->next->next->content;
	fd = open(file[0], O_RDONLY);
	dup2(fd, STDIN_FILENO);
	close(fd);
	ms_exec(tmp, env);
}

/*void	ms_redirindouble(t_list *av, char **env)
{
	int		fd;
	char	**tmp;
	char 	**file;

	tmp = av->content;
	file = av->next->next->content;
	fd = open(file[0], O_RDONLY);
	dup2(fd, STDIN_FILENO);
	close(fd);
	ms_exec(tmp, env);
}*/
