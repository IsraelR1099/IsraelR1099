/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ways_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:07:01 by irifarac          #+#    #+#             */
/*   Updated: 2022/07/10 20:56:20 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_push_swap.h"

void	ft_sort_3(t_nbr **head, int counter)
{
	int	max;
	int	min;

	max = ft_max_nbr(*head);
	min = ft_min_nbr(*head);
	if (ft_check_sort(head, counter))
		return ;
	if (max == 1 && min == 2)
		ft_rra(head);
	else if (max == 1 && min == 0)
	{
		ft_rra(head);
		ft_sa(head);
	}
	else if (min == 1 && max == 2)
		ft_sa(head);
	else if (max == 0 && min == 2)
	{
		ft_sa(head);
		ft_rra(head);
	}
	else if (max == 0 && min == 1)
		ft_ra(head);
}

void	ft_sort_4(t_nbr **head, t_nbr **head_b, int counter)
{
	int	min;
	int	max;

	min = ft_min_nbr(*head);
	max = ft_max_nbr(*head);
	if (ft_check_sort(head, counter))
		return ;
	if (min == 0)
	{
		ft_pb(head, head_b);
		ft_sort_3(head, counter);
		ft_pa(head, head_b);
	}
	else if (max == 0)
		ft_utilsort_max4(head, head_b, counter);
	else if (min == 1 || max == 1)
	{
		ft_sa(head);
		ft_sort_4(head, head_b, counter);
	}
	else if (min == 3 || max == 3)
	{
		ft_rra(head);
		ft_sort_4(head, head_b, counter);
	}
}

void	ft_sort_5(t_nbr **head, t_nbr **head_b, int counter)
{
	int	min;
	int	max;

	min = ft_min_nbr(*head);
	max = ft_max_nbr(*head);
	if (ft_check_sort(head, counter))
		return ;
	if (min == 0)
		ft_utilsort_min5(head, head_b, counter);
	else if (max == 0)
		ft_utilsort_max5(head, head_b, counter);
	else if (min == 1 || max == 1)
	{
		ft_sa(head);
		ft_sort_5(head, head_b, counter);
	}
	else if (min == 4 || max == 4)
		ft_utilsort_m4(head, head_b, counter);
	else if (min == 3 || max == 3)
	{
		ft_rra(head);
		ft_sort_5(head, head_b, counter);
	}
}

void	ft_algorithm(t_nbr **head, t_nbr **head_b, int counter)
{
	t_nbr	*tmp;
	t_nbr	*tmp_b;
	int		i;

	tmp = *head;
	tmp_b = *head_b;
	ft_priority(head, counter);
	i = 0;
/*	while (tmp && i++ < 25)
	{
	//	printf("head b es %d\n", (*head_b)->data);
	//	printf("head a es %d y tmp es %d\n", (*head)->data, tmp->data);
		if (tmp->data < tmp->next->data && tmp->priority == 0)
			ft_apply_pb(head, head_b, &tmp);
		else if (ft_pcheck(head) && tmp->priority != 0 && tmp->next->priority != 0)
			ft_apply_rra(head, &tmp);
		else
		{
			if (tmp_b->next != NULL && tmp_b->data < tmp_b->next->data)
				ft_apply_ss(head, head_b, &tmp, &tmp_b);
			else
				ft_apply_sa(head, &tmp);
		}
	}
*/
	while (!ft_check_sort(head, counter) && ft_lstsize(head) < (counter - 1))
	{
		if (ft_condition_rra(head) && ft_condition_rrb(head_b))
			ft_rrr(head, head_b);
		else if (ft_condition_rra(head))
			ft_rra(head);
		else if (ft_condition_rrb(head_b)
			ft_rrb(head_b);
		else if (ft_condition_sa(head) && ft_condition_sb(head_b))
			ft_ss(head, head_b);
		else if (ft_condition_sa(head)
			ft_sa(head);
		else if (ft_condition_sb(head_b)
			ft_sb(head_b);
		else if (ft_condition_ra(head) && ft_condition_ra(head_b))
			ft_rr(head, head_b);
		else if (ft_condition_ra(head);
			ft_ra(head);
		else if (ft_condition_rb(head_b))
			ft_rb(head_b);
		else if (ft_condition_pb(head))
			ft_pb(head, head_b);
		else if (ft_condition_pa(head, head_b, counter);
			ft_pa(head, head_b);
	}
	tmp = *head;
	while (tmp)
	{
		printf("data es %d e index %d i priority es %d\n", tmp->data, tmp->index, tmp->priority);
		tmp = tmp->next;
	}
	while (*head_b)
	{
		printf("data b es %d y priority es %d\n", (*head_b)->data, (*head_b)->priority);
		*head_b = (*head_b)->next;
	}
}


