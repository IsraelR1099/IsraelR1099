/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_points.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 14:01:53 by irifarac          #+#    #+#             */
/*   Updated: 2022/05/03 13:53:46 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_fractal.h"
#include "mlx/mlx.h"

void	generateImage(points *values, window *init, char *str)
{
	if (ft_strcmp(str, "Mandelbrot") == 0)
		ft_Mandelbrot(values, init);
	else if (ft_strcmp(str, "Julia") == 0)
		ft_Julia(values, init);
}

void	ft_Mandelbrot(points *values, window *init)
{
	int	color;

	values->y = 3;
	while (values->y >= -3)
	{
		values->x = -4;
		while (values->x <= 4)
		{
			values->new_a = HEIGHT * (values->x + 4) / 8;
			values->new_b = WIDTH * (3 - (values->y))/ 6;
			values->iter = ft_iterationMandelbrot(values, values->x, values->y);
			if (values->iter == 0)
				my_mlx_pixel_put(init, values->new_a, values->new_b, 0x000000);
			else
			{
				color = color_value(values->iter, init);
				my_mlx_pixel_put(init, values->new_a, values->new_b, color);
			}
			values->x += 0.006;
		}
		values->y -= 0.008;
	}
	mlx_put_image_to_window(init->mlx, init->mlx_win, init->img, 0, 0);
}

void	ft_Julia(points *values, window *init)
{
	int	color;
	
	values->b_temp = 3;
	while (values->b_temp >= -3)
	{
		values->a_temp = -4;
		while (values->a_temp <= 4)
		{
			values->new_a = HEIGHT * (values->a_temp + 4) / 8;
			values->new_b = WIDTH * (3 - (values->b_temp)) / 6;
			values->iter = ft_iterationJulia(values, values->a_temp, values->b_temp);
			if (values->iter == 0)
				my_mlx_pixel_put(init, values->new_a, values->new_b, 0x000000);
			else
			{
				color = color_value(values->iter, init);
				my_mlx_pixel_put(init, values->new_a, values->new_b, color);
			}
			values->a_temp += 0.006;
		}
		values->b_temp -= 0.008;
	}
	mlx_put_image_to_window(init->mlx, init->mlx_win, init->img, 0, 0);
}
