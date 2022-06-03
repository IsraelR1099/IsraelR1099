/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:12:24 by irifarac          #+#    #+#             */
/*   Updated: 2022/06/03 14:04:58 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../Libft/libft.h"
#include "../include/lib_push_swap.h"

int	main(int counter, char **str)
{
	t_nbr	*lst;
	int		index;

	if (counter > 2)
	{
		if (ft_checker(str, counter))
		{
			lst = (t_nbr *)malloc(sizeof(t_nbr));
			if (!lst)
				return (0);
			index = 1;
			while (*(str + index) && !(index == counter))
			{
				lst->data = ft_atoi(&*(*(str + index) + 0));
				index++;
			}
		}
	}
	return (0);
}	
