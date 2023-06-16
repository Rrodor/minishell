/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:36:38 by rrodor            #+#    #+#             */
/*   Updated: 2023/02/12 18:57:42 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		l;
	int		i;
	int		j;

	if (!s1)
		return (0);
	j = 0;
	l = (int)ft_strlen((char *)s1);
	i = l;
	while (ft_strchr(set, s1[i-- - 1]))
		l--;
	i = -1;
	while (ft_strchr(set, s1[++i]))
		l--;
	if (l < 0)
		l = 0;
	str = malloc ((l + 1) * sizeof(char));
	if (!str)
		return (0);
	while (j < l)
		str[j++] = s1[i++];
	str[j] = 0;
	return (str);
}

/*
#include <stdio.h>
int main()
{
	char	s1[] = "";
	char	set[] = "abc";

	printf("%s", ft_strtrim(s1, set));
	return (0);
}*/
