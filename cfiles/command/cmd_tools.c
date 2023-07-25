/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 01:16:01 by rrodor            #+#    #+#             */
/*   Updated: 2023/07/26 01:16:02 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*cmd_new(char **str, int n_redir, t_lexer *redirs)
{
	t_cmd	*new;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new)
		return (0);
	new->str = str;
	new->builtin = builtin_arr(str[0]);
	new->hd_file_name = NULL;
	new->n_redirs = n_redir;
	new->redirs = redirs;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	cmd_add_back(t_cmd **lst, t_cmd *new)
{
	t_cmd	*tmp;

	tmp = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

void	cmd_rm_first(t_cmd **lst)
{
	t_cmd   *tmp;

	if (!*lst)
		return ;
	tmp = (*lst)->next;
	lexer_clear(&(*lst)->redirs);
	free(*lst);
	*lst = tmp;
}

void	cmd_clear(t_cmd **lst)
{
	t_cmd   *tmp;
	t_lexer *redirections_tmp;

	if (!*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		redirections_tmp = (*lst)->redirs;
		lexer_clear(&redirections_tmp);
		if ((*lst)->str)
			free_arr((*lst)->str);
		if ((*lst)->hd_file_name)
			free((*lst)->hd_file_name);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

t_cmd	*cmd_first(t_cmd *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (NULL);
	while (lst->prev != NULL)
	{
		lst = lst->prev;
		i++;
	}
	return (lst);
}
