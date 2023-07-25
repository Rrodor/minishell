#include "minishell.h"

char	*ms_getname(char **envp)
{
	char	*name;
	int		i;

	i = 0;
	if (!envp || !envp[0])
		return (readline("Enter a Username :"));
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "USER=", 5) == 0)
		{
			name = ft_strdup(envp[i] + 5);
			return (name);
		}
		i++;
	}
	return (ft_strdup("User"));
}

char	*ms_getuser(char **envp)
{
	char	*name;

	name = ms_getname(envp);
	name = ft_strjoin(name, "@minishell$~");
	return (name);
}
