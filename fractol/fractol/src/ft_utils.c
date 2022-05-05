/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 12:21:50 by irifarac          #+#    #+#             */
/*   Updated: 2022/05/05 12:17:21 by irifarac         ###   ########.fr       */
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

void	ft_show_options(void)
{
	printf("Utilizar los parametros siguientes:\n Mandelbrot.\n Julia.\n");
}

int	create_rgb(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

int	color_value(int iter, window *init)
{
	int	color;

	init->red = 0 + (iter * 15);
	init->green = 0 + (iter * 15);
	init->blue = 255;
	color = create_rgb(init->red, init->green, init->blue);
	return (color);
}

float	ft_atoi(char *str)
{
	float	number;
	int		position;
	int		sign;
	int		exponent;

	sign = 1;
	position = 0;
	number = 0;
	exponent = 0;
	if (str[position] == '-')
	{
		sign = -1;
		position++;
	}
	while (((str[position] >= 48) && (str[position] <= 57))
		|| str[position] == 46)
	{
		if (str[position] == 46)
		{
			position++;
			continue ;
		}
		number = (number * 10) + str[position] - 48;
		position++;
		exponent++;
	}
	number /= pow(10, exponent - 1);
	return (sign * number);
}
