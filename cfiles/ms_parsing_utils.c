/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parsing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:11:16 by rrodor            #+#    #+#             */
/*   Updated: 2023/07/18 18:07:41 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ms_strjoinc(char *str, char c)
{
	char	*line;

	if (!str && !c)
		return (NULL);
	if (!c)
		return (str);
	if (!str)
	{
		line = malloc(sizeof(char) * 2);
		if (!line)
			return (NULL);
		line[0] = c;
		line[1] = 0;
	}
	else
	{
		line = malloc(sizeof(char) * (ft_strlen(str) + 2));
		if (!line)
			return (NULL);
		ft_strlcpy(line, str, ft_strlen(str) + 1);
		line[ft_strlen(str)] = c;
		line[ft_strlen(str) + 1] = 0;
		free(str);
	}
	return (line);
}

char	**ms_tabdup(char **oldtab)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	while (oldtab[i])
		i++;
	tab = malloc(sizeof(int *) * (i + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (oldtab[i])
	{
		j = -1;
		tab[i] = malloc(sizeof(int) * (ft_strlen(oldtab[i]) + 1));
		if (!tab[i])
			return (NULL);
		while (++j < ft_strlen(oldtab[i]))
			tab[i][j] = oldtab[i][j];
		tab[i][j] = 0;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

char	**ms_strtotab(char *str)
{
	char	**tab;

	tab = malloc(sizeof(char *) * 2);
	if (!tab)
		return (NULL);
	tab[0] = ft_strdup(str);
	tab[1] = NULL;
	return (tab);
}

char	**ms_envvar(char **tab, char **env)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '$')
			{
				tmp = ms_check_path(tab[i], env);
				free(tab[i]);
				tab[i] = ft_strdup(tmp);
				free(tmp);
			}
			j++;
		}
		i++;
	}
	return (tab);
}
