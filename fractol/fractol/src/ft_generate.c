/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_points.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 14:01:53 by irifarac          #+#    #+#             */
/*   Updated: 2022/04/30 13:33:41 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_fractal.h"
#include "mlx/mlx.h"

void	generateImage(points *values, window *init, char *str)
{
	if (ft_strcmp(str, "Mandelbrot") == 0)
		ft_Mandelbrot(values, init);
	else if (ft_strcmp(str, "Julia") == 0)
		ft_Julia(values, init, NULL);
}

void	ft_Mandelbrot(points *values, window *init)
{
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
			else if (values->iter > 20)
				my_mlx_pixel_put(init, values->new_a, values->new_b, 0x00ff00);
			else
				my_mlx_pixel_put(init, values->new_a, values->new_b, 0x0000ff);
			values->x += 0.006;
		}
		values->y -= 0.008;
	}
	mlx_put_image_to_window(init->mlx, init->mlx_win, init->img, 0, 0);
}

void	ft_Julia(points *values, window *init, char *str)
{
	(void)init;
	//values->x = ft_atoi(str);
	//values->y = ft_atoi(str);
	printf("%d %s", values->new_a, str);
}
