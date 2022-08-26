/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 12:40:21 by irifarac          #+#    #+#             */
/*   Updated: 2022/08/26 11:39:04 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "../include/lib_push_swap.h"

static void	ft_start(t_nbr *head, int counter)
{
	ft_sort_lst(&head, counter);
	ft_deallocation(&head);
}

int	main(int counter, char **str)
{
	t_nbr	*head;
	t_nbr	*tmp;
	int		index;
	int		i;

	if (counter >= 2)
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
			ft_start(head, counter);
		}
	}
	return (0);
}
