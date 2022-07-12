/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_more3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 12:53:27 by irifarac          #+#    #+#             */
/*   Updated: 2022/07/12 15:17:38 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_push_swap.h"

int	ft_diff_down(t_nbr **head, int nbr)
{
	t_nbr	*tmp;
	int		iter;
	int		result;
	int		count;
	int		i;
	int		size;

	size = ft_slst(head);
	iter = (size) - nbr;
	tmp = *head;
	i = 0;
	count = 0;
	while (tmp != NULL && i < iter)
	{
		tmp = tmp->next;
		i++;
	}
	if (i == iter)
	{
		while (tmp)
		{
			if (tmp->priority != 0)
				break ;
			tmp = tmp->next;
			count++;
		}
	}
	//printf("iter es %d y count %d\n", iter, count);
	result = size - (iter + count);
	return (result);
}

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
	//printf("len es %d y counter es %d\n", len, counter - 1);
	if (len == (counter - 1))
		return (1);
	return (0);
}
