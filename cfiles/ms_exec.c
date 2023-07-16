/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:11:20 by rrodor            #+#    #+#             */
/*   Updated: 2023/07/16 19:28:02 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ms_check_path(char *cmd, char **ev)
{
	char	**paths;
	char	*path;
	char	*no_ex;
	int		i;

	i = 0;
	while (ft_strncmp(ev[i], "PATH=", 5))
		i++;
	paths = ft_split(ev[i] + 5, ':');
	i = -1;
	while (paths[++i])
	{
		no_ex = ft_strjoin(paths[i], "/");
		path = ft_strjoin(no_ex, cmd);
		free(no_ex);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
	}
	return (NULL);
}

void	ms_execpath(char **av, char **ev)
{
	int		i;
	char	*path;
	pid_t	pid;

	i = -1;
	path = ms_check_path(av[0], ev);
	if (!path)
	{
		//free_array(av);
		exit(2);
	}
	execve(path, av, ev);
}

void	ms_execpath2(char **av, char **ev)
{
	int		i;
	char	*path;
	pid_t	pid;

	i = -1;
	path = ms_check_path(av[0], ev);
	if (!path)
	{
		//free_array(av);
		exit(2);
	}
	pid = fork();
	if (pid == -1)
		return ;
	if (!pid)
		execve(path, av, ev);
	else
		waitpid(pid, NULL, 0);
}

int	ms_exec(char **cmd, char **env)
{
	if (ft_strncmp(cmd[0], "exit", 4) == 0)
	{
		free(cmd[0]);
		exit(0) ;
	}
	else if (ft_strncmp(cmd[0], "export", 6) == 0)
		ft_printf("#export\n");
	else if (ft_strncmp(cmd[0], "unset", 5) == 0)
		ft_printf("#unset\n");
	else if (ft_strncmp(cmd[0], "env", 3) == 0)
		ft_printf("#env\n");
	else if (ft_strncmp(cmd[0], "pwd", 3) == 0)
		ms_pwd();
	else if (ft_strncmp(cmd[0], "cd", 2) == 0)
		ms_cd(cmd[1]);
	else if (ft_strncmp(cmd[0], "echo", 4) == 0)
		ms_echo(cmd[1], 1);
	else
		ms_execpath2(cmd, env);
}

int ms_central(t_list *parse, char **env)
{
	if (ft_lstsize(parse) == 1)
	{
		ms_exec((char **) parse->content, env);
		return (0);
	}
	else
	{
		ms_pipe(&parse, env);
		return (0);
	}
}
