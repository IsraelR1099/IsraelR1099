/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_best.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 13:54:19 by irifarac          #+#    #+#             */
/*   Updated: 2022/08/09 20:21:54 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_push_swap.h"

int	ft_best_way(t_nbr **head, int group, int counter)
{
	t_nbr	*tmp;
	int		times;
	int		times_d;
	int		i;

	tmp = *head;
	times = 0;
	i = 0;
	while (tmp && i < ft_groups(counter))
	{
		if (tmp->positive >= (counter - 1 - group)
			&& tmp->priority == 0)
			times++;
		tmp = tmp->next;
		i++;
	}
	tmp = *head;
	times_d = 0;
	while (tmp)
	{
		if (tmp->index >= (ft_slst(head) - ft_groups(counter)))
		{
			if (tmp->positive >= (counter - 1 - group)
				&& tmp->priority == 0)
				times_d++;
		}
		tmp = tmp->next;
	}
	if (times >= times_d)
		return (1);
	return (0);
}
