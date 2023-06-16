/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:19:57 by rrodor            #+#    #+#             */
/*   Updated: 2023/02/03 14:37:36 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;

	str = s;
	while (n > 0)
	{
		*str = 0;
		str++;
		n--;
	}
}

/*
#include <stdio.h>
int main()
{
        char str[] = "salut_a_tous";
        printf("%s\n", str);
        ft_bzero(str, 3);
        printf("%s\n", str);
        return 0;
}*/
