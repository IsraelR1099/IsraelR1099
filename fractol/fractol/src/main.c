/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:06:35 by irifarac          #+#    #+#             */
/*   Updated: 2022/05/26 14:05:17 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../include/lib_fractal.h"

int	main(int counter, char **str)
{
	t_window	*init;

	init = (t_window *)malloc(sizeof(t_window));
	init->inf = (t_points *)malloc(sizeof(t_points));
	if (!init || !init->inf)
	{
		ft_free(init);
		return (0);
	}
	if ((counter > 1 && counter < 6) && (counter != 3 && counter != 4))
	{
		init_variables(init, &*(*(str + 1) + 0));
		if (counter == 2)
			generate_image(init, &*(*(str + 1) + 0));
		else if (counter == 5)
		{
			init->inf->x_julia = ft_atoi(str[2], '+');
			init->inf->y_julia = ft_atoi(str[4], *str[3]);
			generate_image(init, &*(*(str + 1) + 0));
		}
		all_hook(init);
		ft_free(init);
	}
	ft_show_options();
	return (0);
}

int	init_variables(t_window *init, char *str)
{
	checker(str);
	init->mlx = mlx_init();
	init->mlx_win = mlx_new_window(init->mlx, HEIGHT, WIDTH, "Fractol");
	init->img = mlx_new_image(init->mlx, HEIGHT, WIDTH);
	init->addr = mlx_get_data_addr(init->img, &init->b, &init->ll, &init->end);
	init->inf->fract_type = str;
	init->inf->x_julia = -0.51;
	init->inf->y_julia = -0.601;
	init->z_x = 1;
	init->z_y = 1;
	init->trl_x = 0;
	init->trl_y = 0;
	init->max_iter = 50;
	init->red = 0;
	init->green = 0;
	init->blue = 255;
	init->fr = 0.50;
	init->fg = 0.40;
	init->fb = 0.25;
	init->sr = 8;
	init->sg = 4;
	init->sb = 1;
	return (1);
}

void	all_hook(t_window *init)
{
	mlx_key_hook(init->mlx_win, key_event, init);
	mlx_hook(init->mlx_win, 4, 1L << 4, ft_mouse_event, init);
	mlx_hook(init->mlx_win, 5, 1L << 3, ft_mouse_event, init);
	mlx_hook(init->mlx_win, 17, 0, destroy_window, init);
	mlx_loop(init->mlx);
	mlx_do_key_autorepeatoff(init);
}

void	ft_free(t_window *init)
{
	free(init->inf);
	free(init);
}

void	my_mlx_pxput(t_window *init, int x, int y, int color)
{
	char	*dst;

	dst = init->addr + (y * init->ll + x * (init->b / 8));
	*(unsigned int *)dst = color;
}
