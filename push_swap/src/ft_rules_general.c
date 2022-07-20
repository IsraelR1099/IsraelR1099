/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules_general.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 09:50:40 by irifarac          #+#    #+#             */
/*   Updated: 2022/07/20 10:54:07 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_push_swap.h"

void	ft_rrr(t_nbr **head, t_nbr **head_b)
{
	t_nbr	*last;
	t_nbr	*sec_last;
	t_nbr	*lastb;
	t_nbr	*sec_lastb;

	last = *head;
	while (last->next != NULL)
	{
		sec_last = last;
		last = last->next;
	}
	sec_last->next = NULL;
	last->next = *head;
	*head = last;
	lastb = *head_b;
	sec_lastb = NULL;
	while (lastb->next != NULL)
	{
		sec_lastb = lastb;
		lastb = lastb->next;
	}
	sec_lastb->next = NULL;
	lastb->next = *head_b;
	*head_b = lastb;
	ft_update_index(*head_b);
	write(1, "rrr\n", 4);

}
	
