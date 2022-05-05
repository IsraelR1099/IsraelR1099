/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_points.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 14:01:53 by irifarac          #+#    #+#             */
/*   Updated: 2022/05/05 14:00:08 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_fractal.h"
#include "mlx/mlx.h"

void	generateImage(window *init, char *str)
{
	printf("holaaa\n");
	if (ft_strcmp(str, "Mandelbrot") == 0)
		ft_Mandelbrot(init);
	else if (ft_strcmp(str, "Julia") == 0)
		ft_Julia(init);
}

void	ft_Mandelbrot(window *init)
{
	int	color;

	init->values->y = 3;
	printf("hola\n");
	while (init->values->y >= -3)
	{
		init->values->x = -4;
		while (init->values->x <= 4)
		{
			init->values->new_a = ((4 * HEIGHT / 8) + init->trl) + ((init->zoom_x * init->values->x * HEIGHT / 8)); 
			init->values->new_b = ((3 * WIDTH / 6)) - (init->zoom_y * init->values->y * WIDTH / 6);
			//printf("new a es %d y new b es %d\n", init->values->new_a, init->values->new_b);
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
			init->values->new_a = ((4 * HEIGHT / 8) + init->trl) + ((init->values->a_temp * HEIGHT / 8)); 
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
