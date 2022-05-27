/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sub_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 22:00:47 by mporras-          #+#    #+#             */
/*   Updated: 2022/03/04 22:00:52 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	ft_create_cuts(t_meta_data *meta, int value)
{
	t_stacks	*rst;
	t_stacks	*node;

	node = meta->pivot;
	while (node && node->next != NULL)
		node = node->next;
	if (node && value == node->value)
		return (1);
	rst = (t_stacks *)malloc(sizeof(t_stacks));
	if (rst == NULL)
		return (0);
	rst->value = value;
	rst->next = NULL;
	if (node == NULL)
		meta->pivot = rst;
	else
		node->next = rst;
	return (1);
}

int	ft_get_sub_stack_limits(t_meta_data *meta)
{
	int			i;
	int			pos;
	int			prev;
	t_stacks	*node;

	i = 1;
	pos = ft_min_at_stack(meta, 'a');
	while (pos != 0)
	{
		prev = pos;
		pos = ft_find_next(meta, 'a', pos);
		i++;
		if (pos == 0 || i == meta->cuts)
		{
			if (pos == 0)
				node = ft_get_node_from_index(meta, 'a', prev);
			else
				node = ft_get_node_from_index(meta, 'a', pos);
			if (ft_create_cuts(meta, node->value) == 0)
				return (0);
			node = NULL;
			i = 0;
		}
	}
	return (1);
}
