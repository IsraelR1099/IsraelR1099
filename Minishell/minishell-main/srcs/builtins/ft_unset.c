/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:22:21 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/22 18:38:00 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ft_free_elem(t_env *to_delete)
{
	if (to_delete->key)
		free(to_delete->key);
	if (to_delete->value)
		free(to_delete->value);
	if (to_delete)
		free(to_delete);
}

int	ft_unset(char **names, t_env **env)
{
	unsigned char	ret;
	t_env			*to_delete;
	t_env			*to_redirect;

	ret = 0;
	while (*(names++ + 1) != NULL)
	{
		if (ft_var_name_check(*names, ft_strlen(*names)))
		{
			ret = 1;
			ft_printf(2, "minishell: unset: `%s': not a valid identifier\n",
				*names);
			continue ;
		}
		to_delete = ft_find_elem(*env, *names);
		if (!to_delete || !*names || ft_strcmp(*names, "_") == 0)
			continue ;
		to_redirect = ft_find_elem_before(*env, *names);
		if (!to_redirect)
			*env = to_delete->next;
		else
			to_redirect->next = to_delete->next;
		ft_free_elem(to_delete);
	}
	return (ret);
}
