#include "minishell.h"

t_global g_global;

int	main(int argc, char **argv, char **envp)
{
	t_tools	tools;

	if (argc != 1 || argv[1])
	{
		printf("This program does not accept arguments\n");
		exit(0);
	}
	tools.envp = dup_arr(envp);
	find_pwd(&tools);
	implement_tools(&tools);
	ms_loop(&tools);
	return (0);
}