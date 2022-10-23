/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:09:19 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/23 13:15:34 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_pwd(t_env *env)
{
	if (ft_expand(env, "PWD"))
	{
		ft_printf(2, "%s\n", ft_expand(env, "PWD"));
		return (0);
	}
	else
	{
		ft_printf(2, "minishell: pwd: PWD variable deleted\n");
		return (1);
	}
}
