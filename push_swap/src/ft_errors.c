/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:26:30 by irifarac          #+#    #+#             */
/*   Updated: 2022/06/02 14:02:54 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_push_swap.h"

int	ft_checker(char **str, int counter)
{
	int	position;
	int	index;

	position = 0;
	index = 1;
	while (*(*(str + index) + position))
	{
		if (ft_not_nbr(*(*(str + index) + position)))
		{
			write(1, "Error\n", 6);
			return (0);
		}
	   position++;
	   if (!(*(*(str + index) + position)))
	   {
		   index++;
		   position = 0;
		   if (index == counter)
			   break;
	   }
	}	   
	return (1);
}

int	ft_not_nbr(char c)
{
	if ((c >= 48) && (c <= 57))
		return (0);
	return (1);
}
