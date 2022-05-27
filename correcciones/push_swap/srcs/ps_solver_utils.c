/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solver_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:48:12 by mporras-          #+#    #+#             */
/*   Updated: 2022/02/27 14:48:15 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_max_at_stack(t_meta_data *meta, char ab)
{
	t_stacks	*node;
	int			i;
	int			min;
	int			rst;

	i = 0;
	node = ft_select_stack(meta, ab);
	if (!node)
		return (0);
	rst = 1;
	min = node->value;
	while (node)
	{
		i++;
		if (min < node->value)
		{
			min = node->value;
			rst = i;
		}
		node = node->next;
	}
	return (rst);
}

int	ft_min_at_stack(t_meta_data *meta, char ab)
{
	t_stacks	*node;
	int			i;
	int			min;
	int			rst;

	i = 0;
	node = ft_select_stack(meta, ab);
	if (!node)
		return (0);
	rst = 1;
	min = node->value;
	while (node)
	{
		i++;
		if (min > node->value)
		{
			min = node->value;
			rst = i;
		}
		node = node->next;
	}
	return (rst);
}

int	ft_find_next(t_meta_data *meta, char ab, int index)
{
	t_stacks	*node;
	int			value;
	int			rst;
	int			i;

	node = ft_select_stack(meta, ab);
	value = ft_get_value_node(meta, index, ab);
	rst = ft_get_value_node(meta, ft_max_at_stack(meta, ab), ab);
	i = 0;
	index = 0;
	while (node)
	{
		i++;
		if (node->value > value && node->value <= rst)
		{
			rst = node->value;
			index = i;
		}
		node = node->next;
	}
	return (index);
}

int	ft_find_prev(t_meta_data *meta, char ab, int index)
{
	t_stacks	*node;
	int			value;
	int			rst;
	int			i;

	node = ft_select_stack(meta, ab);
	value = ft_get_value_node(meta, index, ab);
	rst = ft_get_value_node(meta, ft_min_at_stack(meta, ab), ab);
	i = 0;
	index = 0;
	while (node)
	{
		i++;
		if (node->value < value && node->value >= rst)
		{
			rst = node->value;
			index = i;
		}
		node = node->next;
	}
	return (index);
}

t_stacks	*ft_last_node(t_meta_data *meta, char ab)
{
	t_stacks	*node;

	node = ft_select_stack(meta, ab);
	while (node->next != NULL)
		node = node->next;
	return (node);
}
