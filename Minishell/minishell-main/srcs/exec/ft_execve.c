/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:41:04 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/23 21:36:20 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_is_alias(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == '/')
			return (0);
		i++;
	}
	return (1);
}

static int	ft_find_exec(t_env *env, char **names)
{
	char	tstr[BUFFER_SIZE];
	char	*path;
	char	*pstr;
	char	*cpath;

	path = ft_expand(env, "PATH");
	cpath = path;
	ft_bzero(tstr, BUFFER_SIZE);
	if (ft_is_alias(names[0]))
	{
		while (cpath)
		{
			pstr = ft_strchrnul(cpath, ':');
			ft_memcpy(tstr, cpath, pstr - cpath);
			tstr[pstr - cpath] = '/';
			ft_memcpy(tstr + (pstr - cpath) + (pstr > cpath),
				names[0], ft_strlen(names[0]));
			execve(tstr, names, env->envp);
			ft_memset(tstr, 0, BUFFER_SIZE);
			cpath = pstr + 1;
			if (pstr[0] != ':')
				return (127);
		}
	}
	return (0);
}

int	ft_execve(t_env *env, char **names)
{
	int	ret;

	ret = 0;
	if (!ft_is_alias(names[0]))
		ret = ft_is_file_or_dir(names[0]);
	if (ret)
		return (ret);
	if (!(ft_strcmp(*names, "bash"))
		|| !(ft_strcmp(*names, "./minishell")) || !(ft_strcmp(*names, "zsh")))
	{
		env->envp = ft_create_envp(env);
		if (!env->envp)
			ft_error("malloc error", 1);
	}
	if (ft_is_alias(names[0]) && ft_expand(env, "PATH"))
	{
		ret = ft_find_exec(env, names);
		if (ret)
			ft_printf(2, "minishell: %s: command not found\n", names[0]);
	}
	else
		ret = execve(names[0], names, env->envp) * -1;
	return (ret);
}
