/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testpipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 17:21:45 by rrodor            #+#    #+#             */
/*   Updated: 2023/07/16 18:08:35 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>

void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);

int    ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen((char *)src));
	while (i < (size - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (size > 0)
		dst[i] = 0;
	return (ft_strlen((char *)src));
}

char	*ft_strdup(const char *s)
{
	char	*scpy;

	scpy = ft_calloc(ft_strlen((char *)s) + 1, sizeof(char));
	if (!scpy)
		return (0);
	ft_strlcpy(scpy, s, ft_strlen((char *)s) + 1);
	return (scpy);
}

void	putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	ft_bzero(void *s, size_t n)
{
	char	*str;

	str = s;
	while (n > 0)
	{
		*str = 0;
		str++;
		n--;
	}
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] && --n)
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*res;

	if (size == 0 || nmemb == 0)
		return (malloc(0));
	if (((size * nmemb) / size) != nmemb)
		return (0);
	res = malloc(nmemb * size);
	if (!res)
		return (0);
	ft_bzero(res, nmemb * size);
	return ((void *)res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	llen;

	i = 0;
	if (!s)
		return (0);
	if (start >= ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	llen = ft_strlen(s + start);
	if (len < llen)
		llen = len;
	str = (char *)ft_calloc(llen + 1, sizeof(char));
	if (!str)
		return (0);
	i = -1;
	while (++i < llen)
		str[i] = s[i + start];
	return (str);
}

char	*ms_getpath(char *path, char**env)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (env[i])
	{
		while (env[i][j] && env[i][j] != '=')
			j++;
		if (ft_strncmp(env[i], path, j) == 0)
		{
			str = ft_substr(env[i], j + 1, ft_strlen(env[i]));
			return (str);
		}
		i++;
		j = 0;
	}
	return (NULL);
}

static int	ft_countwrd(const char *s, char c)
{
	int	l;
	int	i;

	l = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			l++;
		while (s[i] != c && s[i])
			i++;
	}
	return (l);
}

static int	ft_init(char const *s, char c, int *i, int *j)
{
	int	l;

	l = ft_countwrd(s, c);
	*i = 0;
	*j = 0;
	return (l);
}

char	**ft_split(char const *s, char c)
{
	char	**wrd;
	int		l;
	int		i;
	int		j;
	int		k;

	if (!s)
		return (0);
	l = ft_init(s, c, &i, &j);
	wrd = ft_calloc(l + 1, sizeof(char *));
	if (!wrd)
		return (0);
	while (j++ < l)
	{
		k = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i + k] != c && s[i + k])
			k++;
		wrd[j - 1] = ft_substr(s, i, k);
		if (!wrd[j - 1])
			return (0);
		i += k;
	}
	return (wrd);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	ls1;
	size_t	ls2;

	if (!s1 || !s2)
		return (0);
	ls1 = ft_strlen((char *)s1);
	ls2 = ft_strlen((char *)s2);
	str = ft_calloc(ls1 + ls2 + 1, sizeof(char));
	if (!str)
		return (0);
	ft_strlcat(str, s1, ls1 + 1);
	ft_strlcat(str, s2, ls1 + ls2 + 1);
	return (str);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	ls;
	size_t	ld;

	if ((!dst || !src) && !size)
		return (0);
	ls = ft_strlen((char *)src);
	ld = ft_strlen((char *)dst);
	i = 0;
	if (!size || (size < ld))
		return (ls + size);
	while (src[i] && (size - 1) > (ld + i))
	{
		dst[ld + i] = src[i];
		i++;
	}
	dst[ld + i] = 0;
	return (ls + ld);
}

int	ms_execpath(char **cmd, char **env)
{
	char	*path;
	char	**path_tab;
	pid_t	pid;
	int		i;
	int		fd;

	i = 0;
	path = ms_getpath("PATH", env);
	path_tab = ft_split(path, ':');
	while (path_tab[i])
	{
		path_tab[i] = ft_strjoin(path_tab[i], "/");
		path_tab[i] = ft_strjoin(path_tab[i], cmd[0]);
		fd = open(path_tab[i], O_RDONLY);
		if (fd > 0)
		{
			pid = fork();
			if (pid == 0)
				execve(path_tab[i], cmd, env);
			else
				close(fd);
				wait(NULL);
				return (0);
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv, char **env)
{
	pid_t	pid;
	int		fd[2];
	int	i = 0;
	char	*str[] = {"ls", NULL};

	printf("argc = %d\n", argc);
	if (pipe(fd) == -1)
		return (0);
	pid = fork();
	if (pid == -1)
		return (0);
	if (!pid)
	{
		putstr("child start\n");
		close(fd[0]);
		dup2(fd[1], 1);
		putstr("child dup ok\n");
		ms_execpath(str, env);
		putstr("child end\n");
	}
	else
	{
		putstr("parent start\n");
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		putstr("parent dup ok\n");
		waitpid(pid, NULL, 0);
		putstr("parent end\n");
	}
	dup2(0, STDOUT_FILENO);
	ms_execpath(argv + 1, env);
	return (0);
}
