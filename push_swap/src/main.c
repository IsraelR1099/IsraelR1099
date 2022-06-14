/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:12:24 by irifarac          #+#    #+#             */
/*   Updated: 2022/06/14 14:06:11 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "../include/lib_push_swap.h"

int	main(int counter, char **str)
{
	t_nbr	*head;
	t_nbr	*tmp;
	int		index;
	int		i;

	if (counter > 2)
	{
		if (ft_checker(str, counter))
		{
			head = ft_createlist((counter - 1));
			index = 1;
			tmp = head;
			i = 0;
			while (!(index == counter) && head != NULL)
			{
				tmp->data = ft_atoi(*(str + index));
				tmp->index = i;
				tmp = tmp->next;
				index++;
				i++;
			}
			ft_sort_lst(&head, counter);
			ft_deallocation(&head);
		}
	}
	return (0);
}
