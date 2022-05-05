/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:06:35 by irifarac          #+#    #+#             */
/*   Updated: 2022/05/05 14:00:11 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../include/lib_fractal.h"

int	main(int counter, char **str)
{
	window	*init;

	init = (window *)malloc(sizeof(window));
	init->values = (points *)malloc(sizeof(points));
	if (!init || !init->values)
		return (0);
	if (counter > 1)	
	{
		init_variables(init, &*(*(str + 1) + 0));
		if (counter == 2)
			generateImage(init, &*(*(str + 1) + 0));
		else if (counter == 5)
		{
			init->values->x_julia = ft_atoi(str[2]);
			init->values->y_julia = ft_atoi(str[4]);
			printf("x es %f\n y es %f\n", init->values->x_julia, init->values->y_julia);
			generateImage(init, &*(*(str + 1) + 0));
		}
		mlx_key_hook(init->mlx_win, key_event, init);
		mlx_hook(init->mlx_win, 4, 1L << 4, ft_mouse_event, init);
		mlx_hook(init->mlx_win, 5, 1L << 3, ft_mouse_event, init);
		mlx_loop(init->mlx);
		free(init->values);
		free(init);
	}
	ft_show_options();
	return (0);
}

int	init_variables(window *init, char *str)
{
	init->mlx = mlx_init();
	init->mlx_win = mlx_new_window(init->mlx, HEIGHT, WIDTH, "Fractol");
	init->img = mlx_new_image(init->mlx, HEIGHT, WIDTH);
	init->addr = mlx_get_data_addr(init->img, &init->bpp, &init->line_length, &init->endian);
	init->values->fract_type = str;
	init->values->x_julia = -0.51;
	init->values->y_julia = -0.601;
	init->zoom_x = 1;
	init->zoom_y = 1;
	init->trl = 0;
	init->max_iter = 50;
	return (1);
}

void	my_mlx_pixel_put(window *init, int x, int y, int color)
{
	char	*dst;

	dst = init->addr + (y * init->line_length + x * (init->bpp / 8));
	*(unsigned int *)dst = color;
}
