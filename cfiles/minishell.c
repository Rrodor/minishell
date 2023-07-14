/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:32:05 by rrodor            #+#    #+#             */
/*   Updated: 2023/07/14 15:58:36 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hfiles/minishell.h"

void	ms_printlist(void *s)
{
	char **str;
	int i;

	str = s;
	i = 0;
	while (str[i])
	{
		ft_printf("%s", str[i]);
		i++;
	}
	ft_printf("\n");
}

/*
int	main()
{
	char	*str;
	t_list	*list;
	t_env	*env;
	int		i;

	env = NULL;
	while (1)
	{
		str = readline("minishell >> ");
		list = ms_parsing(str);
		//ft_lstiter(list, ms_printlist);
		add_history(str);

		if (ft_strncmp(str, "exit", 4) == 0)
		{
			free(str);
			break ;
		}
		else if (ft_strncmp(str, "export", 6) == 0)
			ms_export(clean_command("export", str), &env);
		else if (ft_strncmp(str, "unset", 5) == 0)
			ms_unset(clean_command("unset", str), &env);
		else if (ft_strncmp(str, "env", 3) == 0)
			ms_env(env);
		else if (ft_strncmp(str, "pwd", 3) == 0)
			ms_pwd();
		else if (ft_strncmp(str, "cd", 2) == 0)
			ms_cd(str);
		//else if (ft_strncmp(str, "echo", 4) == 0)
		//	ms_echo(clean_command("echo", str));
		else
		{
			ft_printf("command not found :%s\n", str);
			free(str);
		}
	}
	return (0);
}
*/

/*
// New main for testing
// Only used to test pipes for now

int main()
{
	int i;
	int nb_cmds;
	pid_t pids[nb_cmds];
	int pipefds[nb_cmds - 1][2];

	i = 0;
	nb_cmds = 3;

	// Create pipes
	while (i < nb_cmds - 1)
	{
		if (pipe(pipefds[i] == -1))
			exit(EXIT_FAILURE);
		i++;
	}

	// Forking and executing commands
	i = 0;
	while (i)
	{
		// Fork
		pids[i] = fork();
		if (pids[i] == -1)
			exit(EXIT_FAILURE);
		
		// Child process
		if (pids[i] == 0)
		{
			if (i != 0)
			{
				// Redirect input from previous cmd
				dup2(pipefds[i - 1][0], STDIN_FILENO);
				close(pipefds[i - 1][0]);
				close(pipefds[i - 1][1]);
			}

			if (i != nb_cmds - 1)
			{
				// Redirect output to next cmd
				dup2(pipefds[i][1], STDOUT_FILENO);
				close(pipefds[i][0]);
				close(pipefds[i][1]);
			}

			// Execute command
			// ???
		}
		else // Parent process
		{
			// Close pipes
			int j = 0;
			while (j < nb_cmds - 1)
			{
				close(pipefds[j][0]);
				close(pipefds[j][1]);
				j++;
			}

			// Wait for child process to finish
			int status;
			waitpid(pids[i], &status, 0);
			if (WIFEXITED(status))
				printf("Child %d terminated with exit status %d\n", i, WEXITSTATUS(status));
			else
				printf("Child %d terminated abnormally\n", i);
		}
	}
}*/

void	init_minishell(t_minishell **minishell)
{
	t_minishell *m;

	m = malloc(sizeof(t_minishell));
	m->line = NULL;
	m->parse = NULL;
	m->env = NULL;
	m->nb_cmd = 0; // From parsing
	m->pids = malloc(sizeof(pid_t) * m->nb_cmd);
	m->fds = malloc(sizeof(int) * (m->nb_cmd - 1) * 2);
	*minishell = m;
}

/*int main()
{
	int 		i;
	t_minishell *ms;

	init_minishell(&ms);
	while (1)
	{
		ms->line = readline("minishell~");
		ms->parse = ms_parsing(ms->line);
		//ft_lstiter(ms->parse, ms_printlist);
		add_history(ms->line);
		if (ft_strncmp(ms->line, "exit", 4) == 0)
		{
			free(ms->line);
			break ;
		}
		else if (ft_strncmp(ms->line, "export", 6) == 0)
			ms_export(clean_command("export", ms->line), &(ms->env));
		else if (ft_strncmp(ms->line, "unset", 5) == 0)
			ms_unset(clean_command("unset", ms->line), &(ms->env));
		else if (ft_strncmp(ms->line, "env", 3) == 0)
			ms_env((ms->env));
		else if (ft_strncmp(ms->line, "pwd", 3) == 0)
			ms_pwd();
		else if (ft_strncmp(ms->line, "cd", 2) == 0)
			ms_cd(ms->line);
		else if (ft_strncmp(ms->line, "echo", 4) == 0)
			ms_echo(clean_command("echo", ms->line), !hasFlag(ms->line, "-n"));
		else
		{
			ft_printf("command not found :%s\n", ms->line);
			free(ms->line);
		}
	}

	return (0);
}*/

int main()
{
	int 		i;
	t_minishell *ms;

	init_minishell(&ms);
	while (1)
	{
		ms->line = readline("minishell~");
		ms->parse = ms_parsing(ms->line);
		add_history(ms->line);
		if (strstr(ms->line, ">"))
		{
			ft_printf("> found\n");
			ms_redir_out(ms->line);
		}
		else if (strstr(ms->line, "<"))
		{
			ft_printf("< found\n");
			ms_redir_in(ms->line);
		}
		else
		{
			ft_printf("command not found :%s\n", ms->line);
			free(ms->line);
		}
	}

	return (0);
}