/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 12:21:50 by irifarac          #+#    #+#             */
/*   Updated: 2022/05/24 14:04:05 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_fractal.h"

int	ft_strcmp(char *str1, char *str2)
{
	size_t	i;

	if (!str1)
		return (1);
	i = 0;
	while (str1[i] != '\0' && str1[i] == str2[i])
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

int	create_rgb(int tr, int red, int green, int blue)
{
	return (tr << 24 | red << 16 | green << 8 | blue);
}

int	color_value(int iter, t_window *init, char *str)
{
	int		color;
	double	cnt_color;
	double	mgd;

	if (ft_strcmp(str, "Mandelbrot") == 0)
	{
		mgd = init->inf->x * init->inf->x + init->inf->y * init->inf->y;
		cnt_color = iter + 1 - ((log10(2) / sqrt(mgd)) / log10(2));
		init->red = (unsigned char)(sin(init->fr * cnt_color + init->sr) * 128 + 127);
		init->green = (unsigned char)(sin(init->fg * cnt_color + init->sg) * 128 + 127);
		init->blue = (unsigned char)(sin(init->fb * cnt_color + init->sb) * 128 + 127);
		init->tr = 0;
	}
	else if (ft_strcmp(str, "Julia") == 0)
	{
		mgd = init->inf->atmp * init->inf->atmp
			+ init->inf->btmp * init->inf->btmp;
		cnt_color = iter + 1 - ((log10(2) / sqrt(mgd)) / log10(2));
		init->red = (unsigned char)(sin(init->fr * cnt_color + init->sr) * 128 + 127);
		init->green = (unsigned char)(sin(init->fg * cnt_color + init->sg) * 128 + 127);
		init->blue = (unsigned char)(sin(init->fb * cnt_color + init->sb) * 128 + 127);
		init->tr = 0;
	}
	color = create_rgb(init->tr, init->red, init->green, init->blue);
	return (color);
}

float	ft_atoi(char *str, char c)
{
	float	number;
	int		i;
	int		sign;
	int		exponent;

	sign = 1;
	i = 0;
	number = 0;
	exponent = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (c == '-')
		sign = -1;
	while (((str[i] >= 48) && (str[i] <= 57)) || str[i] == 46)
	{
		if (str[i] == 46)
		{
			i++;
			continue ;
		}
		number = (number * 10) + str[i] - 48;
		i++;
		exponent++;
	}
	number /= pow(10, exponent - 1);
	return (sign * number);
}
