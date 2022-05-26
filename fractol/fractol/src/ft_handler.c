/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 10:52:12 by irifarac          #+#    #+#             */
/*   Updated: 2022/05/26 14:05:22 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_fractal.h"
#include "../mlx/mlx.h"

void	reset_variables(t_window *init)
{
		init->z_x = 1;
		init->z_y = 1;
		init->trl_x = 0;
		init->trl_y = 0;
		init->fr = 0.5;
		init->fg = 0.4;
		init->fb = 0.25;
		init->sr = 8;
		init->sg = 4;
		init->sb = 1;
		init->max_iter = 50;
}

void	change_values(t_window *init)
{
		init->fr = 0.08;
		init->fg = 0.25;
		init->fb = 0.9;
		init->sr += 2;
		init->sg += 2;
		init->sb += 1;
}

int	key_event(int button, t_window *init)
{
	printf("button es %d\n", button);
	if (button == 53)
		destroy_window(init);
	else if (button == 126)
		init->trl_y += 10;
	else if (button == 125)
		init->trl_y -= 10;
	else if (button == 124)
		init->trl_x -= 10;
	else if (button == 123)
		init->trl_x += 10;
	else if (button == 69)
		init->max_iter += 10;
	else if (button == 78)
		init->max_iter -= 10;
	else if (button == 15)
		reset_variables(init);
	else if (button == 8)
		change_values(init);
	printf("trl_x es %d\n", init->trl_x);
	generate_image(init, init->inf->fract_type);
	return (1);
}

int	ft_mouse_event(int button, int x, int y, t_window *init)
{
	printf("button es %d, x es %d, y es %d\n", button, x, y);
	if (button == 5)
	{
		init->trl_x += (int)((x - 640) * init->z_x);
		init->trl_y += (int)((y - 360) * init->z_y);
		printf("trl x es %d\n", init->trl_x);
		if (init->z_x >= 0.0005 && init->z_y >= 0.0005)
		{
			printf("entro en if zoom x %f y zoom y %f\n", init->z_x, init->z_y);
			ft_zoom_plus(init);
			generate_image(init, init->inf->fract_type);
		}
	}
	else if (button == 4)
	{
		printf("zoom x %f zoom y %f\n", init->z_x, init->z_y);
		ft_zoom_less(x, y, init);
		generate_image(init, init->inf->fract_type);
	}
	return (1);
}

int	destroy_window(t_window *init)
{
	mlx_destroy_window(init->mlx, init->mlx_win);
	exit(0);
	return (1);
}
