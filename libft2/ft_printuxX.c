/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuxX.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:17:13 by rrodor            #+#    #+#             */
/*   Updated: 2023/03/09 15:55:38 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printu(va_list argptr, int l)
{
	unsigned int	n;

	n = va_arg(argptr, unsigned int);
	l = ft_putnbr_base(n, l, "0123456789");
	return (l);
}

int	ft_printx(va_list argptr, int l)
{
	unsigned int	n;

	n = va_arg(argptr, unsigned int);
	l = ft_putnbr_base(n, l, "0123456789abcdef");
	return (l);
}

int	ft_printxm(va_list argptr, int l)
{
	unsigned int	n;

	n = va_arg(argptr, unsigned int);
	l = ft_putnbr_base(n, l, "0123456789ABCDEF");
	return (l);
}
