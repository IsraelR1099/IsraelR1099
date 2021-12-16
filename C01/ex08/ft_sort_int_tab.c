/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:28:35 by irifarac          #+#    #+#             */
/*   Updated: 2021/12/15 14:23:12 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	a;
	int	b;
	int	temp;

	a = size - 1;
	while (a > 0)
	{
		b = 0;
		while (b < a)
		{
			if (tab[b] > tab[b +1])
			{
				temp = tab[b];
				tab[b] = tab[b + 1];
				tab[b +1] = temp;
			}
			b++;
		}
		a--;
	}
}
