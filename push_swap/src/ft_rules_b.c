/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 09:57:42 by irifarac          #+#    #+#             */
/*   Updated: 2022/07/11 09:50:04 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_push_swap.h"

void	ft_rrb(t_nbr **head_b)
{
	
	t_nbr	*last;
	t_nbr	*sec_last;

	last = *head_b;
	sec_last = NULL;
	while (last->next != NULL)
	{
		sec_last = last;
		last = last->next;
	}
	sec_last->next = NULL;
	last->next = *head_b;
	*head_b = last;
	ft_update_index(*head_b);
	write(1, "rrb\n", 4);
}

void	ft_sb(t_nbr **head_b)
{

	t_nbr	*new_head;

	new_head = (*head_b)->next;
	(*head_b)->next = (*head_b)->next->next;
	new_head->next = *head_b;
	*head_b = new_head;
	ft_update_index(*head_b);
	write(1, "sb\n", 3);
}


void	ft_rb(t_nbr **head_b)
{
	t_nbr	*first;
	t_nbr	*last;

	first = *head_b;
	last = *head_b;
	while (last->next != NULL)
		last = last->next;
	*head_b = first->next;
	first->next = NULL;
	last->next = first;
	ft_update_index(*head_b);
	write(1, "rb\n", 3);
}

void	ft_ss(t_nbr **head, t_nbr **head_b)
{
	ft_sa(head);
	ft_sb(head_b);
	write(1, "ss\n", 3);
}

void	ft_rr(t_nbr **head, t_nbr **head_b)
{
	ft_ra(head);
	ft_rb(head_b);
	write(1, "rr\n", 3);
}
