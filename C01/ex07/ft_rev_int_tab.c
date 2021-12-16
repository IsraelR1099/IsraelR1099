/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:37:08 by irifarac          #+#    #+#             */
/*   Updated: 2021/12/15 13:19:22 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	a;
	int	b;
	int	result;

	a = 0;
	b = size -1;
	while (a < (size / 2))
	{
		result = tab[a];
		tab[a] = tab [b];
		tab[b] = result;
		a++;
		b--;
	}
}
