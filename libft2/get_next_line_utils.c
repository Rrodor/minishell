/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:01:12 by rrodor            #+#    #+#             */
/*   Updated: 2023/07/18 14:46:21 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include "get_next_line.h"

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (gnl_strdup(s2));
	if (!s2)
		return (s1);
	str = malloc((gnl_strlen(s1) + BUFFER_SIZE + 1) * sizeof(char));
	str[0] = 0;
	if (!str)
		return (0);
	gnl_strcat(str, s1);
	gnl_strcat(str, s2);
	free(s1);
	return (str);
}

char	*gnl_strdup(char	*str)
{
	char	*ret;

	if (!str)
		return (NULL);
	ret = malloc ((gnl_strlen(str) + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	ret[0] = 0;
	gnl_strcat(ret, str);
	return (ret);
}

size_t	gnl_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*gnl_strcat(char *dst, const char *src)
{
	size_t	i;
	size_t	ld;

	i = 0;
	ld = 0;
	if (!dst && !src)
		return (0);
	if (dst[0])
		ld = gnl_strlen(dst);
	while (src[i])
	{
		dst[ld + i] = src[i];
		i++;
	}
	dst[ld + i] = 0;
	return (dst);
}

int	gnl_strchr(char *str, char c)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			x = 1;
		i++;
	}
	return (x);
}
