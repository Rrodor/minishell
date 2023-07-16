/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:58:36 by rrodor            #+#    #+#             */
/*   Updated: 2023/07/16 19:40:02 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ms_child(char **av, char **ev)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		return ;
	pid = fork();
	if (pid == -1)
		return ;
	if (!pid)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		ms_execpath(av, ev);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

int	ms_pipe(t_list **parse, char **env)
{
	t_list	*tmp;
	int		savestdin;
	int		savestdout;

	savestdin = dup(STDIN_FILENO);
	savestdout = dup(STDOUT_FILENO);
	tmp = *parse;
	while (tmp->content)
	{
		if (tmp->next && ft_strncmp(tmp->next->content, "|", 1))
		{
			ms_child(tmp->content, env);
			tmp = tmp->next->next;
		}
		else
		{
			dup2(1, STDOUT_FILENO);
			ms_exec(tmp->content, env);
			dup2(savestdin, STDIN_FILENO);
			dup2(savestdout, STDOUT_FILENO);
			//exit(0);
			return (0);
		}
	}
	return (0);
}
