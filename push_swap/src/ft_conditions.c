/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conditions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:28:39 by irifarac          #+#    #+#             */
/*   Updated: 2022/08/10 20:17:05 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_push_swap.h"

int	ft_condition_pb(t_nbr **head)
{
	t_nbr	*tmp;
	t_nbr	*last;

	tmp = *head;
	last = ft_lastnode(tmp);
	if (tmp->priority == 0
		&& tmp->data < tmp->next->data)
		return (1);
	else if (tmp->priority == 0
		&& last->priority == 0
		&& tmp->data < last->data)
		return (1);
	return (0);
}
