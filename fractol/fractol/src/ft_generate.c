/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_points.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 14:01:53 by irifarac          #+#    #+#             */
/*   Updated: 2022/05/23 14:15:15 by irifarac         ###   ########.fr       */
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

	init->inf->new_b = 0;
	while (init->inf->new_b < WIDTH)
	{
		init->inf->new_a = 0;
		while (init->inf->new_a < HEIGHT)
		{
			init->inf->x = ((((2 * 4 * init->zoom_x) * ((float)init->inf->new_a)) + init->trl_x) / HEIGHT) - (4 * init->zoom_x);
			init->inf->y = (3 * init->zoom_y) - ((((2 * 3 * init->zoom_y) * (float)init->inf->new_b) + init->trl_y) / WIDTH);
			init->inf->iter = ft_iter_mandel(init, init->inf->x, init->inf->y);
			if (init->inf->iter == 0)
				my_mlx_pxput(init, init->inf->new_a, init->inf->new_b, 0x00);
			else
			{
				color = color_value(init->inf->iter, init, "Mandelbrot");
				my_mlx_pxput(init, init->inf->new_a, init->inf->new_b, color);
			}
			init->inf->new_a += 1;
		}
		init->inf->new_b += 1;
	}
	mlx_put_image_to_window(init->mlx, init->mlx_win, init->img, 0, 0);
}

void	ft_julia(window *init)
{
	int	color;

	init->inf->new_b = 0;
	while (init->inf->new_b < WIDTH)
	{
		init->inf->new_a = 0;
		while (init->inf->new_a < HEIGHT)
		{
			init->inf->a_temp = ((((2 * 4 * init->zoom_x) * ((float)init->inf->new_a)) + init->trl_x) / HEIGHT) - (4 * init->zoom_x);
			init->inf->b_temp = (3 * init->zoom_y) - ((((2 * 3 * init->zoom_y) * (float)init->inf->new_b) + init->trl_y) / WIDTH);
			init->inf->iter = ft_iter_julia(init, init->inf->a_temp, init->inf->b_temp);
			if (init->inf->iter == 0)
				my_mlx_pxput(init, init->inf->new_a, init->inf->new_b, 0x00);
			else
			{
				color = color_value(init->inf->iter, init, "Julia");
				my_mlx_pxput(init, init->inf->new_a, init->inf->new_b, color);
			}
			init->inf->new_a += 1;
		}
		init->inf->new_b += 1;
	}
	mlx_put_image_to_window(init->mlx, init->mlx_win, init->img, 0, 0);
}
