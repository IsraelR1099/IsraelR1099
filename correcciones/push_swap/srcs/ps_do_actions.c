/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_do_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 16:40:30 by mporras-          #+#    #+#             */
/*   Updated: 2022/02/26 16:40:36 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_do_push(t_meta_data *meta, char ab)
{
	if (ab == 'a')
	{
		ft_push_action(meta, 'a');
		if (meta->sim == 0)
			ft_putendl_fd("pb", STDOUT_FILENO);
		return (1);
	}
	else if (ab == 'b')
	{
		ft_push_action(meta, 'b');
		if (meta->sim == 0)
			ft_putendl_fd("pa", STDOUT_FILENO);
		return (1);
	}
	return (0);
}

int	ft_do_rotate(t_meta_data *meta, char ab)
{
	if (ab == 'a')
	{
		ft_rotate_action(meta, 'a');
		if (meta->sim == 0)
			ft_putendl_fd("ra", STDOUT_FILENO);
		return (1);
	}
	else if (ab == 'b')
	{
		ft_rotate_action(meta, 'b');
		if (meta->sim == 0)
			ft_putendl_fd("rb", STDOUT_FILENO);
		return (1);
	}
	else if (ab == 'r')
	{
		ft_rotate_action(meta, 'a');
		ft_rotate_action(meta, 'b');
		if (meta->sim == 0)
			ft_putendl_fd("rr", STDOUT_FILENO);
		return (1);
	}
	return (0);
}

int	ft_do_reverse_rotate(t_meta_data *meta, char ab)
{
	if (ab == 'a')
	{
		ft_reverse_rotate_action(meta, 'a');
		if (meta->sim == 0)
			ft_putendl_fd("rra", STDOUT_FILENO);
		return (1);
	}
	else if (ab == 'b')
	{
		ft_reverse_rotate_action(meta, 'b');
		if (meta->sim == 0)
			ft_putendl_fd("rrb", STDOUT_FILENO);
		return (1);
	}
	else if (ab == 'r')
	{
		ft_reverse_rotate_action(meta, 'a');
		ft_reverse_rotate_action(meta, 'b');
		if (meta->sim == 0)
			ft_putendl_fd("rrr", STDOUT_FILENO);
		return (1);
	}
	return (0);
}

int	ft_do_swap(t_meta_data *meta, char ab)
{
	if (ab == 'a')
	{
		ft_swap_action(meta, 'a');
		if (meta->sim == 0)
			ft_putendl_fd("sa", STDOUT_FILENO);
		return (1);
	}
	else if (ab == 'b')
	{
		ft_swap_action(meta, 'b');
		if (meta->sim == 0)
			ft_putendl_fd("sb", STDOUT_FILENO);
		return (1);
	}
	else if (ab == 'r')
	{
		ft_swap_action(meta, 'a');
		ft_swap_action(meta, 'b');
		if (meta->sim == 0)
			ft_putendl_fd("ss", STDOUT_FILENO);
		return (1);
	}
	return (0);
}

int	ft_do_while(t_meta_data *meta, int i, char ab,
	int (*act)(t_meta_data *, char))
{
	int	rst;

	rst = 0;
	while (i-- > 0)
		rst += act(meta, ab);
	return (rst);
}
