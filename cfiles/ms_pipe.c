/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:58:36 by rrodor            #+#    #+#             */
/*   Updated: 2023/07/17 21:59:18 by rrodor           ###   ########.fr       */
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

void	ms_pipe(t_list *av, char **env)
{
	char	**sep;
	char	**tmp;

	sep = av->next->content;
	if (ft_strncmp(sep[0], "|", 1) == 0)
		ms_child(av->content, env);
	else if (ft_strncmp(sep[0], "<<", 2) == 0)
	{
		tmp = av->next->next->content;
		here_doc(tmp[0], 1);
	}
	else if (ft_strncmp(sep[0], ">>", 2) == 0)
		ms_rediroutdouble(av, env);
	else if (ft_strncmp(sep[0], ">", 1) == 0)
		ms_redirout(av, env);
	else if (ft_strncmp(sep[0], "<", 1) == 0)
		ms_redirin(av, env);
}
int	ms_specialsep(t_list **parse, char **env)
{
	t_list	*tmp;
	char	**sep;
	int		savestdin;
	int		savestdout;

	savestdin = dup(STDIN_FILENO);
	savestdout = dup(STDOUT_FILENO);
	tmp = *parse;
	while (tmp)
	{
		if (tmp->next)
		{
			ms_pipe(tmp, env);
			sep = tmp->next->content;
			if (sep && ft_strncmp(sep[0], "|", 1) == 0)
				tmp = tmp->next->next;
			else
				tmp = NULL;
		}
		else
		{
			dup2(1, STDOUT_FILENO);
			ms_exec(tmp->content, env);
			tmp = NULL;
		}
	}
	dup2(savestdin, STDIN_FILENO);
	dup2(savestdout, STDOUT_FILENO);
	return (0);
}
