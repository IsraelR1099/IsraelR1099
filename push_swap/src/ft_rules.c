/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:32:05 by irifarac          #+#    #+#             */
/*   Updated: 2022/06/10 12:45:16 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_push_swap.h"

void	ft_rra(t_nbr **head)
{
	t_nbr	*last;
	t_nbr	*sec_last;

	last = *head;
	sec_last = NULL;
	while (last->next != NULL)
	{
		sec_last = last;
		last = last->next;
	}
	sec_last->next = NULL;
	last->next = *head;
	*head = last;
}

void	ft_sa(t_nbr **head)
{
	t_nbr	*new_head;
	t_nbr	*second;

	second = *head;
	*head = (*head)->next;
	(*head)->next = second;
	second->next = second->next->next;
	
}

void	ft_ra(t_nbr **head)
{
	t_nbr	*first;
	t_nbr	*last;

	first = *head;
	last = *head;
	while (last->next != NULL)
		last = last->next;
	*head = first->next;
	first->next = NULL;
	last->next = first;
}
