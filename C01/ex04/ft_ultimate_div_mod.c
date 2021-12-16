/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 13:40:04 by irifarac          #+#    #+#             */
/*   Updated: 2021/12/13 14:39:04 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	divide;
	int	mod;

	divide = *a / *b;
	*a = divide;
	mod = *a % *b;
	*b = mod;
	printf("%d,%d\n", (*a),  (*b));
}
