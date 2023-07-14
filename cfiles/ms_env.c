/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 21:19:42 by aramon            #+#    #+#             */
/*   Updated: 2023/07/13 18:54:07 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hfiles/minishell.h"

void    ms_env(t_env *env)
{
    t_env   *tmp;

    tmp = env;
    while (tmp)
    {
        ft_printf("%s=%s\n", tmp->name, tmp->content);
        tmp = tmp->next;
    }
    free(tmp);
}