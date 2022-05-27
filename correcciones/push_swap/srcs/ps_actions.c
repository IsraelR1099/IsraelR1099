/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 11:21:59 by mporras-          #+#    #+#             */
/*   Updated: 2022/02/25 21:39:27 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_swap_action(t_meta_data *meta, char ab)
{
	t_stacks	*tmp;

	if (ab == 'a' || ab == 's')
	{
		if (ft_list_size(meta->first_a) > 1)
		{
			tmp = meta->first_a->next;
			meta->first_a->next = tmp->next;
			tmp->next = meta->first_a;
			meta->first_a = tmp;
		}
	}
	if (ab == 'b' || ab == 's')
	{
		if (ft_list_size(meta->first_b) > 1)
		{
			tmp = meta->first_b->next;
			meta->first_b->next = tmp->next;
			tmp->next = meta->first_b;
			meta->first_b = tmp;
		}
	}
}

void	ft_rotate_action(t_meta_data *meta, char ab)
{
	t_stacks	*tmp;
	t_stacks	*node;

	if (ab == 'a')
		node = meta->first_a;
	else
		node = meta->first_b;
	if (ft_list_size(node) > 1)
	{
		if (ab == 'a')
			meta->first_a = meta->first_a->next;
		else
			meta->first_b = meta->first_b->next;
		tmp = node;
		while (node->next != NULL)
			node = node->next;
		tmp->next = NULL;
		node->next = tmp;
	}
}

void	ft_reverse_rotate_action(t_meta_data *meta, char ab)
{
	t_stacks	*tmp;
	t_stacks	*node;

	if (ab == 'a')
		node = meta->first_a;
	else
		node = meta->first_b;
	if (ft_list_size(node) > 1)
	{
		while ((node->next)->next != NULL)
			node = node->next;
		tmp = node->next;
		node->next = NULL;
		if (ab == 'a')
		{
			tmp->next = meta->first_a;
			meta->first_a = tmp;
		}
		else
		{
			tmp->next = meta->first_b;
			meta->first_b = tmp;
		}
	}
}

void	ft_push_action(t_meta_data *meta, char ab)
{
	t_stacks	*tmp;

	if (ab == 'a' || ab == 's')
	{
		if (ft_list_size(meta->first_a) > 0)
		{
			tmp = meta->first_a;
			meta->first_a = tmp->next;
			tmp->next = meta->first_b;
			meta->first_b = tmp;
		}
	}
	else if (ab == 'b' || ab == 's')
	{
		if (ft_list_size(meta->first_b) > 0)
		{
			tmp = meta->first_b;
			meta->first_b = tmp->next;
			tmp->next = meta->first_a;
			meta->first_a = tmp;
		}
	}
}
