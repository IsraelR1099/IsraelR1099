/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 11:59:57 by irifarac          #+#    #+#             */
/*   Updated: 2021/12/12 14:15:26 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	int	divide;
	int	modulo;

	divide = a / b;
	*div = divide;
	modulo = a % b;
	*mod = modulo;
	printf("%d,%d\n", (*div), (*mod));
}
