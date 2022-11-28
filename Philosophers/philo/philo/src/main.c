/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 09:31:55 by irifarac          #+#    #+#             */
/*   Updated: 2022/11/28 13:52:11 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

int	main(int counter, char **str)
{
	if (counter == 5 || counter == 6)
	{
		if (ft_control(str, counter))
		{
			printf("no error\n");
		}
	}
	else
		ft_message("Wrong number of arguments\n", 0);
	return (0);
}
