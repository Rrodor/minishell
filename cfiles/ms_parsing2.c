/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parsing2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:13:52 by rrodor            #+#    #+#             */
/*   Updated: 2023/07/18 18:28:33 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ms_numword2(char *str, int i)
{
	char	c;

	c = str[i];
	i++;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

int	ms_numword(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != ' ')
		{
			if (str[i] == '"' || str[i] == '\'')
				i = ms_numword2(str, i);
			count++;
			while (str[i] && str[i] != ' ')
				i++;
		}
		else
			i++;
	}
	return (count);
}

char	*ms_splitword(char *str, int *i, int *j)
{
	char	*line;
	int		k;

	k = *i;
	while (str[k] && str[k] != ' ' && str[k] != '"' && str[k] != '\'')
		k++;
	line = malloc(sizeof(char) * (k - *i + 1));
	if (!line)
		return (NULL);
	k = 0;
	while (str[*i] && str[*i] != ' ' && str[*i] != '"' && str[*i] != '\'')
	{
		line[k] = str[*i];
		k++;
		*i = *i + 1;
	}
	line[k] = '\0';
	(*j)++;
	return (line);
}

char	*ms_splitquote(char	*str, int *i, int *j, char **env)
{
	char	*line;
	int		k;
	char	c;

	c = str[*i];
	*i = *i + 1;
	k = *i;
	while (str[k] && str[k] != c)
		k++;
	line = malloc(sizeof(char) * (k - *i + 1));
	if (!line)
		return (NULL);
	k = 0;
	while (str[*i] && str[*i] != c)
	{
		line[k] = str[*i];
		k++;
		*i = *i + 1;
	}
	line[k] = '\0';
	(*i)++;
	(*j)++;
	if (c == '"')
		line = ms_dollarquote(line, env);
	return (line);
}

char	**ms_split2(char *str, char	**env)
{
	char	**tab;
	int		i;
	char	c;
	int		j;

	i = 0;
	j = 0;
	tab = malloc(sizeof(char *) * ms_numword(str));
	if (!tab)
		return (NULL);
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] == '$')
			tab[j++] = ms_splitdollar(str, &i, env);
		else if (str[i] == '"' || str[i] == '\'')
			tab[j] = ms_splitquote(str, &i, &j, env);
		else if (str[i] != ' ')
			tab[j] = ms_splitword(str, &i, &j);
		while (str[i] && str[i] == ' ')
			i++;
	}
	tab[j] = NULL;
	return (tab);
}
