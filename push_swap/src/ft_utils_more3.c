/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_more3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 12:53:27 by irifarac          #+#    #+#             */
/*   Updated: 2022/07/14 13:02:17 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_push_swap.h"

int	ft_diff_down(t_nbr **head)
{
	t_nbr	*tmp;
	int	count;
	int	result;

	tmp = *head;
	count = 0;
	result = 0;
	while (tmp)
	{
		if (tmp->priority == 0)
			count = tmp->data;
		tmp = tmp->next;
	}
	tmp = *head;
	while (tmp && tmp->data != count)
	{
		result++;
		tmp = tmp->next;
	}
	return (ft_slst(head) - result);
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
	printf("len es %d y counter es %d\n", len, counter - 1);
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

int	ft_go_check(t_nbr **head)
{
	t_nbr	*tmp;
	int		up;
	int		down;
	int		size;

	tmp = *head;
	size = ft_slst(head);
	up = 0;
	while (tmp && tmp->priority != 0)
	{
		up++;
		tmp = tmp->next;
	}
	down = size - (up + 1);
	if (down < up && up != size)
		return (1);
	return (0);
}
