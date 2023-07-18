/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:45:36 by aramon            #+#    #+#             */
/*   Updated: 2023/07/18 15:34:29 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int check_to_export(char *to_export)
{
    int i;

    i = 0;
    while (to_export[i])
    {
        if (to_export[i] == '=')
        {
            if (to_export[i - 1] == ' ')
            {
                ft_printf("-bash: export: `=': not a valid identifier\n");
                return (0);
            }
        }
        i++;
    }
    return (1);
}

int     get_total_var_to_export(char *to_export)
{
    int     i;
    int     total;

    i = 0;
    total = 0;
    while (to_export[i])
    {
        if (to_export[i] == '=')
            total++;
        i++;
    }
    return (total);
}

void check_var_already_present(t_env **env, char **split)
{
    t_env   *tmp;

    tmp = *env;
    while (tmp)
    {
        if (ft_strncmp(tmp->name, split[0], ft_strlen(tmp->name)) == 0)
        {
            tmp->content = split[1];
            return ;
        }
        tmp = tmp->next;
    }
    env_add_back(env, env_new(split[0], split[1]));
    return ;
}

void    ms_export(char *to_export, t_env **env)
{
    int     total_var;
    int     curr_var;
    char    **first_export_split;
    char    **second_export_split;

    if (!check_to_export(to_export))
        return ;
    total_var = get_total_var_to_export(to_export);
    if (total_var == 0)
        return ;
    first_export_split = ft_split(to_export, ' ');
    curr_var = 0;
    while (curr_var < total_var)
    {
        second_export_split = ft_split(first_export_split[curr_var], '=');
        if (*env)
            check_var_already_present(env, second_export_split);
        else
            *env = env_new(second_export_split[0], second_export_split[1]);
        curr_var++;
    }
}
