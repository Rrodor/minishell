/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:14:14 by rrodor            #+#    #+#             */
/*   Updated: 2023/02/02 13:07:28 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((unsigned char *)s + i);
		n--;
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
int main()
{
	char str[] = "salut a tous";
	printf("%s\n", (char *)ft_memchr(str, 't', 8));
	return 0;
}
*/	
