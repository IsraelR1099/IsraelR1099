/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_more.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 11:48:57 by irifarac          #+#    #+#             */
/*   Updated: 2022/07/04 13:55:01 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_push_swap.h"

void	ft_utilsort_m4(t_nbr **head, t_nbr **head_b, int counter)
{
	ft_rra(head);
	ft_sort_5(head, head_b, counter);
}

void	ft_utilsort_max4(t_nbr **head, t_nbr **head_b, int counter)
{
	if (ft_check_sort(&(*head)->next, counter))
		ft_ra(head);
	else
	{
		ft_pb(head, head_b);
		ft_sort_3(head, counter);
		ft_pa(head, head_b);
		ft_ra(head);
	}
}

void	ft_utilsort_max5(t_nbr **head, t_nbr **head_b, int counter)
{
	if (ft_check_sort(&(*head)->next, counter))
		ft_ra(head);
	else
	{
		ft_pb(head, head_b);
		ft_sort_4(head, head_b, counter);
		ft_pa(head, head_b);
		ft_ra(head);
	}
}

int	ft_groups(int counter)
{
	int	nbr;
	int	count;
	int	distance;

	nbr = 0;
	count = 0;
	while (count < (counter - 1))
	{
		nbr = count * count;
		distance = ((count + 1) * (count + 1)) - nbr;
		if (nbr == (counter - 1))
			return (count);
		else if ((nbr + distance) > (counter - 1))
		{
			if ((counter - 1) > (nbr + (distance / 2)))
				return (count + 1);
			else
				return (count);
		}
		count++;
	}
	return (count);
}

void	ft_index(t_nbr **head, int counter)
{
	t_nbr	*tmp;
	t_nbr	*tmp2;
	int		nbr;
	int		i;

	tmp = *head;
	i = 1;
	(void)counter;
	while (tmp)
	{
		tmp2 = *head;
		nbr = tmp->data;
		while (tmp2)
		{
			if (tmp2->data < nbr)
			{
				tmp2->index = 1;
				tmp->index = tmp2->index + 1;
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
		i++;
	}
}




