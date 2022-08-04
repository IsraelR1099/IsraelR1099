/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inversions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:36:42 by irifarac          #+#    #+#             */
/*   Updated: 2022/07/24 17:15:34 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_push_swap.h"

void	ft_inversions(t_nbr **head, t_nbr **head_b, int counter)
{
	t_nbr	*tmp;
	t_nbr	*tmp_b;
	int	nbr;

	tmp = *head;
	tmp_b = *head_b;
	nbr = tmp->priority;
	(void)counter;
	if (nbr > tmp->next->priority)
	{
		ft_pb(head, head_b);
		if (tmp_b->data > tmp_b->next->data &&
				tmp_b->next->priority != 0)
			ft_sb(head_b);
	}
	else
		ft_sa(head);
}

int	ft_times(t_nbr **head, t_nbr **head_b)
{
	t_nbr	*tmp;
	t_nbr	*tmp_b;
	int		times;
	int		priority;

	times = 0;
	tmp_b = *head_b;
	tmp = *head;
	priority = tmp_b->priority;
	if (tmp->priority == (priority + 1))
		return (1);
	while (tmp)
	{
		if (tmp->priority == (priority + 1))
			return (times);
		else if (tmp->priority == (priority - 1))
			return (times);
		tmp = tmp->next;
		times++;
	}
	if (times == ft_slst(head))
		times = ft_times_space(head, head_b);
	return (times);
}

int	ft_times_space(t_nbr **head, t_nbr **head_b)
{
	t_nbr	*tmp;
	t_nbr	*tmp_b;
	int		times;
	int		prior;

	times = 0;
	tmp = *head;
	tmp_b = *head_b;
	prior = tmp_b->priority;
	while (tmp)
	{
		if (prior < tmp->priority &&
				prior > tmp->next->priority)
			return (times);
		tmp = tmp->next;
		times++;
	}
	return (0);
}

int	ft_times_noprio(t_nbr **head, t_nbr **head_b)
{
	t_nbr	*tmp;
	t_nbr	*tmp_b;
	int		times;
	int		nbr;

    if (head_b == NULL)
    {
        return (0);
    }
    times = 0;
    tmp_b = *head_b;
    tmp = *head;
    nbr = tmp_b->data;
	while (tmp)
	{
		if (tmp->data > nbr)
			return (times);
		tmp = tmp->next;
		times++;
	}
	return (times);
}
