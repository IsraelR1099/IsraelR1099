/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 21:18:32 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/03 14:13:25 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../Libft/libft.h"

static char	*ft_strchrnul(const char *s, int c)
{
	while (*s)
	{
		if (c == *s)
			break ;
		s++;
	}
	return ((char *)s);
}

static int	ft_execve(char *file, char *argv[], char *envp[])
{
	char	*path;
	char	tstr[126];
	char	*pstr;
	char	*cpath;
	int		ret;
	size_t		len;

	path = getenv("PATH");
	cpath = path;
	len = 0;
	ft_bzero(tstr, 126);
//	printf("entro en ft execve y path es %s y cpath %s y path len %zu\n", path, cpath, ft_strlen(path));
	while (cpath)
	{
		pstr = ft_strchrnul(cpath, ':');
		ft_memcpy(tstr, cpath, pstr - cpath);
		tstr[pstr - cpath] = '/';
		ft_memcpy(tstr + (pstr - cpath) + (pstr>cpath), file, ft_strlen(file) +
		1);
		ret = execve(tstr, argv, envp);
//		printf("ret %d y tstr %s\n", ret, tstr);
		cpath = pstr + 1;
		len++;
	}
	printf("salgo de exec y ret es %d\n", ret);
	ft_error("command not found", 127);
	return (0);
}

int	ft_execvp(char *file, char *argv[], char *envp[])
{
	int	iter;

	iter = 0;
	while (file[iter])
	{
		file[iter] = ft_tolower(file[iter]);
		iter++;
	}
	return (ft_execve(file, argv, envp));
}
