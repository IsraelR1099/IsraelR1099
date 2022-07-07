/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 12:18:56 by irifarac          #+#    #+#             */
/*   Updated: 2022/07/07 13:55:10 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_push_swap.h"

void	ft_apply_pb(t_nbr **head, t_nbr **head_b, t_nbr **tmp)
{
	t_nbr	*temp;
	t_nbr	*last_b;

	ft_pb(head, head_b);
	*tmp = *head;
	temp = *head_b;
	while (temp->next)
	{
		temp = temp->next;
	}
	last_b = temp;
	printf("last b es %d\n", last_b->data);
	if ((*head_b)->data < (*head_b)->next->data)
	{
		printf("hola\n");
		if ((*head_b)->data < last_b->data)
			ft_rb(head_b);
		else
			ft_sb(head_b);
	}
}

void	ft_apply_rra(t_nbr **head, t_nbr **tmp)
{
	ft_rra(head);
	*tmp = *head;
}

void	ft_apply_ss(t_nbr **head, t_nbr **head_b, t_nbr **tmp, t_nbr **tmp_b)
{
	ft_ss(head, head_b);
	*tmp = *head;
	*tmp_b = *head_b;
}

void	ft_apply_sa(t_nbr **head, t_nbr **tmp)
{
	ft_sa(head);
	*tmp = *head;
}
