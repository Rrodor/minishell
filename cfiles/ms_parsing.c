/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:12:14 by rrodor            #+#    #+#             */
/*   Updated: 2023/07/03 23:41:35 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*ms_parsing(char *str)
{
	t_list	*list;
	char	*line;

	list = NULL;
	line = ft_strtrim(str, " ");
	if (!ms_error(line))
		return (NULL);
	ft_printf("error\n");
	list = ms_firstsplit(line);
	return (list);
}

t_list	*ms_firstsplit(char *line)
{
	t_list	*list;
	char	*str;
	int		i;

	list = NULL;
	i = 0;
	str = NULL;
	while (line[i])
	{
		if (ft_strchr("\'\"|<>", line[i]))
		{
			if (line[i] == '"' || line[i] == '\'')
				str = ms_fsquote(line, &i, str, &list);
			else
				str = ms_fsspecial(line, &i, str, &list);
		}
		else
			str = ms_strjoinc(str, line[i++]);
	}
	ft_lstadd_back(&list, ft_lstnew(ft_strdup(str)));
	return (list);
}

char	*ms_fsquote(char *line, int *i, char *str, t_list **list)
{
	int		j;

	j = *i + 1;
	str = ms_strjoinc(str, line[*i]);
	while (line[j] && line[j] != line[*i])
	{
		str = ms_strjoinc(str, line[j]);
		j++;
	}
	str = ms_strjoinc(str, line[j]);
	*i = j + 1;
	return (str);
}

char	*ms_fsspecial(char *line, int *i, char *str, t_list **list)
{
	int		j;

	j = *i;
	ft_lstadd_back(list, ft_lstnew(str));
	str = NULL;
	if (line[j + 1] == line[j])
	{
		ft_lstadd_back(list, ft_lstnew(ft_substr(line, j, 2)));
		j++;
	}
	else
		ft_lstadd_back(list, ft_lstnew(ft_substr(line, j, 1)));
	j++;
	*i = j;
	return (str);
}

/*t_list	*ms_listsplit(t_list *oldlist)
{
	t_list	*list;
	char	**tab;

	list = NULL;
	while (oldlist)
	{

		if (oldlist->content == '|')
			ft_lstadd_back(list, ft_lstnew(ft_strdup("|")));
		else
		{
			tab = ft_split(oldlist->content, ' ');
			ft_lstadd_back(&list, ft_lstnew(ft_strdup(oldlist->content)));
		}
		oldlist = oldlist->next;
	}
	return (list);
}*/
