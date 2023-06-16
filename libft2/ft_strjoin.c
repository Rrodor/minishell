/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:18:28 by rrodor            #+#    #+#             */
/*   Updated: 2023/02/12 18:10:52 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	ls1;
	size_t	ls2;

	if (!s1 || !s2)
		return (0);
	ls1 = ft_strlen((char *)s1);
	ls2 = ft_strlen((char *)s2);
	str = ft_calloc(ls1 + ls2 + 1, sizeof(char));
	if (!str)
		return (0);
	ft_strlcat(str, s1, ls1 + 1);
	ft_strlcat(str, s2, ls1 + ls2 + 1);
	return (str);
}
