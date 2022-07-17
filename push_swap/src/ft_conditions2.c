/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conditions2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:28:39 by irifarac          #+#    #+#             */
/*   Updated: 2022/07/17 15:01:23 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_push_swap.h"

int	ft_condition_rb(t_nbr **head_b, t_nbr **head, int counter)
{
	t_nbr	*tmp;
	int		last;
	int		up;
	int		down;
	int		max;

	if ((*head_b) == NULL || (*head_b)->next == NULL)
		return (0);
//	printf("hola en rb\n");
	tmp = *head_b;
	up = ft_diff_upb(head_b);
	down = ft_diff_downb(head_b);
	max = ft_max_value(head_b);
//	printf("up en rb es %d y down %d\n", up, down);
	while (tmp)
	{
		last = tmp->data;
		tmp = tmp->next;
	}
	tmp = *head_b;
	//printf("last es %d\n", last);
	if (tmp->data < last &&
		tmp->data < tmp->next->data &&
		last != max)
		return (1);
	else if (ft_pcheck(head) == 2 && 
			tmp->data > tmp->next->data &&
			tmp->data > last && up < down &&
			tmp->data != max)
		return (up);
	else if (ft_check_sort(head, counter) &&
			tmp->data > tmp->next->data &&
			tmp->data > last && up < down)
		return (up);
	else if (down == up)
		return (up);
//	printf("salimos de rb\n");
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
//	printf("max es %d\n", max);
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
