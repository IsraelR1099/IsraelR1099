/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:06:35 by irifarac          #+#    #+#             */
/*   Updated: 2022/04/28 12:49:59 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../include/lib_fractal.h"

void	my_mlx_pixel_put(window *init, int x, int y, int color)
{
	char	*dst;

	dst = init->addr + (y * init->line_length + x * (init->bpp / 8));
	*(unsigned int *)dst = color;
}

int	main(void)
{
	window	*init;
	points	*values;
	
	init = (window *)malloc(sizeof(window));
	values = (points *)malloc(sizeof(points));
	if (!init || !values)
		return (0);
	init->mlx = mlx_init();
	init->mlx_win = mlx_new_window(init->mlx, HEIGHT, WIDTH, "Fractol");
	init->img = mlx_new_image(init->mlx, HEIGHT, WIDTH);
	init->addr = mlx_get_data_addr(init->img, &init->bpp, &init->line_length, &init->endian);
	generatePoints(values, init);
//	my_mlx_pixel_put(init, values->new_a, values->new_b, 0x00FF00);
//	mlx_put_image_to_window(init->mlx, init->mlx_win, init->img, 0, 0);
	mlx_key_hook(init->mlx_win, key_event, init);
	mlx_loop(init->mlx);
	free(init);
	return (0);
}
