/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:42:12 by aramon            #+#    #+#             */
/*   Updated: 2023/07/17 18:08:36 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hfiles/minishell.h"

// echo "Banana" -n (Shouldn't work)
// Needs to be fixed <- Should check only after the command echo and not after
int hasFlag(char *str, char *flag)
{
    if (strstr(str, flag) != NULL)
        return 1;
    return 0;
}

// Print only strings between quotes
void    ms_echo(char *str, int new_line)
{
    int     i;

    i = 0;
    while (str[i])
    {
        if (str[i] == '\"')
        {
            i++;
            while (str[i] != '\"')
            {
                ft_putchar(str[i]);
                i++;
            }
        }
        i++;
    }
    if (new_line == 1)
        ft_putchar('\n');
}
