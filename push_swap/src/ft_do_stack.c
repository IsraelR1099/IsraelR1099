/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 20:49:19 by irifarac          #+#    #+#             */
/*   Updated: 2022/07/22 11:39:43 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_push_swap.h"

int	ft_do_both(t_nbr **head, t_nbr **head_b, int counter)
{
	//printf("hola en do both\n");
	if (ft_condition_sa(head) && ft_condition_sb(head_b))
	{
//		printf("dentro de sa do both\n");
		ft_ss(head, head_b);
		return (1);
//		printf("salgo de sa both\n");
	}
	else if (ft_condition_rra(head) && ft_condition_rrb(head_b))
	{
//		printf("dentro de rra do both\n");
		ft_rrr(head, head_b);
		return (1);
//		printf("salgo de rra both\n");
	}
	else if (ft_condition_ra(head) && ft_condition_rb(head_b, head, counter))
	{
		//printf("entro en do both rr\n");
		ft_rr(head, head_b);
		return (1);
	}
//	printf("fura de do both\n");
	return (0);
}

void	ft_do_stacka(t_nbr **head)
{
	//printf("entro en do stack\n");
	if (ft_condition_sa(head))
		ft_sa(head);
	else if (ft_condition_rra(head))
		ft_rra(head);
	else if (ft_condition_ra(head))
	{
		//printf("hola en ra en stack\n");
		ft_ra(head);
	}
}

void	ft_do_stackb(t_nbr **head_b, t_nbr **head, int counter)
{
	int	nrb;
	int	nrrb;

//	printf("en stackb\n");
	nrb = ft_condition_rb(head_b, head, counter);
	nrrb = ft_condition_rrb(head_b);
	if (nrb)
	{
		while (nrb)
		{
//			printf("estoy aqui\n");
			ft_rb(head_b);
			nrb--;
		}
	}
	else if (ft_condition_sb(head_b))
		ft_sb(head_b);
	else if (nrrb)
	{
		while (nrrb)
		{
			ft_rrb(head_b);
			nrrb--;
		}
	}
}
