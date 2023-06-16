/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:26:23 by rrodor            #+#    #+#             */
/*   Updated: 2023/02/10 22:28:41 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/*
#include <stdio.h>
int	main()
{
	t_list *test = 0;
	t_list *test2 = 0;
	t_list *test3 = 0;
	int	i = 1;
	int	j = 2;
	int	k = 3;

	test = ft_lstnew((void *)&i);
	test2 = ft_lstnew((void *)&j);
	test3 = ft_lstnew((void *)&k);
	ft_lstadd_front(&test, test2);
	ft_lstadd_front(&test2, test3);
	printf("%d", *((int *)(ft_lstlast(test3)->content)));
	return (0);
}*/
