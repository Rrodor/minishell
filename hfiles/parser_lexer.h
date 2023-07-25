/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_lexer.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 01:13:34 by rrodor            #+#    #+#             */
/*   Updated: 2023/07/26 01:24:07 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_LEXER_H
# define PARSER_LEXER_H
# include "minishell.h"

# define PIPE 1
# define GREAT 2
# define GREAT_GREAT 3
# define LESS 4
# define LESS_LESS 5

typedef struct s_lexer
{
	char			*str;
	int				token;
	int				i;
	struct s_lexer	*next;
	struct s_lexer	*prev;
}					t_lexer;

typedef struct s_parser
{
	t_lexer			*lexer_list;
	t_lexer			*redirections;
	int				num_redirections;
	struct s_tools	*tools;
}					t_parser;

typedef struct s_tools
{
	char			*args;
	char			**paths;
	char			**envp;
	struct s_cmd	*simple_cmds;
	t_lexer			*lexer_list;
	char			*pwd;
	char			*old_pwd;
	int				pipes;
	int				*pid;
	int				heredoc;
	int				reset;
	char			*name;
}					t_tools;

typedef struct s_cmd
{
	char			**str;
	int				(*builtin)(t_tools *, struct s_cmd *);
	int				n_redirs;
	char			*hd_file_name;
	t_lexer			*redirs;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}					t_cmd;

void				lexer_add_back(t_lexer **lst, t_lexer *new);
t_lexer				*lexer_new(char *str, int token);
t_lexer				*lexer_clear_one(t_lexer **lst);
void				lexer_del_first(t_lexer **lst);
void				lexer_del_one(t_lexer **lst, int key);
void				lexer_clear(t_lexer **lst);

//parser
int					parser(t_tools *tools);

//parser_utils
t_parser			init_parser_tools(t_lexer *lexer_list, t_tools *tools);
void				count_pipes(t_lexer *lexer_list, t_tools *tools);
int					count_args(t_lexer *lexer_list);
t_lexer				*find_next_cmd(t_lexer *lexer_lst);

//handle_redirections
int					add_new_redirection(t_lexer *tmp, t_parser *parser_tools);
int					handle_heredoc(t_parser *parser_tools, t_lexer *tmp);
void				rm_redirections(t_parser *parser_tools);

//Parse envp
int					find_pwd(t_tools *tools);
int					parse_envp(t_tools *tools);

//Reader
int					check_token(int c);
int					add_node(char *str, int token, t_lexer **lexer_list);
int					token_reader(t_tools *tools);

//quotes
int					handle_quotes(int i, char *str, char del);

//token
int					handle_token(char *str, int i, t_lexer **lexer_list);

#endif
