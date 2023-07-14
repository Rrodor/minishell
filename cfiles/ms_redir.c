/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 00:41:23 by aramon            #+#    #+#             */
/*   Updated: 2023/07/14 16:14:46 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hfiles/minishell.h"

char    *ft_strtok(const char *str, const char *delim)
{
    char        *s;
    int         i;
    int         j;
    char        *token;

    i = 0;
    j = 0;
    if (str != NULL)
        s = (char*)str;
    token = malloc(ft_strlen(s) + 1);
    if (token == NULL)
        return (NULL);
    while (s[i] && !ft_strchr(delim, s[i]))
    {
        token[j] = s[i];
        i++;
        j++;
    }
    token[j] = '\0';
    s = &s[i + 1];
    return (token);
}

// Trim whitespaces front and back
char    *trim_whitespaces(char *str)
{
    int     i;
    int     j;
    char    *new;

    i = 0;
    j = 0;
    new = malloc(ft_strlen(str) + 1);
    if (new == NULL)
        return (NULL);
    while (str[i] == ' ')
        i++;
    while (str[i])
    {
        new[j] = str[i];
        i++;
        j++;
    }
    new[j] = '\0';
    return (new);
}

// Basic implementation of redirection ">"
// Lots of errors cases must be handled (returning 1)
void    ms_redir_out(const char *cmd)
{
    int fd;
    int savedStdout;
    char *cmd_trimmed;
    char *token;
    char *new_cmd;
    int append;

    token = ft_strtok((char*)cmd, ">"); // Get command before ">"
    new_cmd = ft_strtok(NULL, ">"); // Get command after ">"
    if (new_cmd == NULL) { // Check if there is a command after ">"
        ft_printf("Error: invalid command\n");
        return;
    }
    cmd_trimmed = trim_whitespaces(new_cmd); // Trim whitespaces front and back
    append = 0; // Check if it's append or overwrite
    if (strstr(cmd_trimmed, ">") != NULL)
    {
        append = 1; // It's append
        cmd_trimmed = trim_whitespaces(ft_strtok(cmd_trimmed, ">")); // Trim whitespaces front and back
    }
    // Open file (create if not exist) using APPEND or TRUNC based on apppend variable
    if (append)
        fd = open(cmd_trimmed, O_WRONLY | O_CREAT | O_APPEND, 0644);
    else
        fd = open(cmd_trimmed, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    savedStdout = dup(STDOUT_FILENO); // Save stdout
    if (dup2(fd, STDOUT_FILENO) == -1) // Redirect stdout to file
        ft_printf("Error: dup2 failed\n");
    close(fd); // Close file
    ft_printf("Hello world\n"); // Print in file
    if (dup2(savedStdout, STDOUT_FILENO) == -1) // Restore stdout
        ft_printf("Error: dup2 failed\n");
    close(savedStdout); // Close saved stdout
    system(token); // Execute command before ">" | Need swap to execve()
    if (dup2(savedStdout, STDOUT_FILENO) == -1) // Restore stdout
        ft_printf("Error: dup2 failed\n");
    close(savedStdout); // Close saved stdout
}

void ms_redir_in(const char *cmd)
{
    int fd;
    int savedStdin;
    char *cmd_trimmed;
    char *token;
    char *new_cmd;
    int append;

    token = ft_strtok((char*)cmd, "<"); // Get command before "<"
    new_cmd = ft_strtok(NULL, "<"); // Get command after "<"
    if (new_cmd == NULL) { // Check if there is a command after "<"
        ft_printf("Error: invalid command\n");
        return;
    }
    cmd_trimmed = trim_whitespaces(new_cmd); // Trim whitespaces front and back
    append = 0;
    if (strstr(cmd_trimmed, "<") != NULL) // Check if it's append or overwrite
    {
        append = 1;
        cmd_trimmed = trim_whitespaces(ft_strtok(cmd_trimmed, "<")); // Trim whitespaces front and back
    }
    if (append) // Open file (create if not exist) using APPEND or TRUNC based on apppend variable
        fd = open(cmd_trimmed, O_RDONLY | O_CREAT | O_APPEND, 0644);
    else
        fd = open(cmd_trimmed, O_RDONLY | O_CREAT | O_TRUNC, 0644);
    savedStdin = dup(STDIN_FILENO); // Save stdin
    if (dup2(fd, STDIN_FILENO) == -1)
        ft_printf("Error: dup2 failed\n");
    close(fd); // Close file
    ft_printf("Hello world\n"); // Print in file
    if (dup2(savedStdin, STDIN_FILENO) == -1) // Restore stdin
        ft_printf("Error: dup2 failed\n");
    close(savedStdin); // Close saved stdin
    system(token); // Execute command before "<" | Need swap to execve()
    if (dup2(savedStdin, STDIN_FILENO) == -1)
        ft_printf("Error: dup2 failed\n");
    close(savedStdin); // Close saved stdin
}