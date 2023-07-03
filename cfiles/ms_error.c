/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:58:07 by rrodor            #+#    #+#             */
/*   Updated: 2023/07/03 23:41:12 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ms_error(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i] == ' ')
		i++;
	if (!line[i])
		return (0);
	if (line[i] == '|')
	{
		ft_printf("error pipe doesn't have argument\n");
		return (0);
	}
	if (line[i] == '<' || line[i] == '>')
	{
		ft_printf("error redir doesn't have argument\n");
		return (0);
	}
	if (!ms_error2(line, 0))
		return (0);
	return (1);
}

int	ms_error2(char *line, int i)
{
	while (line[i])
	{
		if (line [i] == '\'' || line[i] == '"')
		{
			if (!ms_errorquote(line, &i))
				return (0);
		}
		else if (line[i] == '|')
		{
			if (!ms_errorpipe(line, &i))
				return (0);
		}
		else if (line[i] == '<' || line[i] == '>')
		{
			if (!ms_errorredir(line, &i))
				return (0);
		}
		else
			i++;
	}
	return (1);
}

int	ms_errorquote(char *line, int *i)
{
	char	c;

	c = line[*i];
	(*i)++;
	while (line[*i])
	{
		if (line[*i] == c)
		{
			(*i)++;
			return (1);
		}
		(*i)++;
	}
	if (c == '\'')
		ft_printf("error simple quote is open\n");
	else
		ft_printf("error double quote is open\n");
	return (0);
}

int	ms_errorpipe(char *line, int *i)
{
	(*i)++;
	while (line[*i] == ' ')
		(*i)++;
	if (!line[*i] || line[*i] == '|' || line[*i] == '<' || line[*i] == '>')
	{
		ft_printf("error pipe doesn't have argument\n");
		return (0);
	}
	return (1);
}

int	ms_errorredir(char *line, int *i)
{
	char	c;

	c = line[(*i)];
	(*i)++;
	if (line[*i] == c)
		(*i)++;
	while (line[*i] == ' ')
		(*i)++;
	if (!line[*i] || line[*i] == '|' || line[*i] == '<' || line[*i] == '>')
	{
		ft_printf("error redir doesn't have argument\n");
		return (0);
	}
	return (1);
}
