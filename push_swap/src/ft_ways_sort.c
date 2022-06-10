/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ways_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:07:01 by irifarac          #+#    #+#             */
/*   Updated: 2022/06/10 12:43:15 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_push_swap.h"

void	ft_sort_3(t_nbr *head)
{
	int	max;
	int	min;
	
	max = ft_max_nbr(head);
	min = ft_min_nbr(head);
	if (max == 1 && min == 2)
		ft_rra(&head);
	else if (max == 1 && min == 0)
	{
		ft_rra(&head);
		ft_sa(&head);
	}
	else if (min == 1 && max == 2)
		ft_sa(&head);
	else if (max == 0 && min == 2)
	{
		ft_sa(&head);
		ft_rra(&head);
	}
	else if (max == 0 && min == 1)
		ft_ra(&head);
	ft_write(max, min);
	while (head)
	{
		printf("data es %d\n", head->data);
		head = head->next;
	}
}
