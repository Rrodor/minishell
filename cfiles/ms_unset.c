/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 21:37:01 by aramon            #+#    #+#             */
/*   Updated: 2023/07/13 18:53:54 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hfiles/minishell.h"

void ms_unset(const char *var_name, t_env **all)
{
    t_env *current;
    t_env *prev;

    current = *all;
    prev = NULL;
    while (current != NULL)
    {
        if (strcmp(current->name, var_name) == 0)
        {
            if (prev == NULL)
                *all = current->next;
            else
                prev->next = current->next;
            free(current->name);
            free(current->content);
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}