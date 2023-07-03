/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parsing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:11:16 by rrodor            #+#    #+#             */
/*   Updated: 2023/07/03 19:33:22 by rrodor           ###   ########.fr       */
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
