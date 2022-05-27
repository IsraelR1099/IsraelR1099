/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_find_cuts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:05:11 by mporras-          #+#    #+#             */
/*   Updated: 2022/03/08 17:51:58 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	ft_start_cuts(t_meta_data *meta)
{
	if (meta->size <= 20)
		return (20);
	if (meta->size > 20 && meta->size <= 50)
		return (20);
	if (meta->size > 50 && meta->size <= 200)
		return (25);
	if (meta->size > 200 && meta->size <= 300)
		return (35);
	if (meta->size > 300 && meta->size <= 500)
		return (45);
	if (meta->size > 500)
		return (80);
	return (meta->size / 6);
}

static t_meta_data	*ft_copy_stacks_nodes(t_meta_data *meta, t_meta_data *dest)
{
	t_stacks	*stack;
	t_stacks	*node;
	t_stacks	*new;

	node = meta->first_a;
	while (node)
	{
		new = ft_create_elem(node->value, dest);
		if (new == NULL)
			return (NULL);
		if (dest->first_a == NULL)
		{
			stack = new;
			dest->first_a = stack;
		}
		else
		{
			stack->next = new;
			stack = stack->next;
		}
		node = node->next;
	}
	return (dest);
}

static t_meta_data	*ft_copy_stacks(t_meta_data *meta)
{
	t_meta_data	*rst;

	rst = ft_meta_data_init();
	if (rst == NULL)
		return (NULL);
	rst = ft_copy_stacks_nodes(meta, rst);
	return (rst);
}

static t_meta_data	*ft_test_pivot(t_meta_data *meta, int cut)
{
	t_meta_data	*copy;

	copy = ft_copy_stacks(meta);
	if (copy == NULL)
		return (NULL);
	copy->cuts = cut;
	copy->sim = 1;
	ft_get_sub_stack_limits(copy);
	ft_select_cases(copy);
	return (copy);
}

int	ft_find_best_pivot(t_meta_data *meta)
{
	t_meta_data	*copy;
	int			min;
	int			min_cut;
	int			start;

	min = 0;
	min_cut = 0;
	start = ft_start_cuts(meta);
	meta->cuts = start;
	while (start < meta->size && start < meta->cuts * 2)
	{
		copy = ft_test_pivot(meta, start);
		if (copy == NULL)
			return (ft_clear_all(copy));
		if (min == 0 || copy->moves < min)
		{
			min = copy->moves;
			min_cut = start;
		}
		ft_clear_all(copy);
		start++;
	}
	meta->cuts = min_cut;
	return (1);
}
