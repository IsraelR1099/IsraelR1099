/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ways_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:07:01 by irifarac          #+#    #+#             */
/*   Updated: 2022/06/14 14:06:09 by irifarac         ###   ########.fr       */
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
	{
		printf("data 1 es %d\n", (*head)->data);
		printf("data 2 es %d\n", (*head)->next->data);
		printf("data 3 es %d\n", (*head)->next->next->data);
		printf("hola\n");
		ft_sa(head);
		printf("data 1 es %d e indice %d\n", (*head)->data, (*head)->index);
		printf("data 2 es %d e indice %d\n", (*head)->next->data, (*head)->next->index);
		printf("data 3 es %d e indice %d\n", (*head)->next->next->data, (*head)->next->next->index);
	}
	else if (max == 0 && min == 2)
	{
		ft_sa(head);
		ft_rra(head);
	}
	else if (max == 0 && min == 1)
		ft_ra(head);
	ft_update_index(*head);
	ft_write(max, min);
}

void	ft_sort_4(t_nbr **head, t_nbr **head_b)
{
	int	min;

	min = ft_min_nbr(*head);
	if (min == 0)
	{
		ft_pb(head, head_b);
		ft_sort_3(head);
		//ft_pa(head, head_b);
	}
/*	while (*head)
	{
		printf("data es %d e indice %d\n", (*head)->data, (*head)->index);
		*head = (*head)->next;
	}
	while (*head_b)
	{
		printf("data de head b es %d e indice %d\n", (*head_b)->data, (*head_b)->index);
		*head_b = (*head_b)->next;
	}*/
}
