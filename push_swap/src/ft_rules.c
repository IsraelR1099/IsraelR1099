/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:32:05 by irifarac          #+#    #+#             */
/*   Updated: 2022/08/10 17:54:35 by irifarac         ###   ########.fr       */
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
	ft_update_index(*head);
	write(1, "rra\n", 4);
}

void	ft_sa(t_nbr **head)
{
	t_nbr	*new_head;

	new_head = (*head)->next;
	(*head)->next = (*head)->next->next;
	new_head->next = *head;
	*head = new_head;
	ft_update_index(*head);
	write(1, "sa\n", 3);
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
	ft_update_index(*head);
	write(1, "ra\n", 3);
}

void	ft_pb(t_nbr **head, t_nbr **head_b)
{
	t_nbr	*tmp;
	t_nbr	*tmp_b;

	tmp = (*head)->next;
	if (!(*head_b)->next && (*head_b)->data == 0)
	{
		tmp_b = *head_b;
		free(tmp_b);
		(*head)->next = NULL;
		*head_b = *head;
		*head = tmp;
	}
	else
	{
		(*head)->next = *head_b;
		*head_b = *head;
		*head = tmp;
	}
	ft_update_index(*head);
	write(1, "pb\n", 3);
}

void	ft_pa(t_nbr **head, t_nbr **head_b)
{
	t_nbr	*tmp;

	if ((*head_b)->next == NULL)
	{
		tmp = *head_b;
		*head_b = NULL;
		tmp->next = *head;
		*head = tmp;
	}
	else
	{
		tmp = (*head_b)->next;
		(*head_b)->next = *head;
		*head = *head_b;
		*head_b = tmp;
	}
	ft_update_index(*head);
	write(1, "pa\n", 3);
}
