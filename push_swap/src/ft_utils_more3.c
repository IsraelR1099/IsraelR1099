/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_more3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 12:53:27 by irifarac          #+#    #+#             */
/*   Updated: 2022/07/11 13:51:15 by irifarac         ###   ########.fr       */
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
	while (tmp)
	{
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
		i++;
		tmp = tmp->next;
	}
	//printf("iter es %d y count %d\n", iter, count);
	result = size - (iter + count);
	return (result);
}
