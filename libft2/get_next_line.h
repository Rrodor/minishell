/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:14:37 by rrodor            #+#    #+#             */
/*   Updated: 2023/07/18 14:44:44 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
# endif

char	*get_next_line(int fd);
char	*gnl_line(char *str);
char	*gnl_strjoin(char *s1, char *s2);
size_t	gnl_strlen(char *str);
char	*gnl_strcat(char *dst, const char *src);
char	*gnl_prepstr(char *str, int i);
char	*gnl_strdup(char *str);
int		gnl_strchr(char *str, char c);
char	*gnl_buffinfline(int fd, int l, char *str, char *buf);

#endif
