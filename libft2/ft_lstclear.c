/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:04:13 by rrodor            #+#    #+#             */
/*   Updated: 2023/02/12 18:52:09 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*i;
	t_list	*j;

	if (!lst || !*lst || !del)
		return ;
	i = *lst;
	while (ft_lstsize(i) > 1)
	{
		j = i->next;
		i->next = j->next;
		ft_lstdelone(j, del);
	}
	ft_lstdelone(i, del);
	*lst = 0;
}

/*
int	main(int argc, char **argv)
{
	t_list a;
	t_list b;
	t_list c;

	int	test = 1;
	int	test2 = 2;
	a = ft_lstnew(&test);
	b = ft_lstnew(&test);
	c = ft_lstnew(&test);

	ft_lstadd_back(&a, b);
	return (0);
}*/
