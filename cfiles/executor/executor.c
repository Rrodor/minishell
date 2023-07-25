#include "minishell.h"

t_cmd	*call_expander(t_tools *tools, t_cmd *cmd)
{
	t_lexer	*start;

	cmd->str = expander(tools, cmd->str);
	start = cmd->redirs;
	while (cmd->redirs)
	{
		if (cmd->redirs->token != LESS_LESS)
			cmd->redirs->str = expander_str(tools, cmd->redirs->str);
		cmd->redirs = cmd->redirs->next;
	}
	cmd->redirs = start;
	return (cmd);
}

int	pipe_wait(int *pid, int amount)
{
	int	i;
	int	status;

	i = 0;
	while (i < amount)
	{
		waitpid(pid[i], &status, 0);
		i++;
	}
	waitpid(pid[i], &status, 0);
	if (WIFEXITED(status))
		g_global.error_num = WEXITSTATUS(status);
	return (EXIT_SUCCESS);
}

int	ft_fork(t_tools *tools, int end[2], int fd_in, t_cmd *cmd)
{
	static int	i = 0;

	if (tools->reset == 1)
	{
		i = 0;
		tools->reset = 0;
	}
	tools->pid[i] = fork();
	if (tools->pid[i] < 0)
		ft_error(5, tools);
	if (tools->pid[i] == 0)
		dup_cmd(cmd, tools, end, fd_in);
	i++;
	return (EXIT_SUCCESS);
}

int	check_fd_heredoc(t_tools *tools, int end[2], t_cmd *cmd)
{
	int	fd_in;

	if (tools->heredoc)
	{
		close(end[0]);
		fd_in = open(cmd->hd_file_name, O_RDONLY);
	}
	else
		fd_in = end[0];
	return (fd_in);
}

int	executor(t_tools *tools)
{
	int		end[2];
	int		fd_in;

	fd_in = STDIN_FILENO;
	while (tools->simple_cmds)
	{
		tools->simple_cmds = call_expander(tools, tools->simple_cmds);
		if (tools->simple_cmds->next)
			if (pipe(end) == -1)
				perror("pipe");
		send_heredoc(tools, tools->simple_cmds);
		ft_fork(tools, end, fd_in, tools->simple_cmds);
		close(end[1]);
		if (tools->simple_cmds->prev)
			close(fd_in);
		fd_in = check_fd_heredoc(tools, end, tools->simple_cmds);
		if (tools->simple_cmds->next)
			tools->simple_cmds = tools->simple_cmds->next;
		else
			break ;
	}
	pipe_wait(tools->pid, tools->pipes);
	tools->simple_cmds = cmd_first(tools->simple_cmds);
	return (0);
}