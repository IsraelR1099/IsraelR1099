/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_best.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 13:54:19 by irifarac          #+#    #+#             */
/*   Updated: 2022/07/18 14:10:51 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_push_swap.h"

int	ft_best_way(t_nbr **head, int counter)
{
	t_nbr	*tmp;
	int		len;
	int		group;
	int		nbr;
	int		nbr_last;
	int		size;

	group = ft_groups(counter);
	tmp = *head;
	size = ft_slst(head);
	nbr = 0;
	len = 0;
	while (tmp && len < group)
	{
		nbr += tmp->data;
		tmp = tmp->next;
		len++;
	}
	tmp = *head;
	nbr_last = 0;
	len = 0;
	while (tmp)
	{
		if (len == (size - nbr))
		{
			while (tmp)
			{
				nbr_last += tmp->data;
				tmp = tmp->next;
				len++;
			}
		}
		tmp = tmp->next;
	}
	if (nbr_last < nbr)
		return (2);
	return (1);
}
