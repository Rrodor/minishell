/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:48:32 by rrodor            #+#    #+#             */
/*   Updated: 2023/02/09 23:09:42 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen((char *)s);
	if (c == 0)
		return (&((char *)s)[i]);
	while (((unsigned char)s[i]) != ((unsigned char)c) && i)
		i--;
	if (((unsigned char)s[i]) == (unsigned char)c)
		return (&((char *)s)[i]);
	return (0);
}

/*
#include <stdio.h>
int main()
{
	char *str = "hello";

	printf("%s", ft_strrchr(str, 'g'));
	return 0;
}*/
