/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_more.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 11:48:57 by irifarac          #+#    #+#             */
/*   Updated: 2022/06/20 12:45:07 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_push_swap.h"

void	ft_utilsort_m4(t_nbr **head, t_nbr **head_b, int counter)
{
	ft_rra(head);
	ft_sort_5(head, head_b, counter);
}

void	ft_utilsort_max4(t_nbr **head, t_nbr **head_b, int counter)
{
	if (ft_check_sort(&(*head)->next, counter))
		ft_ra(head);
	else
	{
		ft_pb(head, head_b);
		ft_sort_3(head, counter);
		ft_pa(head, head_b);
		ft_ra(head);
	}
}

void	ft_utilsort_max5(t_nbr **head, t_nbr **head_b, int counter)
{
	if (ft_check_sort(&(*head)->next, counter))
		ft_ra(head);
	else
	{
		ft_pb(head, head_b);
		ft_sort_4(head, head_b, counter);
		ft_pa(head, head_b);
		ft_ra(head);
	}
}
