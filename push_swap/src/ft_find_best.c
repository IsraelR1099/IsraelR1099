/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_best.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 13:54:19 by irifarac          #+#    #+#             */
/*   Updated: 2022/08/12 12:26:14 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_push_swap.h"

static int	ft_best_down(t_nbr **head, int counter, int group)
{
	t_nbr	*tmp;
	int		times_d;

	times_d = 0;
	tmp = *head;
	while (tmp)
	{
		if (tmp->index >= (ft_slst(head) - (ft_groups(counter) * 2)))
		{
			if (tmp->positive >= (counter - 1 - group)
				&& tmp->priority == 0)
				times_d++;
		}
		tmp = tmp->next;
	}
	return (times_d);
}

int	ft_best_way(t_nbr **head, int group, int counter)
{
	t_nbr	*tmp;
	int		times;
	int		times_d;
	int		i;

	tmp = *head;
	times = 0;
	i = 0;
	while (tmp && i < ft_groups(counter) * 2)
	{
		if (tmp->positive >= (counter - 1 - group)
			&& tmp->priority == 0)
			times++;
		tmp = tmp->next;
		i++;
	}
	times_d = ft_best_down(head, counter, group);
	if (times >= times_d)
		return (1);
	return (0);
}
