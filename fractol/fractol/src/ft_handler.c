/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 10:52:12 by irifarac          #+#    #+#             */
/*   Updated: 2022/05/24 14:02:09 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_fractal.h"
#include "mlx/mlx.h"

int	key_event(int button, t_window *init)
{
	printf("button es %d\n", button);
	if (button == 53)
		destroy_window(init);
	//Mover arriba 
	else if (button == 126)
		init->trl_y += (20 * init->z_y);
	//Mover abajo
	else if (button == 125)
		init->trl_y -= (20 * init->z_y);
	//Mover hacia la izquierda
	else if (button == 124)
		init->trl_x -= (20 * init->z_x);
	//Mover hacia la derecha
	else if (button == 123)
		init->trl_x += (20 * init->z_x);
	//Aumentar iteraciones +
	else if (button == 69)
		init->max_iter += 10;
	//Disminuir iteraciones -
	else if (button == 78)
		init->max_iter -= 10;
	//Restablecer valores r
	else if (button == 15)
	{
		init->z_x = 1;
		init->z_y = 1;
		init->trl_x = 0;
		init->trl_y = 0;
		init->fr = 0.5;
		init->fg = 0.4;
		init->fb = 0.25;
		init->max_iter = 50;
	}
	//Cambiar colores c
	else if (button == 8)
	{
		init->fr = 0.08;
		init->fg = 0.9;
		init->fb = 0.4;
	}
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
			if (init->z_x <= 0.02 && init->z_y <= 0.02)
			{
				printf("entro en if zoom x %f y zoom y %f\n", init->z_x, init->z_y);
				init->z_x -= 0.0005;
				init->z_y -= 0.0005;
				printf("entro en if zoom x %f y zoom y %f\n", init->z_x, init->z_y);
				generate_image(init, init->inf->fract_type);
			}
			else
			{
				init->z_x -= 0.02;
				init->z_y -= 0.02;
				printf("zoom x %f y zoom y %f\n", init->z_x, init->z_y);
				generate_image(init, init->inf->fract_type);
			}
		}
	}
	else if (button == 4)
	{
		printf("zoom x %f zoom y %f\n", init->z_x, init->z_y);
		if (init->z_x == 0.014 && init->z_y == 0.012)
		{
			init->trl_x -= x - 640;
			init->trl_y -= y - 360;
			init->z_x += 0.006;
			init->z_y += 0.008;
		}
		else
		{
			init->z_x += 0.02;
			init->z_y += 0.02;
		}
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
