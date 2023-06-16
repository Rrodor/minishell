/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:47:52 by rrodor            #+#    #+#             */
/*   Updated: 2023/02/12 18:56:44 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	if (!dest && !src)
		return (NULL);
	d = dest;
	s = (void *)src;
	if (s < d)
	{
		while (n > 0)
		{
			d[n - 1] = s[n - 1];
			n--;
		}
	}
	else
		dest = ft_memcpy(dest, src, n);
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
	//char	stratos[] = "stratos";
	char	bongamin[] = "bongamin";
	char	bongamin2[] = "bongamin";
	
	printf("%s\n", (char *)ft_memmove(bongamin, &bongamin[3], 4));
	printf("%s", (char *)memmove(bongamin2, &bongamin2[3], 4));
	return 0;
}*/
