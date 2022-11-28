/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:58:45 by irifarac          #+#    #+#             */
/*   Updated: 2022/11/28 13:52:08 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

static int	ft_isdigit(int c)
{
	if ((c >= 48) && (c <= 57))
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
		printf("str es %c, i es %d, j %d\n", *(*(str + i) + j), i, j);
		if (!ft_isdigit(*(*(str + i) + j)))
			return (ft_message("Wrong argument\n", 0));
		j++;
		if (!*(*(str + i) + j) && i <= (counter - 1))
		{
			i++;
			j = 0;
		}
	}
	return (1);
}
