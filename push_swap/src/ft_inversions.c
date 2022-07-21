/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inversions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:36:42 by irifarac          #+#    #+#             */
/*   Updated: 2022/07/21 21:11:03 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_push_swap.h"

void	ft_inversions(t_nbr **head, t_nbr **head_b, int counter)
{
	t_nbr	*tmp;
	t_nbr	*tmp_b;
	int	nbr;

	tmp = *head;
	tmp_b = *head_b;
	nbr = tmp->data;
	if (nbr > tmp-next->data)
	{
		ft_pb(head, head_b);
		if (tmp_b->data > tmp->next->data)
			ft_sb(head_b);
	}
	else
		ft_sa(head);
}
