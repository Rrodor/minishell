/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 14:10:47 by rrodor            #+#    #+#             */
/*   Updated: 2023/02/21 19:33:07 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	ls;
	size_t	ld;

	if ((!dst || !src) && !size)
		return (0);
	ls = ft_strlen((char *)src);
	ld = ft_strlen((char *)dst);
	i = 0;
	if (!size || (size < ld))
		return (ls + size);
	while (src[i] && (size - 1) > (ld + i))
	{
		dst[ld + i] = src[i];
		i++;
	}
	dst[ld + i] = 0;
	return (ls + ld);
}

/*
#include <stdio.h>
int main()
{
	char	dst[20] = "salut";
	char	src[] = "";
	size_t	l = 0;	

	l = ft_strlcat(dst, src, 8);
	printf("%ld %s", l, dst);
	return 0;
}*/
