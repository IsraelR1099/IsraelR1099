/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conditions2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:28:39 by irifarac          #+#    #+#             */
/*   Updated: 2022/07/14 20:21:23 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_push_swap.h"

int	ft_condition_rb(t_nbr **head_b)
{
	t_nbr	*tmp;
	int	last;
	
	if (!head_b)
		return (0);
	tmp = *head_b;
	while (tmp)
	{
		last = tmp->data;
		tmp = tmp->next;
	}
	tmp = *head_b;
	if (tmp->data < last &&
		tmp->data < tmp->next->data)
		return (1);
	return (0);
}

int	ft_condition_pb(t_nbr **head)
{
	t_nbr	*tmp;
	t_nbr	*last;

	tmp = *head;
	last = ft_lastnode(tmp);
//	printf("priority %d y next %d y data %d y next %d\n", tmp->priority, tmp->next->priority, tmp->data, tmp->next->data);
	if (tmp->priority == 0 &&
		tmp->data < tmp->next->data)
		return (1);
	else if (tmp->priority == 0 &&
		last->priority == 0 &&
		tmp->data < last->data)
		return (1);
	return (0);
}

int	ft_condition_pa(t_nbr **head, t_nbr **head_b)
{
	int	max;
	int	lstsize;

	max = ft_max_value(head_b);
	//printf("max es %d\n", max);
	lstsize = ft_slst(head);
	if (ft_check_sort(head, lstsize + 1))
	{
		if ((*head_b)->data == max)
			return (1);
		else if ((*head_b)->next == NULL)
			return (1);
	}
	return (0);
}
