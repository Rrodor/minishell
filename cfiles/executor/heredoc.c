/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 01:15:50 by rrodor            #+#    #+#             */
/*   Updated: 2023/07/26 01:49:25 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	create_heredoc(t_lexer *heredoc, int quotes, t_tools *tools, char *file_name)
{
	int		fd;
	char	*line;
	int		bytes_written;
	int		newline_written;

	fd = open(file_name, O_CREAT | O_RDWR | O_TRUNC, 0644);
	line = readline("Enter the content for the here document (press Ctrl+D to finish):\n");
	while (line && ft_strncmp(heredoc->str, line, ft_strlen(heredoc->str)) && !g_global.stop_heredoc)
	{
		if (quotes == 0)
			line = expander_str(tools, line);
		bytes_written = write(fd, line, ft_strlen(line));
		if (bytes_written == -1)
			perror("write");
		newline_written = write(fd, "\n", 1);
		if (newline_written == -1)
			perror("write");
		free(line);
		line = readline(NULL);
	}
	free(line);
	if (g_global.stop_heredoc || !line)
		return (EXIT_FAILURE);
	close(fd);
	return (EXIT_SUCCESS);
}

int	ft_heredoc(t_tools *tools, t_lexer *heredoc, char *file_name)
{
	int		quotes;
	int		sl;

	sl = EXIT_SUCCESS;
	if ((heredoc->str[0] == '\"'
			&& heredoc->str[ft_strlen(heredoc->str) - 1] == '\"')
		|| (heredoc->str[0] == '\''
			&& heredoc->str[ft_strlen(heredoc->str) - 1] == '\''))
		quotes = 1;
	else
		quotes = 0;
	delete_quotes(heredoc->str, '\"');
	delete_quotes(heredoc->str, '\'');
	g_global.stop_heredoc = 0;
	g_global.in_heredoc = 1;
	sl = create_heredoc(heredoc, quotes, tools, file_name);
	g_global.in_heredoc = 0;
	tools->heredoc = 1;
	return (sl);
}

char	*generate_heredoc_filename(void)
{
	static int	i = 0;
	char		*num;
	char		*file_name;

	num = ft_itoa(i++);
	file_name = ft_strjoin("build/.tmp_heredoc_file_", num);
	free(num);
	return (file_name);
}

int	send_heredoc(t_tools *tools, t_cmd *cmd)
{
	t_lexer	*start;
	int		sl;

	start = cmd->redirs;
	sl = EXIT_SUCCESS;
	while (cmd->redirs)
	{
		if (cmd->redirs->token == LESS_LESS)
		{
			if (cmd->hd_file_name)
				free(cmd->hd_file_name);
			cmd->hd_file_name = generate_heredoc_filename();
			sl = ft_heredoc(tools, cmd->redirs, cmd->hd_file_name);
			if (sl)
			{
				g_global.error_num = 1;
				return (reset_tools(tools));
			}
		}
		cmd->redirs = cmd->redirs->next;
	}
	cmd->redirs = start;
	return (EXIT_SUCCESS);
}
