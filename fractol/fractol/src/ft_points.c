/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_points.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:21:07 by irifarac          #+#    #+#             */
/*   Updated: 2022/04/28 12:57:41 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "../include/lib_fractal.h"

void	generatePoints(points *values, window *init)
{
	values->x = 0;
	values->y = 0;
	values->iter = 0;
	values->a_temp = 0;
	values->b_temp = 0;
	while (values->y <= 2)
	{
		values->new_a = HEIGHT * (values->x + 4)/8;
		values->new_b = WIDTH * (3 - values->y)/6;
		//printf("new a y new b son %d, %d\n", values->new_a, values->new_b);
		while (values->iter <= 25)
		{
			values->a = ft_calcx(values->a_temp, values->b_temp, values->x);
			values->b = ft_calcy(values->a_temp, values->b_temp, values->y);
			//printf("a y b es %f, %f\n", values->a, values->b);
			values->a_temp = values->a;
			values->b_temp = values->b;
			values->iter++;
		}
		if (values->iter >= 5 && values->iter <= 7)
			my_mlx_pixel_put(init, values->new_a, values->new_b, 0x00FF00);
		else if (values->iter < 2)
			my_mlx_pixel_put(init, values->new_a, values->new_b, 0xFFFFFF);
		else
			my_mlx_pixel_put(init, values->new_a, values->new_b, 0x0000FF);
		if (values->x == 2 || values->i == 200)
		{
			printf("holaa final\n");
			values->y += 0.008;
			values->x = 0;
			values->i = 0;
		}
		values->x += 0.006;
		values->i++;
		values->iter = 0;
		values->a_temp = 0;
		values->b_temp = 0;
	}
	mlx_put_image_to_window(init->mlx, init->mlx_win, init->img, 0, 0);
}
