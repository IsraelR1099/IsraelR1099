/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phase.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:42:03 by irifarac          #+#    #+#             */
/*   Updated: 2022/08/12 13:00:03 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_push_swap.h"

static void	ft_send_rra(t_nbr **head, t_nbr **head_b, int counter, int group)
{
	t_nbr	*tmp;
	int		limits;

	tmp = *head;
	limits = 1;
	while (limits <= ft_groups(counter)
		|| limits <= ft_groups(counter) * 2)
	{
		tmp = *head;
		if (tmp->positive >= (counter - 1 - group))
		{
			if (ft_condition_pb(head))
				ft_check_pb(head, head_b);
		}
		if (!ft_check_pos(head, counter, group))
			ft_rra(head);
		tmp = tmp->next;
		limits++;
	}
}

static void	ft_phase3_down(t_nbr **head, t_nbr **head_b)
{
	int		times;
	t_nbr	*last;

	if ((*head_b)->data < (*head)->next->data
		&& (*head_b)->data > (*head)->data)
	{
		ft_ra(head);
		ft_pa(head, head_b);
		last = ft_lastnode(*head);
		if (last->data > (*head_b)->data)
			ft_rra(head);
	}
	else
	{
		times = ft_times_noprio(head, head_b);
		while (times)
		{
			ft_ra(head);
			times--;
		}
	}
}

int	ft_phase1(t_nbr **head, t_nbr **head_b, int counter)
{
	int		group;

	group = ft_groups(counter) * 2;
	while (ft_pcheck(head) != 2)
	{
		if (ft_best_way(head, group, counter) == 1)
			ft_send(head, head_b, counter, group);
		else
			ft_send_rra(head, head_b, counter, group);
		if (ft_check_pos(head, counter, group))
		{
			group = group + (ft_groups(counter) * 2);
			if (group >= (counter - 1))
				group = (counter - 1 - ft_groups(counter));
		}
	}
	return (1);
}

int	ft_phase2(t_nbr **head, t_nbr **head_b, int counter)
{
	while (!ft_check_sort(head, counter) && ft_slst(head) > 5)
		ft_inversions(head, head_b);
	ft_sort_5(head, head_b, counter);
	return (1);
}

int	ft_phase3(t_nbr **head, t_nbr **head_b, int counter)
{
	while (ft_slst(head) < (counter - 1) && *head_b)
	{
		if ((*head_b)->data < (*head)->data)
			ft_check_rra(head, head_b);
		else
			ft_phase3_down(head, head_b);
	}
	return (1);
}
