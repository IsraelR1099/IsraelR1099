/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_more3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 12:53:27 by irifarac          #+#    #+#             */
/*   Updated: 2022/08/10 17:47:01 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_push_swap.h"

int	ft_is_sort(t_nbr **head, int counter)
{
	t_nbr	*tmp;
	int		nbr;
	int		len;

	tmp = *head;
	nbr = tmp->data;
	len = 1;
	while (tmp)
	{
		if (tmp->data > nbr)
		{
			nbr = tmp->data;
			len++;
		}
		tmp = tmp->next;
	}
	if (len == (counter - 1))
		return (1);
	return (0);
}

t_nbr	*ft_lastnode(t_nbr *tmp)
{
	t_nbr	*node;
	t_nbr	*temp;

	temp = tmp;
	while (temp)
	{
		node = temp;
		temp = temp->next;
	}
	return (node);
}
