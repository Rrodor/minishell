/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:32:27 by rrodor            #+#    #+#             */
/*   Updated: 2023/02/08 15:02:30 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*res;

	if (size == 0 || nmemb == 0)
		return (malloc(0));
	if (((size * nmemb) / size) != nmemb)
		return (0);
	res = malloc(nmemb * size);
	if (!res)
		return (0);
	ft_bzero(res, nmemb * size);
	return ((void *)res);
}

/*
#include <unistd.h>
int main()
{
	char	*test;
	int	i = 0;

	test = (char *)ft_calloc(8, sizeof(char));
	if (!test)
	{
		write(1, "erreur", 6);
		return 0;
	}
	test[0] = 'S';
	test[1] = 't';
	test[2] = 'r';
	test[3] = 'a';
	test[4] = 't';
	test[5] = 'o';
	test[6] = 's';
	while (test[i])
	{
		write(1, &test[i], 1);
		i++;
	}
	return (0);
}*/
