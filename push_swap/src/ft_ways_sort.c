/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ways_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:07:01 by irifarac          #+#    #+#             */
/*   Updated: 2022/06/16 13:30:02 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_push_swap.h"

void	ft_sort_3(t_nbr **head)
{
	int	max;
	int	min;
	
	max = ft_max_nbr(*head);
	min = ft_min_nbr(*head);
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
	ft_update_index(*head);
}

void	ft_sort_4(t_nbr **head, t_nbr **head_b)
{
	int	min;
	int	max;

	min = ft_min_nbr(*head);
	max = ft_max_nbr(*head);
	if (min == 0)
	{
		ft_pb(head, head_b);
		ft_sort_3(head);
		ft_pa(head, head_b);
	}
	else if (max == 0)
	{
		ft_pb(head, head_b);
		ft_sort_3(head);
		ft_pa(head, head_b);
		ft_ra(head);
		ft_update_index(*head);
	}
	else if (min == 1 || max == 1)
	{
		ft_sa(head);
		ft_update_index(*head);
		ft_sort_4(head, head_b);
	}
	else if (min == 3 || max == 3)
	{
		ft_rra(head);
		ft_update_index(*head);
		ft_sort_4(head, head_b);
	}
}

void	ft_sort_5(t_nbr **head, t_nbr **head_b)
{
	int	min;
	int	max;

	min = ft_min_nbr(*head);
	max = ft_max_nbr(*head);
	(void)max;
	if (min == 0)
	{
		ft_pb(head, head_b);
		ft_update_index(*head);
		ft_sort_4(head, head_b);
		/*printf("salgo de sort 4\n");
		printf("data stack a es %d\n", (*head)->data);
		printf("data stack a es %d\n", (*head)->next->data);
		printf("data stack a es %d\n", (*head)->next->next->data);
		printf("data stack a es %d\n", (*head)->next->next->next->data);
		printf("pb es %d\n", (*head_b)->data);*/
		ft_pa(head, head_b);
/*		printf("data stack a es %d\n", (*head)->data);
		printf("data stack a es %d\n", (*head)->next->data);
		printf("data stack a es %d\n", (*head)->next->next->data);
		printf("data stack a es %d\n", (*head)->next->next->next->data);
		printf("data stack a es %d\n", (*head)->next->next->next->next->data);*/
	}
	while (*head)
	{
		printf("data de stack a es %d e indice %d\n", (*head)->data, (*head)->index);
		*head = (*head)->next;
	}
	while (*head_b)
	{
		printf("data de head b es %d e indice %d\n", (*head_b)->data, (*head_b)->index);
		*head_b = (*head_b)->next;
	}
}
