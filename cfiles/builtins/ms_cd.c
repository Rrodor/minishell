/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 01:16:10 by rrodor            #+#    #+#             */
/*   Updated: 2023/07/26 01:16:11 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_path_ret(char *str, t_tools *tools)
{
	int	i;

	i = 0;
	while (tools->envp[i])
	{
		if (!ft_strncmp(tools->envp[i], str, ft_strlen(str)))
			return (ft_substr(tools->envp[i], ft_strlen(str),
					ft_strlen(tools->envp[i]) - ft_strlen(str)));
		i++;
	}
	return (NULL);
}

int	specific_path(t_tools *tools, char *str)
{
	char	*tmp;
	int		ret;

	tmp = find_path_ret(str, tools);
	ret = chdir(tmp);
	free(tmp);
	if (ret != 0)
	{
		str = ft_substr(str, 0, ft_strlen(str) - 1);
		ft_putstr_fd(str, STDERR_FILENO);
		free(str);
		ft_putendl_fd(" not set", STDERR_FILENO);
	}
	return (ret);
}

void	add_path_to_env(t_tools *tools)
{
	int		i;
	char	*tmp;

	i = 0;
	while (tools->envp[i])
	{
		if (!ft_strncmp(tools->envp[i], "PWD=", 4))
		{
			tmp = ft_strjoin("PWD=", tools->pwd);
			free(tools->envp[i]);
			tools->envp[i] = tmp;
		}
		else if (!ft_strncmp(tools->envp[i], "OLDPWD=", 7) && tools->old_pwd)
		{
			tmp = ft_strjoin("OLDPWD=", tools->old_pwd);
			free(tools->envp[i]);
			tools->envp[i] = tmp;
		}
		i++;
	}
}

int	ms_cd(t_tools *tools, t_cmd *cmd)
{
	int		ret;

	ret = 0;
	tools->pwd = ms_getpwd();
	if (!cmd->str[1])
		ret = specific_path(tools, "HOME=");
	else if (ft_strncmp(cmd->str[1], "-", 1) == 0)
		ret = specific_path(tools, "OLDPWD=");
	else
	{
		ft_printf("%s\n", cmd->str[1]);
		ret = chdir(cmd->str[1]);
		if (ret != 0)
		{
			ft_putstr_fd("minishell: ", STDERR_FILENO);
			ft_putstr_fd(cmd->str[1], STDERR_FILENO);
			perror(" ");
		}
		ft_printf("test\n");
	}
	if (ret != 0)
		return (EXIT_FAILURE);
	ft_printf("salut\n");
	change_path(tools);
	ft_printf("boss\n");
	add_path_to_env(tools);
	return (EXIT_SUCCESS);
}
