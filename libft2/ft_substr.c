/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 14:59:59 by rrodor            #+#    #+#             */
/*   Updated: 2023/02/12 18:08:03 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	llen;

	i = 0;
	if (!s)
		return (0);
	if (start >= ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	llen = ft_strlen(s + start);
	if (len < llen)
		llen = len;
	str = (char *)ft_calloc(llen + 1, sizeof(char));
	if (!str)
		return (0);
	i = -1;
	while (++i < llen)
		str[i] = s[i + start];
	return (str);
}
