/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printcspdi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:43:09 by rrodor            #+#    #+#             */
/*   Updated: 2023/03/09 15:52:14 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printc(va_list argptr, int l)
{
	int		n;

	n = va_arg(argptr, int);
	l++;
	ft_putchar(n);
	return (l);
}

int	ft_prints(va_list argptr, int l)
{
	char	*str;

	str = va_arg(argptr, char *);
	if (!str)
	{
		ft_putstr("(null)");
		return (l + 6);
	}
	l += ft_strlen(str);
	ft_putstr(str);
	return (l);
}

int	ft_printp(va_list argptr, int l)
{
	unsigned long long int	n;

	n = (unsigned long long int)va_arg(argptr, void *);
	if (n == 0)
	{
		ft_putstr("(nil)");
		return (l + 5);
	}
	write (1, "0x", 2);
	l += 2;
	l = ft_putnbr_base(n, l, "0123456789abcdef");
	return (l);
}

int	ft_printd(va_list argptr, int l)
{
	int	n;

	n = va_arg(argptr, int);
	if (n == 0)
	{
		ft_putchar('0');
		return (l + 1);
	}
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return (l + 11);
	}
	l = ft_putnbr(n, l, "0123456789");
	return (l);
}
