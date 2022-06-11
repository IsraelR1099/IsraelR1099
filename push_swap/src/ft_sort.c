/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:56:43 by irifarac          #+#    #+#             */
/*   Updated: 2022/06/11 13:02:53 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_push_swap.h"

void	ft_sort_lst(t_nbr *head, int counter)
{
	t_nbr	*head_b;
	/*if (ft_check_sort(head, counter))
	{
		free(head);
		return ;
	}*/
	if ((counter - 1) <= 3)
		ft_sort_3(head);
	else if ((counter - 1) == 4)
	{
		head_b = create_list(0);
		ft_sort_4(head, head_b);
	/*else if (counter > 10 && counter <= 100)
		ft_merge(head);
	else if (counter > 100)
		ft_merge(head);*/
}
