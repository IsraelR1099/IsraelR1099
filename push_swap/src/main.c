/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:12:24 by irifarac          #+#    #+#             */
/*   Updated: 2022/06/06 14:03:43 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "../include/lib_push_swap.h"

int	main(int counter, char **str)
{
	t_nbr	*head;
	t_nbr	*tmp;
	int		index;

	if (counter > 2)
	{
		if (ft_checker(str, counter))
		{
			lst = (t_nbr *)malloc(sizeof(t_nbr));
			if (!lst)
				return (0);
			printf("data fuera es %d\n", lst->data);
			ft_createlist(head, (counter - 1));
			index = 1;
			head->index = 0;
			while (*(str + index) && !(index == counter))
			{
				ft_values(lst, 
				index++;
				lst->index++;
			}
		}
	}
	return (0);
}
