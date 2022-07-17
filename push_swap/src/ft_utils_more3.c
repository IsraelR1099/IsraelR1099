/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_more3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 12:53:27 by irifarac          #+#    #+#             */
/*   Updated: 2022/07/16 13:48:44 by irifarac         ###   ########.fr       */
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
	result = 1;
	while (tmp)
	{
		if (tmp->priority == 0)
			count = tmp->data;
		tmp = tmp->next;
	}
//	printf("count es %d\n", count);
	tmp = *head;
	while (tmp && tmp->data != count)
	{
		result++;
		tmp = tmp->next;
	}
//	printf("result es %d\n", result);
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
//	printf("len es %d y counter es %d\n", len, counter - 1);
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

int	ft_diff_upb(t_nbr **head_b)
{
	int		max;
	int		result;
	t_nbr	*tmp;

	max = ft_max_value(head_b);
	tmp = *head_b;
	result = 0;
	while (tmp)
	{
		result++;
		if (tmp->data == max)
			break ;
		tmp = tmp->next;
	}
	return (result);
}

int	ft_diff_downb(t_nbr **head_b)
{
	int		max;
	int		result;
	t_nbr	*tmp;

	max = ft_max_value(head_b);
	tmp = *head_b;
	result = 0;
	while (tmp)
	{
		if (tmp->data == max)
		{
			while (tmp)
			{
				result++;
				tmp = tmp->next;
			}
		}
		if (!tmp)
			break ;
		tmp = tmp->next;
	}
	return (result);
}
