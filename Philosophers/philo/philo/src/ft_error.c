/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:58:45 by irifarac          #+#    #+#             */
/*   Updated: 2022/11/30 13:30:58 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	ft_isvalid(int c)
{
	if ((c >= 48) && (c <= 57))
		return (1);
	else if (c == '+')
		return (1);
	return (0);
}

int	ft_control(char **str, int counter)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i <= (counter - 1))
	{
		if (!ft_isvalid(*(*(str + i) + j)))
			return (ft_message("Wrong argument\n", 0, NULL));
		j++;
		if (!*(*(str + i) + j) && i <= (counter - 1))
		{
			i++;
			j = 0;
		}
	}
	return (1);
}
