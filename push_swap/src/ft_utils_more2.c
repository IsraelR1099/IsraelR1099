/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_more2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:46:27 by irifarac          #+#    #+#             */
/*   Updated: 2022/07/07 11:48:37 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_push_swap.h"

int	*ft_ini(t_nbr **head, int nbr)
{
	int	*max_group;
	int	i;

	max_group = (int *)malloc(sizeof(int) * (nbr));
	if (!max_group)
	{
		ft_deallocation(head);
		return (0);
	}
	max_group[0] = ft_max_value(head);
	i = 1;
	while (i < nbr)
	{
		max_group[i] = INT_MIN;
		i++;
	}
	return (max_group);
}

void	ft_update_priority(t_nbr **head, int *max_group)
{
	t_nbr	*tmp;
	int		i;

	tmp = *head;
	i = 1;
	while (tmp)
	{
		i = 1;
		while (max_group[i])
		{
			if (max_group[i] == tmp->data)
			{
				tmp->priority = i + 1;
			}
			i++;
		}
		tmp = tmp->next;
	}
	tmp = *head;
	while (tmp)
	{
		printf("data es %d y priority es %d\n", tmp->data, tmp->priority);
		tmp = tmp->next;
	}
}

