/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:22:06 by aramon            #+#    #+#             */
/*   Updated: 2023/07/13 18:53:51 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hfiles/minishell.h"

t_env   *env_new(char *var_name, char *var_content)
{
    t_env   *new;

    new = malloc(sizeof(t_env));
    if (!new)
        return (0);
    new->content = var_content;
    new->name = var_name;
    new->next = NULL;
    return (new);
}

t_env   *env_last(t_env *env)
{
    if (!env)
        return (NULL);
    while (env->next)
        env = env->next;
    return (env);
}

void    env_add_back(t_env **env, t_env *new)
{
    t_env   *last;

    if (!env)
        return ;
    if (!*env)
        (*env) = new;
    else
    {
        last = env_last(*env);
        last->next = new;
    }
}