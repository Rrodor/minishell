/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:32:49 by rrodor            #+#    #+#             */
/*   Updated: 2023/02/12 19:00:45 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!big && !len)
		return (0);
	if (!little[j])
		return ((char *)big);
	if (len + 1 == 0)
		len--;
	while (big[i] && len-- > 0)
	{
		j = 0;
		if (((unsigned char)big[i]) == ((unsigned char)little[j]))
		{
			while (((unsigned char)big[i + j]) == ((unsigned char)little[j])
				&& (len - j + 2) > 0 && big[i + j])
				j++;
			if ((len - j + 2) > 0 && j == (int)ft_strlen((char *)little))
				return ((char *)&big[i]);
		}
		i++;
	}
	return (0);
}

/*
#include <string.h>
#include <stdio.h>
int main()
{
	char l[30] = "aaabcabcd";
	//char b[] = "lu";

	printf("%s", ft_strnstr(l, "a", -1));
	return 0;
}*/
