/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:43:36 by rrodor            #+#    #+#             */
/*   Updated: 2023/02/12 18:31:49 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	str = (char *)ft_calloc(1 + ft_strlen((char *)s), sizeof(char));
	if (!str)
		return (0);
	while (s[i])
	{
		str[i] = f((unsigned int)i, s[i]);
		i++;
	}
	str[i] = 0;
	return (str);
}

/*
char	test(unsigned int i, char c)
{
	c += i;
	return (c);
}


#include <stdio.h>
int main()
{
	printf("%s", ft_strmapi("11111", (*test)));
	return 0;
}*/
