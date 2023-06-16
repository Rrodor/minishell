/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:35:50 by rrodor            #+#    #+#             */
/*   Updated: 2023/02/12 16:35:35 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*scpy;

	scpy = ft_calloc(ft_strlen((char *)s) + 1, sizeof(char));
	if (!scpy)
		return (0);
	ft_strlcpy(scpy, s, ft_strlen((char *)s) + 1);
	return (scpy);
}
