/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:19:20 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/23 11:42:35 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	increase_shlvl(t_env *env)
{
	char	shlvl[20];
	int		shlvl_int;

	shlvl_int = ft_atoi(ft_expand(env, "SHLVL")) + 1;
	ft_bzero(shlvl, 20);
	ft_memcpy(shlvl, "SHLVL=", 7);
	if (shlvl_int > 999)
	{
		ft_printf(2, "minishell: warning: shell level too high, resetting to 1\n"
			);
		ft_memcpy(shlvl + ft_strlen(shlvl), "1", 2);
	}
	else
		ft_memcpy(shlvl + ft_strlen(shlvl),
			ft_itoa(shlvl_int), ft_strlen(ft_itoa(shlvl_int)) + 1);
	ft_update_var(shlvl, 6, env);
	ft_update_var("OLDPWD=", 7, env);
}

char	**ft_create_envp(t_env *env)
{
	t_env	*ptr;
	char	**head;

	ptr = env;
	env->envp = (char **) malloc(sizeof(char *) * (ft_envsize(env) + 1));
	if (!env->envp)
		return (NULL);
	head = env->envp;
	while (ptr)
	{
		*env->envp = malloc(ft_strlen(ptr->key) + ft_strlen("=")
				+ ft_strlen(ptr->value) + 1);
		if (!env->envp)
			return (NULL);
		ft_memcpy(*env->envp, ptr->key, ft_strlen(ptr->key) + 1);
		ft_memcpy(*env->envp + ft_strlen(ptr->key), "=", 2);
		if (ptr->value)
			ft_memcpy(*env->envp + ft_strlen(ptr->key) + 1,
				ptr->value, ft_strlen(ptr->value) + 1);
		env->envp++;
		ptr = ptr->next;
	}
	*env->envp = NULL;
	return (env->envp - (env->envp - head));
}

t_env	*ft_init_env(char **main_env)
{
	t_env	*head;
	t_env	*current;
	t_env	*temp;
	int		i;

	head = NULL;
	head = ft_create_elem(head, main_env[0], ft_find_value(main_env[0]));
	if (!head)
		return (NULL);
	temp = head;
	i = 1;
	while (main_env[i] != NULL)
	{
		current = ft_create_elem(current, main_env[i],
				ft_find_value(main_env[i]));
		if (!current)
			return (NULL);
		temp->next = current;
		temp = current;
		i++;
	}
	increase_shlvl(head);
	return (head);
}
