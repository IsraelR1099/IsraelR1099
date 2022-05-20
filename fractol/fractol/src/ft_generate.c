/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_points.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 14:01:53 by irifarac          #+#    #+#             */
/*   Updated: 2022/05/20 13:56:10 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_fractal.h"
#include "mlx/mlx.h"

void	generate_image(window *init, char *str)
{
	if (ft_strcmp(str, "Mandelbrot") == 0)
		ft_mandelbrot(init);
	else if (ft_strcmp(str, "Julia") == 0)
		ft_julia(init);
	else if (ft_strcmp(str, "--help") == 0)
		ft_show_options("--help");
}

void	ft_mandelbrot(window *init)
{
	int	color;

	init->values->new_b = 0;
	while (init->values->new_b < WIDTH)
	{
		init->values->new_a = 0;
		while (init->values->new_a < HEIGHT)
		{
			init->values->x = ((((2 * 4 * init->zoom_x) * ((float)init->values->new_a)) + init->trl_x) / HEIGHT) - (4 * init->zoom_x);
			init->values->y = (3 * init->zoom_y) - ((((2 * 3 * init->zoom_y) * (float)init->values->new_b) + init->trl_y) / WIDTH);
			init->values->iter = ft_iteration_mandelbrot(init, init->values->x, init->values->y);
			if (init->values->iter == 0)
			{
				my_mlx_pixel_put(init, init->values->new_a, init->values->new_b, 0x000000);
			}
			else
			{
				color = color_value(init->values->iter, init);
				my_mlx_pixel_put(init, init->values->new_a, init->values->new_b, color);
			}
			init->values->new_a += 1;
		}
		init->values->new_b += 1;
	}
	mlx_put_image_to_window(init->mlx, init->mlx_win, init->img, 0, 0);
}

void	ft_julia(window *init)
{
	int	color;

	init->values->new_b = 0;
	while (init->values->new_b < WIDTH)
	{
		init->values->new_a = 0;
		while (init->values->new_a < HEIGHT)
		{
			init->values->a_temp = ((((2 * 4 * init->zoom_x) * ((float)init->values->new_a)) + init->trl_x) / HEIGHT) - (4 * init->zoom_x);
			init->values->b_temp = (3 * init->zoom_y) - (((2 * 3 * init->zoom_y) * (float)init->values->new_b) / WIDTH);
			init->values->iter = ft_iteration_julia(init, init->values->a_temp, init->values->b_temp);
			if (init->values->iter == 0)
			{
				my_mlx_pixel_put(init, init->values->new_a, init->values->new_b, 0x000000);
			}
			else
			{
				color = color_value(init->values->iter, init);
				my_mlx_pixel_put(init, init->values->new_a, init->values->new_b, color);
			}
			init->values->new_a += 1;
		}
		init->values->new_b += 1;
	}
	mlx_put_image_to_window(init->mlx, init->mlx_win, init->img, 0, 0);
}
