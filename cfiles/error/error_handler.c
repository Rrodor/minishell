/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 01:15:54 by rrodor            #+#    #+#             */
/*   Updated: 2023/07/26 01:38:26 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parser_error(int error, t_tools *tools, t_lexer *lexer_list)
{
	lexer_clear(&lexer_list);
	ft_error(error, tools);
}

int	parser_double_token_error(t_tools *tools, t_lexer *lexer_list,
	int token)
{
	ft_putstr_fd("minishell: syntax error near unexpected token ",
		STDERR_FILENO);
	if (token == GREAT)
		ft_putstr_fd("'>'\n", STDERR_FILENO);
	else if (token == GREAT_GREAT)
		ft_putstr_fd("'>>'\n", STDERR_FILENO);
	else if (token == LESS)
		ft_putstr_fd("'<'\n", STDERR_FILENO);
	else if (token == LESS_LESS)
		ft_putstr_fd("'<<'\n", STDERR_FILENO);
	else if (token == PIPE)
		ft_putstr_fd("'|'\n", STDERR_FILENO);
	else
		ft_putstr_fd("\n", STDERR_FILENO);
	lexer_clear(&lexer_list);
	reset_tools(tools);
	return (EXIT_FAILURE);
}

int	export_error(char *c)
{
	ft_putstr_fd("minishell: export: ", STDERR_FILENO);
	if (c)
	{
		ft_putchar_fd('\'', STDERR_FILENO);
		ft_putstr_fd(c, STDERR_FILENO);
		ft_putstr_fd("\': is ", STDERR_FILENO);
	}
	ft_putendl_fd("not a valid identifier", STDERR_FILENO);
	return (EXIT_FAILURE);
}

void	lexer_error(int error, t_tools *tools)
{
	lexer_clear(&tools->lexer_list);
	ft_error(error, tools);
}

int	cmd_not_found(char *str)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd(": command not found\n", STDERR_FILENO);
	return (127);
}

int	ft_error(int error, t_tools *tools)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	if (error == 0)
		ft_putstr_fd("syntax error near unexpected token 'newline'\n",
			STDERR_FILENO);
	else if (error == 1)
		ft_putstr_fd("memory error: unable to assign memory\n", STDERR_FILENO);
	else if (error == 2)
		ft_putstr_fd("syntax error: unable to locate closing quotation\n",
			STDERR_FILENO);
	else if (error == 3)
		ft_putstr_fd("Parser problem\n", STDERR_FILENO);
	else if (error == 4)
		ft_putstr_fd("Failed to create pipe\n", STDERR_FILENO);
	else if (error == 5)
		ft_putstr_fd("Failed to fork\n", STDERR_FILENO);
	else if (error == 6)
		ft_putstr_fd("outfile: Error\n", STDERR_FILENO);
	else if (error == 7)
		ft_putstr_fd("infile: No such file or directory\n", STDERR_FILENO);
	else if (error == 8)
		ft_putendl_fd("Path does not exist", STDERR_FILENO);
	reset_tools(tools);
	return (EXIT_FAILURE);
}
