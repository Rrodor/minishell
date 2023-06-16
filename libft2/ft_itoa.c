/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:58:38 by rrodor            #+#    #+#             */
/*   Updated: 2023/02/12 18:43:41 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_power(int x, int p)
{
	int	res;

	res = 1;
	if (!x)
		return (res);
	while (p > 0)
	{
		res *= x;
		p--;
	}
	return (res);
}

static int	ft_jaiplusdeplace(int *n, int l)
{
	int	x;

	x = *n;
	if (x < 999999999 && x > -999999999)
	{	
		while (x / ft_power(10, l))
			l++;
	}
	if (x < 0)
	{
		*n *= -1;
		l++;
	}
	return (l);
}

char	*ft_itoa(int n)
{
	int		l;
	char	*str;

	l = 1;
	if (!n)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n > 999999999 || n < -999999999)
		l = 10;
	l = ft_jaiplusdeplace(&n, l);
	str = malloc((l + 1) * sizeof(char));
	if (!str)
		return (0);
	str[l--] = 0;
	while (l > 0)
	{
		str[l--] = n % 10 + 48;
		n /= 10;
	}
	if (n == 0)
		str[0] = '-';
	else
		str[0] = n + 48;
	return (str);
}

/*
#include <stdio.h>
int main()
{
	printf("%s", ft_itoa(1954323550));
	return 0;
}*/
