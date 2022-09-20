/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 21:18:32 by irifarac          #+#    #+#             */
/*   Updated: 2022/09/20 14:09:48 by irifarac         ###   ########.fr       */
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
	char	*path = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin";
	char	tstr[126];
	char	*pstr;
	char	*cpath;

//	path = getenv("PATH");
	cpath = path;
	printf("file es %s\n", file);
	ft_bzero(tstr, 126);
	while (cpath)
	{
		pstr = ft_strchrnul(cpath, ':');
		ft_memcpy(tstr, cpath, pstr - cpath);
		tstr[pstr - cpath] = '/';
		ft_memcpy(tstr + (pstr - cpath) + (pstr>cpath), file, ft_strlen(file) +
		1);
		execve(tstr, argv, envp);
		cpath = pstr + 1;
	}
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
