/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:18:11 by irifarac          #+#    #+#             */
/*   Updated: 2022/08/12 12:26:02 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_push_swap.h"

int	ft_max_nbr(t_nbr *head)
{
	t_nbr	*tmp;
	int		nbr;

	tmp = head;
	nbr = 0;
	while (tmp)
	{
		if (nbr == 0)
			nbr = tmp->data;
		if (nbr < tmp->data)
			nbr = tmp->data;
		tmp = tmp->next;
	}
	tmp = head;
	while (tmp)
	{
		if (tmp->data == nbr)
			return (tmp->index);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_min_nbr(t_nbr *head)
{
	t_nbr	*tmp;
	int		nbr;

	tmp = head;
	nbr = 0;
	while (tmp)
	{
		if (nbr == 0)
			nbr = tmp->data;
		if (nbr > tmp->data)
			nbr = tmp->data;
		tmp = tmp->next;
	}
	tmp = head;
	while (tmp)
	{
		if (tmp->data == nbr)
			return (tmp->index);
		tmp = tmp->next;
	}
	return (0);
}

void	ft_update_index(t_nbr *head)
{
	int		nbr;
	t_nbr	*tmp;

	nbr = 0;
	if (head->index != 0 || head->next->index != 1)
	{
		tmp = head;
		while (tmp)
		{
			tmp->index = nbr;
			nbr++;
			tmp = tmp->next;
		}
	}
}

int	ft_max_value(t_nbr **head)
{
	t_nbr	*tmp;
	int		nbr;

	tmp = *head;
	nbr = MIN_INT;
	while (tmp)
	{
		if (nbr == MIN_INT)
			nbr = tmp->data;
		if (nbr < tmp->data)
			nbr = tmp->data;
		tmp = tmp->next;
	}
	tmp = *head;
	while (tmp)
	{
		if (tmp->data == nbr)
			return (tmp->data);
		tmp = tmp->next;
	}
	return (0);
}
