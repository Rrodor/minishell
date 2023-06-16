/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:40:20 by rrodor            #+#    #+#             */
/*   Updated: 2023/02/09 22:53:06 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (((unsigned char)s[i]) != (unsigned char)c && s[i])
		i++;
	if (s[i])
		return (&((char *)s)[i]);
	if (c == 0)
		return (&((char *)s)[ft_strlen(s)]);
	return (0);
}
