/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:09:38 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/23 16:33:18 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_special_cd_cases(t_env *env, char **names)
{
	char	s[BUFFER_SIZE];
	int		ret;

	ret = 2;
	if (!(*(names + 1)))
			ret = chdir(ft_expand(env, "HOME"));
	if (names[1] && ft_is_file(names[1]))
	{
		ft_printf(2, "minishell: cd: %s: Not a directory\n", names[1]);
		ret = 1;
	}
	else if (!ft_strlen(ft_expand(env, "OLDPWD")) && !ft_strcmp(names[1], "-"))
	{
		ft_printf(2, "minishell: cd: OLDPWD not set\n");
		ret = 1;	
	}
	else if ((!(ft_strncmp(*(names + 1), "--", ft_strlen(*(names + 1))))))
	{
		ret = chdir((ft_expand(env, "OLDPWD")));
		printf("%s\n", getcwd(s, BUFFER_SIZE));
	}
	else if (!ft_strlen(ft_expand(env, "HOME")) && ft_strcmp(names[1], getenv("HOME")))
	{
		printf("names[1]: %s\n", names[1]);
		ft_printf(2, "minishell: cd: HOME not set\n");
		ret = 1;	
	}
	return (ret);
}

int	ft_cd(t_env *env, char **names)
{
	char	old_pwd[BUFFER_SIZE];
	char	new_pwd[BUFFER_SIZE];
	char	s[BUFFER_SIZE];
	int		ret;

	bzero(old_pwd, BUFFER_SIZE);
	bzero(new_pwd, BUFFER_SIZE);
	ft_memcpy(new_pwd, "PWD=", 5);
	ft_memcpy(old_pwd, "OLDPWD=", 8);
	ft_memcpy(old_pwd + 7, getcwd(s, BUFFER_SIZE),
	ft_strlen(getcwd(s, BUFFER_SIZE)) + 1);
	ret = ft_special_cd_cases(env, names);
	if (ret == 2 && (*(names + 1)))
		ret = chdir (*(names + 1));
	if (ret == -1)
		ft_printf(2, "minishell: cd: %s: No such file or directory\n",
			*(names + 1));
	ft_memcpy(new_pwd + 4, getcwd(s, BUFFER_SIZE),
		ft_strlen(getcwd(s, BUFFER_SIZE)) + 1);
	ft_update_var(new_pwd, 4, env);
	ft_update_var(old_pwd, 7, env);
	if (ret < 0)
		return (ret * -1);
	else
		return (ret);
}
