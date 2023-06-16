/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:15:14 by rrodor            #+#    #+#             */
/*   Updated: 2023/03/09 15:56:25 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	ft_putnbr_base(unsigned long long int n, int l, char *base)
{
	int		lbase;
	char	str[32];
	int		i;

	i = 0;
	lbase = ft_strlen(base);
	if (n == 0)
	{
		ft_putchar(base[i]);
		return (l + 1);
	}
	while (n > 0)
	{
		str[i] = base[n % lbase];
		i++;
		n = n / lbase;
		l++;
	}
	while (--i >= 0)
		ft_putchar(str[i]);
	return (l);
}

int	ft_putnbr(int n, int l, char *base)
{
	char	str[12];
	int		i;

	i = 0;
	if (n < 0)
	{
		ft_putchar('-');
		l++;
		n *= -1;
	}
	while (n > 0)
	{
		str[i] = base[n % 10];
		i++;
		n = n / 10;
		l++;
	}
	while (--i >= 0)
		ft_putchar(str[i]);
	return (l);
}
