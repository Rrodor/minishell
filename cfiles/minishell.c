/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:32:05 by rrodor            #+#    #+#             */
/*   Updated: 2023/07/04 11:58:53 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ms_printlist(void *s)
{
	char **str;
	int i;

	str = s;
	i = 0;
	while (str[i])
	{
		ft_printf("%s  ~  ", str[i]);
		i++;
	}
	ft_printf("\n");
}

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

void	ms_cd(char *str)
{
	int		i;
	int		j;
	char	*path;

	i = 2;
	j = 0;
	while (str[i] == ' ')
		i++;
	while (str[i + j] && str[i + j] != ' ')
		j++;
	path = malloc (sizeof(char) * (j + 1));
	j = 0;
	while (str[i + j] && str[i + j] != ' ')
	{
		path[j] = str[i + j];
		j++;
	}
	path[j] = 0;
	chdir(path);
}

int	main()
{
	char	*str;
	t_list	*list;
	int		i;
	int		**tab;

	while (1)
	{
		str = readline("minishell >> ");
		list = ms_parsing(str);
		ft_lstiter(list, ms_printlist);
		add_history(str);/*
		if (ft_strncmp(str, "exit", 4) == 0)
		{
			free(str);
			exit(0);
		}
		else if (ft_strncmp(str, "pwd", 3) == 0)
			ms_pwd();
		else if (ft_strncmp(str, "cd", 2) == 0)
			ms_cd(str);
		else
		{
			ft_printf("command not found :%s\n", str);
			free(str);
		}*/
	}
	return (0);
}
