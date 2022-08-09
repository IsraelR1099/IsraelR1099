/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phase.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:42:03 by irifarac          #+#    #+#             */
/*   Updated: 2022/08/09 20:49:46 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_push_swap.h"

/*int	ft_phase1(t_nbr **head, t_nbr **head_b, int counter)
{
	int		nbr;

	while (ft_pcheck(head) != 2)
	{
		if (ft_best_way(head, counter) == 2)
		{
			nbr = ft_groups(counter);
			while (nbr && ft_pcheck(head) != 2)
			{
				ft_rra(head);
				if (ft_condition_pb(head))
					ft_pb(head, head_b);
				nbr--;
			}
		}
		if (!ft_do_both(head, head_b, counter))
			ft_do_stacka(head);
		if (ft_condition_pb(head))
		{
			ft_pb(head, head_b);
			if (!ft_do_both(head, head_b, counter))
				ft_do_stackb(head_b, head, counter);
		}
	}
	return (1);
}*/
int	ft_phase1(t_nbr **head, t_nbr **head_b, int counter)
{
	int		group;
	int		limits;
	t_nbr	*tmp;

	group = ft_groups(counter) * 2;
	while (ft_pcheck(head) != 2)
	{
		limits = 1;
		tmp = *head;
		if (ft_best_way(head, group, counter) == 1)
			ft_send(head, head_b, counter, group);
		else
		{
			while (limits <= ft_groups(counter)
				|| limits <= ft_groups(counter) * 2)
			{
				tmp = *head;
				if (tmp->positive >= (counter - 1 - group))
					if (ft_condition_pb(head))
						ft_pb(head, head_b);
				ft_rra(head);
				tmp = tmp->next;
				limits++;
			}
		}
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
	int		i;
	int		j;

	while (!ft_check_sort(head, counter) && ft_slst(head) > 5)
		ft_inversions(head, head_b, counter);
	ft_sort_5(head, head_b, counter);
	while (ft_slst(head) != ft_groups(counter))
	{
		i = ft_times(head, head_b);
		j = i;
		while (i)
		{
			ft_ra(head);
			i--;
		}
		ft_pa(head, head_b);
		if ((*head)->priority < (*head)->next->priority)
			ft_sa(head);
		while (j)
		{
			ft_rra(head);
			j--;
		}
	}
	return (1);
}

int	ft_phase3(t_nbr **head, t_nbr **head_b, int counter)
{
	t_nbr	*last;
	t_nbr	*last_b;
	int		times;

	while (ft_slst(head) < (counter - 1) && *head_b) //&& count++ < 55)
	{
		last = ft_lastnode(*head);
		last_b = ft_lastnode(*head_b);
		if ((*head_b)->data < (*head)->data)
		{
			if (*head_b && last->data > (*head_b)->data
				&& last->priority == 0 && last->data < (*head)->data)
				ft_rra(head);
			else if (*head_b && last->data < (*head)->data
				&& last->data > (*head_b)->data)
				ft_rra(head);
			else
			{
				if (last_b->data > (*head_b)->data)
					ft_rrb(head_b);
				else
					ft_pa(head, head_b);
			}
		}
		else
		{
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
	}
	return (1);
}
