/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:13:44 by rrodor            #+#    #+#             */
/*   Updated: 2023/07/16 19:26:21 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include "../libft2/libft.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct 		s_minishell t_minishell;

typedef struct 		s_env
{
	char			*name;
	char			*content;
	struct s_env	*next;
}					t_env;

typedef struct 		s_minishell
{
	char			*line; // User input
	int				nb_cmd;	// Number of commands
	char			**env; // Environment variables
	pid_t			*pids; // Process ID
	int				*fds; // File descriptors
	t_list			*parse; // parsing result
}					t_minishell;

// ms_parsing.c
t_list	*ms_parsing(char *line);
t_list	*ms_pipesplit(char *line);
t_list	*ms_firstsplit(char *line);
char	*ms_fsquote(char *line, int *i, char *str, t_list **list);
char	*ms_fsspecial(char *line, int *i, char *str, t_list **list);
t_list	*ms_listsplit(t_list *oldlist);

// ms_parsing2.c
char	**ms_split2(char *str);
char	*ms_splitquote(char	*str, int *i, int *j);
char	*ms_splitredir(char *str, int *i, int *j);
int		ms_numword(char *str);
int		ms_numword2(char *str, int i);

// ms_parsing_utils.c
char	*ms_strjoinc(char *str, char c);
char	**ms_tabdup(char **oldtab);
char	**ms_strtotab(char *str);

// error.c
int		ms_error(char *line);
int		ms_error2(char *line, int i);
int		ms_errorpipe(char *line, int *i);
int		ms_errorquote(char *line, int *i);
int		ms_errorredir(char *line, int *i);

// ms_export.c
void	ms_export(char *str, t_env **env);

// ms_env_utils.c
t_env	*env_new(char *var_name, char *var_content);
t_env	*env_last(t_env *env);
void	env_add_back(t_env **env, t_env *new);
char	*clean_export_command(char *command);

// ms_pwd.c
void	ms_pwd(void);

// ms_cd.c
void	ms_cd(char *path);

// ms_echo.c
void	ms_echo(char *str, int new_line);
int 	hasFlag(char* str, char* flag);

// ms_unset.c
void	ms_unset(const char *var_name, t_env **all);

// ms_env.c
void	ms_env(t_env *env);

// ms_command_utils.c
char *clean_command(char *keyword, char *command);

// ms_redir.c
void    ms_redir_out(const char *cmd);
void    ms_redir_in(const char *cmd);

// ms_exec.c
char	*ms_check_path(char *cmd, char **ev);
int		ms_exec(char **cmd, char **env);
int		ms_central(t_list *parse, char **env);
void	ms_execpath(char **av, char **ev);
char	*ms_getpath(char *path, char **env);

//ms_pipe.c
int		ms_pipe(t_list **parse, char **env);

#endif
