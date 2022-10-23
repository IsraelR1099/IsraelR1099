/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:21:35 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/23 13:23:26 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_num_arg(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != 0)
	{
		if (i == 0 && (str[i] == '-' || str[i] == '+'))
			continue ;
		if (!ft_isdigit(str[i]))
			return (1);
	}
	return (0);
}

void	ft_exit(char **names)
{
	unsigned char	ret;

	ret = 0;
	// ft_printf(1, "exit\n");
	if (names[2] && !ft_num_arg(names[1]))
	{
		ft_printf(2, "minishell: exit: too many arguments\n");
		ret = 1;
	}
	else if (names[1])
	{
		if (ft_num_arg(names[1]) || (!ft_atoi(names[1])
				&& ft_strlen(names[1]) > 5))
		{
			ft_printf(2, "minishell: exit: %s: numeric argument required\n",
				names[1]);
			ret = -1;
		}
		else
			ret = (unsigned char) ft_atoi(names[1]);
	}
	exit (ret);
}
