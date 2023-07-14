/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 20:38:53 by aramon            #+#    #+#             */
/*   Updated: 2023/07/13 19:16:21 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hfiles/minishell.h"

void    ms_pwd(void)
{
    char    *buf;
    int     i;

    i = 2;
    buf = malloc (20);
    buf = getcwd(buf, 20);
    while (!buf)
    {
        free(buf);
        buf = malloc (20 * i);
        buf = getcwd(buf, 20 * i);
        i++;
    }
    ft_printf("%s\n", buf);
    free (buf);
}