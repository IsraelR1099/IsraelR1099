/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conditions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 20:18:21 by irifarac          #+#    #+#             */
/*   Updated: 2022/07/14 14:09:15 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_push_swap.h"

int	ft_condition_rra(t_nbr **head)
{
	int		up;
	int		down;
	t_nbr	*tmp;
	t_nbr	*node;

	tmp = *head;
	up = ft_diff_up(head);
	down = ft_diff_down(head);
	//printf("up es %d y down %d\n", up, down);
	node = ft_lastnode(tmp);
	if (tmp->data > node->data &&
		!ft_pcheck(head);
		return (1);
	else if (ft_pcheck(head) && down < up)
		return (1);
	else if (ft_pcheck(head) &&
		node->priority > tmp->priority)
		return (1);
	return (0);
}

int	ft_condition_rrb(t_nbr **head_b)
{
	t_nbr	*tmp;
	int		last;

	if ((*head_b)->next == NULL)
		return (0);
	tmp = *head_b;
	last = 0;
	while (tmp != NULL)
	{
		last = tmp->data;
		tmp = tmp->next;
	}
	tmp = *head_b;
	if (last > tmp->data)
		return (1);
	return (0);
}

int	ft_condition_sa(t_nbr **head)
{
	t_nbr	*tmp;
	t_nbr	*last;

	tmp = *head;
	last = ft_lastnode(tmp);
	if (!ft_pcheck(head) && 
		tmp->next->data < tmp->data &&
		tmp->next->data < last->data)
		return (1);
	if (tmp->data > tmp->next->data)
		return (1);
	return (0);
}

int	ft_condition_sb(t_nbr **head_b)
{
	t_nbr	*tmp;

	if ((*head_b)->next == NULL)
		return (0);
	tmp = *head_b;
	if (tmp->data < tmp->next->data)
		return (1);
	return (0);
}

int	ft_condition_ra(t_nbr **head)
{
	t_nbr	*tmp;
	t_nbr	*last;
	tmp = *head;
	last = ft_lastnode(tmp);
	if (ft_pcheck(head) &&
		tmp->priority < last->priority)
		return (1);		
	return (0);
}
