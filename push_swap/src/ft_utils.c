/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:20:20 by irifarac          #+#    #+#             */
/*   Updated: 2022/06/17 11:18:55 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_push_swap.h"

t_nbr	*ft_createlist(int nbr_nodes)
{
	t_nbr	*new_node;
	t_nbr	*tmp;
	t_nbr	*lst;
	int		i;

	lst = (t_nbr *)malloc(sizeof(t_nbr));
	if (!lst)
		return (NULL);
	i = 2;
	tmp = lst;
	lst->data = 0;
	lst->next = NULL;
	while (i <= nbr_nodes)
	{
		new_node = (t_nbr *)malloc(sizeof(t_nbr));
		if (!new_node)
			return (NULL);
		new_node->data = 0;
		new_node->next = NULL;
		tmp->next = new_node;
		tmp = tmp->next;
		i++;
	}
	return (lst);
}

void	ft_write(int max, int min)
{
	if (max == 1 && min == 2)
		write(1, "rra\n", 4);
	else if (max == 1 && min == 0)
	{
		write(1, "rra\n", 4);
		write(1, "sa\n", 3);
	}
	else if (min == 1 && max == 2)
		write(1, "sa\n", 3);
	else if (max == 0 && min == 2)
	{
		write(1, "sa\n", 3);
		write(1, "rra\n", 4);
	}
	else if (max == 0 && min == 1)
		write(1, "ra\n", 3);
}
void	ft_deallocation(t_nbr **head)
{
	t_nbr	*tmp;

	while (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
	*head = NULL;
}

int	ft_size(t_nbr *head)
{
	int		len;
	t_nbr	*tmp;

	len = 0;
	tmp = head;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}
