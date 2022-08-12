/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 13:55:49 by irifarac          #+#    #+#             */
/*   Updated: 2022/08/12 13:51:00 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_push_swap.h"
#include "../Libft/libft.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit (1);
}

int	ft_no_valid(char **str, int counter)
{
	int	position;
	int	index;

	position = 0;
	index = 1;
	if (!*(*(str + index) + position))
		ft_error();
	while (*(*(str + index) + position))
	{
		position++;
		if (!*(*(str + index) + position))
		{
			if (!ft_atoi(*(str + index))
				&& *(*(str + index)) != '0')
				ft_error();
			index++;
			position = 0;
			if (index == counter)
				break ;
			if (!*(*(str + index) + position))
				ft_error();
		}
	}
	return (1);
}

void	ft_check_pb(t_nbr **head, t_nbr **head_b)
{
	ft_pb(head, head_b);
	if (ft_slst(head_b) >= 2
		&& (*head_b)->data < (*head_b)->next->data)
	{
		if ((*head)->data < (*head)->next->data
			&& (*head_b)->data < (*head_b)->next->data)
			ft_ss(head, head_b);
		else
			ft_sb(head_b);
	}
}

void	ft_check_rra(t_nbr **head, t_nbr **head_b)
{
	t_nbr	*last;
	t_nbr	*last_b;

	last = ft_lastnode(*head);
	last_b = ft_lastnode(*head_b);
	if (*head_b && last->data > (*head_b)->data
		&& last->priority == 0 && last->data < (*head)->data)
		ft_rra(head);
	else if (*head_b && last->data < (*head)->data
		&& last->data > (*head_b)->data)
		ft_rra(head);
	else
	{
		if (last_b->data > (*head_b)->data)
			ft_rrb(head_b);
		else
			ft_pa(head, head_b);
	}
}

void	ft_condition_send(t_nbr **head, t_nbr **head_b)
{
	ft_pb(head, head_b);
	if (ft_slst(head_b) >= 2
		&& (*head_b)->data < (*head_b)->next->data)
	{
		if ((*head)->data < (*head)->next->data
			&& (*head_b)->data < (*head_b)->next->data)
			ft_ss(head, head_b);
		else
			ft_sb(head_b);
	}
}
