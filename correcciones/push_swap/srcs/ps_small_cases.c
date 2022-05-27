/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_small_cases.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:53:02 by mporras-          #+#    #+#             */
/*   Updated: 2022/02/27 14:53:07 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	ft_case_two(t_meta_data *meta, char ab)
{
	t_stacks	*node;

	node = ft_select_stack(meta, ab);
	if (ab == 'a' && node->value > node->next->value)
		return (ft_do_swap(meta, 'a'));
	if (ab == 'b' && node->value < node->next->value)
		return (ft_do_swap(meta, 'b'));
	return (0);
}

static int	ft_case_three(t_meta_data *meta, char ab)
{
	int			max;

	if (ft_check_solve_stack(meta, ab) > 0)
		return (0);
	max = ft_max_at_stack(meta, ab);
	if (max == 1)
		return (ft_do_rotate(meta, ab) + ft_case_two(meta, ab));
	else if (max == 2)
		return (ft_do_reverse_rotate(meta, ab) + ft_case_two(meta, ab));
	else
		return (ft_case_two(meta, ab));
}

static int	ft_case_four(t_meta_data *meta, char ab)
{
	int			rst;
	char		pull;

	if (ft_check_solve_stack(meta, ab) > 0)
		return (0);
	rst = 0;
	if (ab == 'a')
		pull = 'b';
	else
		pull = 'a';
	if (ft_min_at_stack(meta, ab) == 1 || ft_max_at_stack(meta, ab) == 1)
	{
		rst += ft_do_push(meta, ab);
		rst += ft_case_three(meta, ab);
		rst += ft_do_push(meta, pull);
		if (ft_max_at_stack(meta, ab) == 1)
			rst += ft_do_rotate(meta, ab);
		return (rst);
	}
	else if (ft_min_at_stack(meta, ab) == 4 || ft_max_at_stack(meta, ab) == 4)
		return (ft_do_rotate(meta, ab) + ft_case_four(meta, ab));
	else
		return (ft_do_swap(meta, ab) + ft_case_four(meta, ab));
}

static int	ft_case_five(t_meta_data *meta, char ab)
{
	t_stacks	*stack;
	int			min;
	int			i;
	char		pull;

	i = 0;
	if (ab == 'a')
		pull = 'b';
	else
		pull = 'a';
	stack = ft_select_stack(meta, ab);
	if (ft_check_solve_stack(meta, ab) == 1)
		return (0);
	if (ft_list_size(stack) == 3)
		return (ft_case_four(meta, ab)
			+ ft_pulling_back_all_stack(meta));
	min = ft_min_at_stack(meta, ab);
	if (min == 1)
		return (ft_do_push(meta, ab)
			+ ft_case_four(meta, ab) + ft_do_push(meta, pull));
	if (min <= 3)
		return (ft_do_rotate(meta, ab) + ft_case_five(meta, ab));
	else
		return (ft_do_reverse_rotate(meta, ab) + ft_case_five(meta, ab));
}

int	ft_small_cases(t_meta_data *meta, char ab)
{
	int	size;

	if (ab == 'A' || ab == 'a')
	{
		size = ft_list_size(meta->first_a);
		ab = 'a';
	}
	else
	{
		size = ft_list_size(meta->first_b);
		ab = 'b';
	}
	if (size == 1)
		return (0);
	else if (size == 2)
		return (ft_case_two(meta, ab));
	else if (size == 3)
		return (ft_case_three(meta, ab));
	else if (size == 4)
		return (ft_case_four(meta, ab));
	else if (size == 5)
		return (ft_case_five(meta, ab));
	else
		return (0);
}
