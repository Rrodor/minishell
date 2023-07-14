/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 20:39:38 by aramon            #+#    #+#             */
/*   Updated: 2023/07/13 21:15:30 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hfiles/minishell.h"

void	ms_cd(char *str)
{
	int		i;
	int		j;
	char	*path;

	i = 2;
	j = 0;
	while (str[i] == ' ')
		i++;
	while (str[i + j] && str[i + j] != ' ')
		j++;
	path = malloc (sizeof(char) * (j + 1));
	j = 0;
	while (str[i + j] && str[i + j] != ' ')
	{
		path[j] = str[i + j];
		j++;
	}
	path[j] = 0;
	chdir(path);
}