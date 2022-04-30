/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 12:21:50 by irifarac          #+#    #+#             */
/*   Updated: 2022/04/30 12:38:08 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_fractal.h"
#include "mlx/mlx.h"

int	ft_strcmp(char *str1, char *str2)
{
	size_t	position;

	position = 0;
	while (str1[position] != '\0' && str1[position] == str2[position])
		position++;
	return ((unsigned char)str1[position] - (unsigned char)str2[position]);
}

void	ft_showOptions(void)
{
	printf("Utilizar los parametros siguientes:\n Mandelbrot.\n Julia.\n");
}
