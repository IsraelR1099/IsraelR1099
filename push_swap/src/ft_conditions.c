/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conditions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 20:18:21 by irifarac          #+#    #+#             */
/*   Updated: 2022/07/13 13:49:25 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_push_swap.h"

int	ft_condition_rra(t_nbr **head, int counter)
{
	int		nbr;
	int		up;
	int		down;
	t_nbr	*tmp;
	t_nbr	*node;

	tmp = *head;
	nbr = ft_groups(counter);
	up = ft_diff_up(head, nbr);
	down = ft_diff_down(head, nbr);
	//printf("up es %d y down %d\n", up, down);
	node = ft_lastnode(tmp);
	tmp = *head;
	if (tmp->data > node->data && ft_pcheck(head))
		return (1);
	else if (ft_pcheck(head))
		return (1);
	else if (tmp->priority != 0 && node->priority != 0 &&
			down < up)
		return (1);
	else if (ft_go_check(head))
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
//	printf("last rrb es %d\n", last);
	tmp = *head_b;
	if (last > tmp->data)
		return (1);
	return (0);
}

int	ft_condition_sa(t_nbr **head)
{
	t_nbr	*tmp;

//	printf("hola en sa\n");
	tmp = *head;
	if (tmp->data > tmp->next->data &&
		tmp->priority == 0 &&
		tmp->next->priority == 0)
		return (1);
	else if (tmp->next->data < tmp->data &&
			tmp->next->priority == 0)
		return (1);
	else if (tmp->priority != 0 &&
		tmp->next->priority != 0 &&
		tmp->priority < tmp->next->priority)
		return (1);
	//printf("final sa\n");
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
	int		last;

	tmp = *head;
	while (tmp)
	{
		if (tmp->priority == 0)
			return (0);
		tmp = tmp->next;
	}
	tmp = *head;
	while (tmp)
	{
		last = tmp->data;
		tmp = tmp->next;
	}
	if ((*head)->data > last)
		return (1);
	return (0);
}
