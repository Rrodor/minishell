
#include "minishell.h"

void	ms_pwd(void)
{
	char	*buf;
	int		i;

	i = 2;
	buf = malloc (20);
	buf = getcwd(buf, 20);
	while (!buf)
	{
		free(buf);
		buf = malloc (20 * i);
		buf = getcwd(buf, 20 * i);
		i++;
	}
	ft_printf("%s\n", buf);
	free (buf);
}

int main()
{
	char *str;

	while(1)
	{
		str = readline("minishell >> ");
		if (ft_strncmp(str, "exit", 4) == 0)
		{
			free(str);
			exit(0);
		}
		else if (ft_strncmp(str, "pwd", 3) == 0)
			ms_pwd();
		else if (ft_strncmp(str, "cd", 2) == 0)
	
		else
		{
			ft_printf("command not found :%s\n", str);
			free(str);
		}
	}
	return 0;
}
