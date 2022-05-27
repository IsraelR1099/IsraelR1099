/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_nodes_get.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:32:56 by mporras-          #+#    #+#             */
/*   Updated: 2022/03/04 16:32:59 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stacks	*ft_get_node_from_index(t_meta_data *meta, char ab, int index)
{
	int			i;
	t_stacks	*node;

	i = 0;
	node = ft_select_stack(meta, ab);
	while (++i < index)
		node = node->next;
	return (node);
}

int	ft_get_index_from_node(t_meta_data *meta, char ab, t_stacks *to_find)
{
	int			i;
	t_stacks	*node;

	i = 1;
	node = ft_select_stack(meta, ab);
	while (to_find != node)
	{
		i++;
		node = node->next;
	}
	return (i);
}

t_stacks	*ft_get_node_from_value(t_meta_data *meta, char ab, int value)
{
	t_stacks	*node;

	node = ft_select_stack(meta, ab);
	while (node)
	{
		if (node->value == value)
			return (node);
		node = node->next;
	}
	return (NULL);
}

int	ft_get_value_node(t_meta_data *meta, int index, char ab)
{
	int			i;
	t_stacks	*node;

	i = 0;
	node = ft_select_stack(meta, ab);
	while (++i < index)
		node = node->next;
	return (node->value);
}

int	ft_get_index_from_value(t_meta_data *meta, char ab, int value)
{
	t_stacks	*node;
	int			i;

	node = ft_select_stack(meta, ab);
	i = 1;
	while (node)
	{
		if (node->value == value)
			return (i);
		node = node->next;
		i++;
	}
	return (0);
}
