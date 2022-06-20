/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:12:24 by irifarac          #+#    #+#             */
/*   Updated: 2022/06/20 10:35:09 by irifarac         ###   ########.fr       */
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
			//ft_deallocation(&head);
		}
	}
	if (counter > 2)
	{
		if (ft_check_sort(&head, counter))
			printf("\033[0;32mOK\n\033[0m");
		else
			printf("\033[0;31mKO\n\033[0m");
	}
	return (0);
}
