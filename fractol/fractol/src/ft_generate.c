/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_points.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 14:01:53 by irifarac          #+#    #+#             */
/*   Updated: 2022/05/25 12:01:50 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_fractal.h"
#include "../mlx/mlx.h"

void	generate_image(t_window *init, char *str)
{
	if (ft_strcmp(str, "Mandelbrot") == 0)
		ft_mandelbrot(init);
	else if (ft_strcmp(str, "Julia") == 0)
		ft_julia(init);
}

void	ft_mandelbrot(t_window *init)
{
	int	color;

	init->inf->nwb = 0;
	while (init->inf->nwb < WIDTH)
	{
		init->inf->nwa = 0;
		while (init->inf->nwa < HEIGHT)
		{
			init->inf->x = ((((8 * init->z_x) * ((float)init->inf->nwa))
						+ init->trl_x) / HEIGHT) - (4 * init->z_x);
			init->inf->y = (3 * init->z_y) - ((((6 * init->z_y)
							* (float)init->inf->nwb) + init->trl_y) / WIDTH);
			init->inf->iter = ft_iter_mandel(init, init->inf->x, init->inf->y);
			if (init->inf->iter == 0)
				my_mlx_pxput(init, init->inf->nwa, init->inf->nwb, 0x00);
			else
			{
				color = color_value(init->inf->iter, init, "Mandelbrot");
				my_mlx_pxput(init, init->inf->nwa, init->inf->nwb, color);
			}
			init->inf->nwa += 1;
		}
		init->inf->nwb += 1;
	}
	mlx_put_image_to_window(init->mlx, init->mlx_win, init->img, 0, 0);
}

void	ft_julia(t_window *init)
{
	int	color;

	init->inf->nwb = 0;
	while (init->inf->nwb < WIDTH)
	{
		init->inf->nwa = 0;
		while (init->inf->nwa < HEIGHT)
		{
			init->inf->atmp = ((((8 * init->z_x) * ((float)init->inf->nwa))
						+ init->trl_x) / HEIGHT) - (4 * init->z_x);
			init->inf->btmp = (3 * init->z_y) - ((((6 * init->z_y)
							* (float)init->inf->nwb) + init->trl_y) / WIDTH);
			init->inf->iter = ft_ijulia(init, init->inf->atmp, init->inf->btmp);
			if (init->inf->iter == 0)
				my_mlx_pxput(init, init->inf->nwa, init->inf->nwb, 0x00);
			else
			{
				color = color_value(init->inf->iter, init, "Julia");
				my_mlx_pxput(init, init->inf->nwa, init->inf->nwb, color);
			}
			init->inf->nwa += 1;
		}
		init->inf->nwb += 1;
	}
	mlx_put_image_to_window(init->mlx, init->mlx_win, init->img, 0, 0);
}
