/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:20:20 by irifarac          #+#    #+#             */
/*   Updated: 2022/06/08 12:06:18 by irifarac         ###   ########.fr       */
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
