/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:21:07 by irifarac          #+#    #+#             */
/*   Updated: 2021/12/15 14:23:09 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size);

int	main(void)
{
	int	array[4] = {10, 3, 11, -2};
	int	nbr;

	ft_sort_int_tab(array, 4);
	nbr = 0;
	while (nbr < 4)
	{
		printf("%d", array[nbr]);
		nbr++;
	}
	return (0);
}
