/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:12:24 by irifarac          #+#    #+#             */
/*   Updated: 2022/05/27 14:09:35 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../Libft/libft.h"

int	main(int counter, char **str)
{
	int	nbr;

	if (counter > 2)
	{
		nbr = ft_atoi(str[1]);
		printf("counter es %d y nbr %d\n", counter, nbr);
	}
	return (0);
}	
