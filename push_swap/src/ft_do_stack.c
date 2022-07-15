/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 20:49:19 by irifarac          #+#    #+#             */
/*   Updated: 2022/07/15 13:59:13 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_push_swap.h"

int	ft_do_both(t_nbr **head, t_nbr **head_b)
{
	if (ft_condition_sa(head) && ft_condition_sb(head_b))
	{
		ft_ss(head, head_b);
		return (1);
	}
	else if (ft_condition_rra(head) && ft_condition_rrb(head_b))
	{
		ft_rrr(head, head_b);
		return (1);
	}
	else if (ft_condition_ra(head) && ft_condition_rb(head_b, head))
	{
		ft_rr(head, head_b);
		return (1);
	}
	return (0);
}

void	ft_do_stacka(t_nbr **head)
{
	if (ft_condition_sa(head))
		ft_sa(head);
	else if (ft_condition_rra(head))
		ft_rra(head);
	else if (ft_condition_ra(head))
		ft_ra(head);
}

void	ft_do_stackb(t_nbr **head_b, t_nbr **head)
{
	//printf("entramos en stack\n");
	if (ft_condition_rb(head_b, head))
		ft_rb(head_b);
	else if (ft_condition_sb(head_b))
		ft_sb(head_b);
	else if (ft_condition_rrb(head_b))
		ft_rrb(head_b);
}
