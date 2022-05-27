/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:03:06 by mporras-          #+#    #+#             */
/*   Updated: 2022/02/19 16:03:09 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_pulling_back_all_stack(t_meta_data *meta)
{
	if (meta->first_b == NULL)
		return (0);
	else
		return (ft_do_push(meta, 'b') + ft_pulling_back_all_stack(meta));
}

int	ft_absolute(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

int	ft_list_size(t_stacks *first_node)
{
	t_stacks	*node;
	int			i;

	node = first_node;
	i = 0;
	while (node)
	{
		i++;
		node = node->next;
	}
	return (i);
}

t_stacks	*ft_select_stack(t_meta_data *meta, char ab)
{
	t_stacks	*stack;

	if (ab == 'a')
		stack = meta->first_a;
	else
		stack = meta->first_b;
	return (stack);
}
