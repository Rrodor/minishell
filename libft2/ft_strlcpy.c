/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:22:40 by rrodor            #+#    #+#             */
/*   Updated: 2023/02/04 13:59:24 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen((char *)src));
	while (i < (size - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (size > 0)
		dst[i] = 0;
	return (ft_strlen((char *)src));
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
	char dst[] = "salut";
	const char src[] = "hey";
	//char dst2[] = "salut";

	ft_strlcpy(dst, src, 0);
	//strlcpy(dst2, src, 4);
	printf("%s\n", dst);
	//printf("%ld\n", ft_strlcpy(dst, src, 0));
	return 0;
}*/
