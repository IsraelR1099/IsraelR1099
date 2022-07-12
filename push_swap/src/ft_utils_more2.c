/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_more2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:46:27 by irifarac          #+#    #+#             */
/*   Updated: 2022/07/12 14:05:34 by irifarac         ###   ########.fr       */
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
	i = 0;
	while (tmp)
	{
		i = 0;
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
/*	tmp = *head;
	while (tmp)
	{
		printf("data es %d y priority es %d\n", tmp->data, tmp->priority);
		tmp = tmp->next;
	}*/
}

int	ft_pcheck(t_nbr **head)
{
	t_nbr	*tmp;
	t_nbr	*last;
	int		cmp;

	tmp = *head;
	last = NULL;
	while (tmp != NULL)
	{
		last = tmp;
		tmp = tmp->next;
	}
	tmp = *head;
	while (tmp && tmp->priority != 0)
	{
		cmp = tmp->data;
		tmp = tmp->next;
	}
	tmp = *head;
	if (last->priority == 0 && tmp->data > last->data)
		return (1);
	if (tmp->priority == 0 && last->priority == 0)
		return (1);
	else
		return (0);
	if (tmp->priority == 0 && tmp->next->priority == 0)
		return (1);
	else
		return (0);
	if (cmp == last->data && tmp->priority < last->priority)
		return (1);
	else
		return (0);
	return (0);
}

int	ft_slst(t_nbr **head)
{
	t_nbr	*tmp;
	int		counter;

	counter = 0;
	tmp = *head;
	while (tmp != NULL)
	{
		counter++;
		tmp = tmp->next;
	}
	return (counter);
}

int	ft_diff_up(t_nbr **head, int nbr)
{
	t_nbr	*tmp;
	int		counter;

	tmp = *head;
	counter = 0;
	while (nbr && tmp)
	{
		if (tmp->priority == 0)
			break ;
		nbr--;
		counter++;
		tmp = tmp->next;
	}
	return (counter);
}
