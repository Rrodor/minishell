/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_dollar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:07:21 by rrodor            #+#    #+#             */
/*   Updated: 2023/07/18 18:49:29 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ms_dollarquote(char *str, char **env)
{
	int		i;
	int		j;
	int		k;
	char	*tmp;
	char	*line;

	i = 0;
	j = 0;
	line = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!line)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '$')
		{
			tmp = ms_splitdollar(str, &i, env);
			k = 0;
			while (tmp[k])
				line[j++] = tmp[k++];
			free(tmp);
		}
		else
			line[j++] = str[i++];
	}
	line[j] = '\0';
	return (line);
}

char	*ms_getenvvar(char *var, char **env)
{
	int		i;
	int		j;

	i = 0;
	while (env[i])
	{
		j = 0;
		if (ft_strncmp(env[i], var, ft_strlen(var)) == 0)
		{
			while (env[i][j] != '=')
				j++;
			j++;
			return (ft_strdup(env[i] + j));
		}
		i++;
	}
	return (ft_strdup(""));
}

char	*ms_splitdollar(char	*str, int *i, char **env)
{
	char	*line;
	int		k;
	char	*tmp;

	k = *i + 1;
	while (str[k] && str[k] != ' ' && str[k] != '$')
		k++;
	line = malloc(sizeof(char) * (k - *i + 1));
	if (!line)
		return (NULL);
	k = 0;
	*i = *i + 1;
	while (str[*i] && str[*i] != ' ' && str[*i] != '$')
	{
		line[k] = str[*i];
		k++;
		*i = *i + 1;
	}
	line[k] = '\0';
	tmp = ms_getenvvar(line, env);
	free(line);
	line = ft_strdup(tmp);
	free(tmp);
	return (line);
}


