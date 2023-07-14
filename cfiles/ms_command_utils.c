/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_command_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 21:42:12 by aramon            #+#    #+#             */
/*   Updated: 2023/07/13 19:42:31 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hfiles/minishell.h"

char *clean_command(char *keyword, char *command)
{
    int     i;
    int     k;
    int     command_len;
    char    *new;

    i = 0;
    k = ft_strlen(keyword);
    command_len = ft_strlen(command);
    if (command_len <= k)
        return (NULL);
    if (new == NULL)
        return (NULL);
    new = (char*)malloc(sizeof(char) * (command_len - k + 1));
    while (command[k + 1] != '\0')
    {
        new[i] = command[k + 1];
        i++;
        k++;
    }
    new[i] = '\0';
    return (new);
}