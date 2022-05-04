/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_points.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 14:01:53 by irifarac          #+#    #+#             */
/*   Updated: 2022/05/04 13:55:40 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_fractal.h"
#include "mlx/mlx.h"

void	generateImage(window *init, char *str)
{
	if (ft_strcmp(str, "Mandelbrot") == 0)
		ft_Mandelbrot(init);
	else if (ft_strcmp(str, "Julia") == 0)
		ft_Julia(init);
}

void	ft_Mandelbrot(window *init)
{
	int	color;

	init->values->y = 3;
	while (init->values->y >= -3)
	{
		init->values->x = -4;
		while (init->values->x <= 4)
		{
//			values->new_a = (HEIGHT * ((values->x * init->zoom) + 4) / 8);
//			values->new_b = (WIDTH * (3 - (values->y * init->zoom))/ 6);
			init->values->new_a = ((4 * HEIGHT / 8) + init->trl) + ((init->values->x * HEIGHT / 8)); 
//			values->new_a = 640 + (values->x * HEIGHT / 8);
			init->values->new_b = ((3 * WIDTH / 6)) - (init->values->y * WIDTH / 6);
			if (init->values->new_a == 1280)
				break;
			//printf("new a es %d\n", values->new_a);
			init->values->iter = ft_iterationMandelbrot(init, init->values->x, init->values->y);
			if (init->values->iter == 0)
				my_mlx_pixel_put(init, init->values->new_a, init->values->new_b, 0x000000);
			else
			{
				color = color_value(init->values->iter, init);
				my_mlx_pixel_put(init, init->values->new_a, init->values->new_b, color);
			}
			init->values->x += 0.006;
		}
		init->values->y -= 0.008;
	}
	mlx_put_image_to_window(init->mlx, init->mlx_win, init->img, 0, 0);
}

void	ft_Julia(window *init)
{
	int	color;

	init->values->b_temp = 3;
	while (init->values->b_temp >= -3)
	{
		init->values->a_temp = -4;
		while (init->values->a_temp <= 4)
		{
			//init->values->new_a = HEIGHT * (init->values->a_temp + 4) / 8;
			//init->values->new_b = WIDTH * (3 - (init->values->b_temp)) / 6;
			init->values->new_a = ((4 * HEIGHT / 8) + init->trl) + ((init->values->a_temp * HEIGHT / 8)); 
//			values->new_a = 640 + (values->x * HEIGHT / 8);
			init->values->new_b = ((3 * WIDTH / 6)) - (init->values->b_temp * WIDTH / 6);
			init->values->iter = ft_iterationJulia(init, init->values->a_temp, init->values->b_temp);
			if (init->values->iter == 0)
				my_mlx_pixel_put(init, init->values->new_a, init->values->new_b, 0x000000);
			else
			{
				color = color_value(init->values->iter, init);
				my_mlx_pixel_put(init, init->values->new_a, init->values->new_b, color);
			}
			init->values->a_temp += 0.006;
		}
		init->values->b_temp -= 0.008;
	}
	mlx_put_image_to_window(init->mlx, init->mlx_win, init->img, 0, 0);
}
