#include "minishell.h"

int	ms_env(t_tools *tools, t_cmd *cmd)
{
	int i;

	i = 0;
    (void) cmd;
	while (tools->envp[i])
	{
		ft_putendl_fd(tools->envp[i], STDOUT_FILENO);
		i++;
	}
	return (EXIT_SUCCESS);
}