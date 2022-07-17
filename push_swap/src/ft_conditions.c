/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conditions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 20:18:21 by irifarac          #+#    #+#             */
/*   Updated: 2022/07/17 20:37:24 by irifarac         ###   ########.fr       */
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
//	if (down < 0)
//		return (0);
//	printf("up en rra es %d y down %d\n", up, down);
	node = ft_lastnode(tmp);
	if (tmp->data > node->data &&
		!ft_pcheck(head))
		return (1);
	else if (ft_pcheck(head) && down < up && down >= 0)
		return (1);
	else if (ft_pcheck(head) == 2 &&
		node->priority > tmp->priority &&
		tmp->priority != 1)
		return (1);
	return (0);
}

int	ft_condition_rrb(t_nbr **head_b)
{
	t_nbr	*tmp;
	int		last;
	int		up;
	int		down;

	if ((*head_b) == NULL || (*head_b)->next == NULL)
		return (0);
	tmp = *head_b;
	last = 0;
	up = ft_diff_upb(head_b);
	down = ft_diff_downb(head_b);
//	printf("up en rrb es %d y down %d\n", up, down);
	while (tmp != NULL)
	{
		last = tmp->data;
		tmp = tmp->next;
	}
	tmp = *head_b;
	if (last > tmp->data)
		return (1);
	else if (last < tmp->data && down < up)
		return (down);
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
	else if (tmp->data > tmp->next->data)
		return (1);
	else if (ft_pcheck(head) && tmp->priority < tmp->next->priority)
		return (1);
//	printf("salgo de sa\n");
	return (0);
}

int	ft_condition_sb(t_nbr **head_b)
{
	t_nbr	*tmp;
	t_nbr	*last;

	//printf("entramos en sb\n");
	if ((*head_b) == NULL || (*head_b)->next == NULL)
		return (0);
	tmp = *head_b;
	last = ft_lastnode(tmp);
	//printf("salimos de sb\n");
	if (tmp->data < tmp->next->data &&
			tmp->data > last->data)
		return (1);
	return (0);
}

int	ft_condition_ra(t_nbr **head)
{
	t_nbr	*tmp;
	t_nbr	*last;
	
//	printf("entro en ra\n");
	tmp = *head;
	last = ft_lastnode(tmp);
	if (ft_pcheck(head) == 2 &&
		tmp->priority < last->priority)
	{
//		printf("primera condition en ra\n");
		return (1);
	}
	else if (ft_pcheck(head) == 2 &&
		tmp->next->next->priority == (tmp->priority - 1))
	{
//		printf("segunda condition en ra\n");
		return (1);
	}
	else if (ft_pcheck(head) == 2 &&
		tmp->next->priority < tmp->priority)
		return (1);
//	printf("salgo de ra\n");
	return (0);
}
