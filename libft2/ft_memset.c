/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:38:18 by rrodor            #+#    #+#             */
/*   Updated: 2023/02/03 14:59:00 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*str;

	str = s;
	while (n > 0)
	{
		*str = c;
		str++;
		n--;
	}
	return (s);
}

/*
#include <stdio.h>
int main()
{
	char str[] = "salut_a_tous";
	printf("%s\n", str);
	ft_memset(str, 54, 3);
	printf("%s\n", str);
	return 0;
}*/
