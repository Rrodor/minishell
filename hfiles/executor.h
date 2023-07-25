#ifndef EXECUTOR_H
# define EXECUTOR_H
# include "minishell.h"

int			check_redirections(t_cmd *cmd);
int			executor(t_tools *tools);
t_cmd       *call_expander(t_tools *tools, t_cmd *cmd);
int         pipe_wait(int *pid, int amount);
int			find_cmd(t_cmd *cmd, t_tools *tools);
void		handle_cmd(t_cmd *cmd, t_tools *tools);
void		dup_cmd(t_cmd *cmd, t_tools *tools, int end[2], int fd_in);
void		single_cmd(t_cmd *cmd, t_tools *tools);
int			send_heredoc(t_tools *tools, t_cmd *cmd);

#endif