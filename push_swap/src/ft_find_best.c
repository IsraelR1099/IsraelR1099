/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_best.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 13:54:19 by irifarac          #+#    #+#             */
/*   Updated: 2022/08/05 13:14:08 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_push_swap.h"

int	ft_best_way(t_nbr **head, int counter)
{
	int	nbr;
	int	nbr_last;
	int	pnbr;
	int	pnbr2;
	int	group;

	group = ft_groups(counter);
	if (ft_slst(head) <= (2 * group))
	{
		pnbr = ft_best_sizeup(head, counter);
		pnbr2 = ft_best_sizeb(head, counter);
		if (pnbr2 > pnbr)
			return (2);
	}
	nbr = ft_best_up(head, counter);
	nbr_last = ft_best_down(head, counter);
	if (nbr_last < nbr)
		return (2);
	return (1);
}

int	ft_best_up(t_nbr **head, int counter)
{
	t_nbr	*tmp;
	int     len;
	int     group;
	int     nbr;

	tmp = *head;
	group = ft_groups(counter);
	len = 0;
	nbr = 0;
	while (tmp && len < group)
	{
		if (tmp->priority == 0)
			nbr += tmp->data;
		tmp = tmp->next;
		len ++;
	}
	return (nbr);
}

int	ft_best_down(t_nbr **head, int counter)
{
	int     nbr_last;
	int     len;
	int     group;
	int     size;
	t_nbr	*tmp;

	size = ft_slst(head);
	group = ft_groups(counter);
	nbr_last = 0;
	len = 0;
	tmp = *head;
	while (tmp)
	{
		if (len == (size - group))
		{
			while (tmp)
			{
				if (tmp->priority == 0)
					nbr_last += tmp->data;
				tmp = tmp->next;
			}
		}
		if (!tmp)
			break ;
		len++;
		tmp = tmp->next;
	}
	return (nbr_last);
}

int	ft_best_sizeb(t_nbr **head, int counter)
{
	t_nbr	*tmp;
	int	pnbr2;
	int	len;
	int	size;
	int	group;

	pnbr2 = 0;
	tmp = *head;
	len = 0;
	size = ft_slst(head);
	group = ft_groups(counter);
	while (tmp)
	{
		if (len == (size - group))
		{
			while (tmp)
			{
				if (tmp->priority == 0)
					pnbr2++;
				tmp = tmp->next;
			}
		}
		if (!tmp)
			break ;
		len++;
		tmp = tmp->next;
	}
	return (pnbr2);
}

int	ft_best_sizeup(t_nbr **head, int counter)
{
	t_nbr	*tmp;
	int	pnbr;
	int	len;
	int	group;

	pnbr = 0;
	len = 0;
	tmp = *head;
	group = ft_groups(counter);
	while (tmp && len < group)
	{
		if (tmp->priority == 0)
			pnbr++;
		tmp = tmp->next;
		len++;
	}
	return (pnbr);
}
