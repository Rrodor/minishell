/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:13:44 by rrodor            #+#    #+#             */
/*   Updated: 2023/07/25 20:15:56 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/wait.h>

# include "../libft2/libft.h"
# include "../libft2/get_next_line.h"

typedef struct 	s_tools t_tools;
typedef struct 	s_cmd t_cmd;
typedef struct 	s_lexer t_lexer;
typedef struct 	s_parser t_parser;

# include "builtins.h"
# include "command.h"
# include "error.h"
# include "parser_lexer.h"
# include "expander.h"
# include "executor.h"
# include "utils.h"
# include "signal.h"
# include "global.h"

//minishell.c
int             ms_loop(t_tools *tools);
int             reset_tools(t_tools *tools);
int				implement_tools(t_tools *tools);

//signal.c
void			init_signals(void);
void			sigquit_handler(int sig);
void			sigint_handler(int sig);

#endif
