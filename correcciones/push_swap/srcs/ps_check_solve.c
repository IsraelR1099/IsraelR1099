/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_solve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:29:06 by mporras-          #+#    #+#             */
/*   Updated: 2022/03/04 16:29:09 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_check_solve(t_meta_data *meta)
{
	int			i;
	int			prev;
	t_stacks	*stack;

	i = 0;
	if (meta->first_b != NULL)
		return (0);
	if (ft_list_size(meta->first_a) == 1)
		return (1);
	stack = meta->first_a;
	prev = stack->value;
	while (stack)
	{
		if (prev > stack->value)
			return (0);
		i++;
		prev = stack->value;
		stack = stack->next;
	}
	if (i != meta->size)
		return (0);
	return (1);
}

int	ft_check_solve_stack(t_meta_data *meta, char ab)
{
	int			prev;
	t_stacks	*stack;
	int			i;

	stack = ft_select_stack(meta, ab);
	prev = stack->value;
	i = 0;
	while (ab == 'a' && stack)
	{
		if (prev > stack->value)
			return (0);
		i++;
		prev = stack->value;
		stack = stack->next;
	}
	while (ab == 'b' && stack)
	{
		if (prev < stack->value)
			return (0);
		i++;
		prev = stack->value;
		stack = stack->next;
	}
	return (i);
}
