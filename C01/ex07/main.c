/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:26:13 by irifarac          #+#    #+#             */
/*   Updated: 2021/12/15 13:19:25 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size);

int	main(void)
{
	int	array[4] = {2, 3, 6, 0};
	int	nbr;

	ft_rev_int_tab(array, 4);
	nbr = 0;
	while (nbr < 4)
	{
		printf("%d", array[nbr]);
		nbr++;
	}
	return (0);
}
