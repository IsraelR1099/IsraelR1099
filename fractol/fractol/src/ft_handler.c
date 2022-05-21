/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 10:52:12 by irifarac          #+#    #+#             */
/*   Updated: 2022/05/21 12:55:44 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_fractal.h"
#include "mlx/mlx.h"

int	key_event(int button, window *init)
{
	printf("button es %d\n", button);
	if (button == 53)
		destroy_window(init);
	//Mover arriba 
	else if (button == 126)
		init->trl_y += 20;
	//Mover abajo
	else if (button == 125)
		init->trl_y -= 20;
	//Mover hacia la izquierda
	else if (button == 124)
		init->trl_x -= 20;
	//Mover hacia la derecha
	else if (button == 123)
		init->trl_x += 20;
	//Aumentar iteraciones +
	else if (button == 69)
		init->max_iter += 10;
	//Disminuir iteraciones -
	else if (button == 78)
		init->max_iter -= 10;
	//Restablecer valores r
	else if (button == 15)
	{
		init->zoom_x = 1;
		init->zoom_y = 1;
		init->trl_x = 0;
		init->trl_y = 0;
	}
	//Cambiar colores c
	else if (button == 8)
	{
		init->tr = 0;
		init->red = 255;
		init->green = 0;
		init->blue = 0;
	}
	printf("trl_x es %d\n", init->trl_x);
	generate_image(init, init->values->fract_type);
	return (1);
}

int	ft_mouse_event(int button, int x, int y, window *init)
{
	printf("button es %d, x es %d, y es %d\n", button, x, y);

	if (button == 5)
	{
		init->trl_x += (int)(x - 640);
		init->trl_y += (int)(y - 360);
	//	init->trl_x += pixel_to_point_x(init, x);		
		printf("trl es %d\n", init->trl_x);
		if (init->zoom_x > 0 && init->zoom_y > 0)
		{
			if (init->zoom_x <= 0.02 && init->zoom_y <= 0.02)
			{
				printf("entro en if zoom x %f y zoom y %f\n", init->zoom_x, init->zoom_y);
				init->zoom_x -= 0.0005;
				init->zoom_y -= 0.0005;
				printf("entro en if zoom x %f y zoom y %f\n", init->zoom_x, init->zoom_y);
				generate_image(init, init->values->fract_type);
			}
			else 
			{
				init->zoom_x -= 0.02;
				init->zoom_y -= 0.02;
				printf("zoom x %f y zoom y %f\n", init->zoom_x, init->zoom_y);
				generate_image(init, init->values->fract_type);
			}
		}
	}
	else if (button == 4)
	{
		printf("zoom x %f zoom y %f\n", init->zoom_x, init->zoom_y);
		if (init->zoom_x == 0.014 && init->zoom_y == 0.012)
		{
			init->trl_x -= x - 640;
			init->trl_y -= y - 360;
			init->zoom_x += 0.006;
			init->zoom_y += 0.008;
		}
		else
		{
			init->zoom_x += 0.02;
			init->zoom_y += 0.02;
		}
		generate_image(init, init->values->fract_type);
	}
	return (1);
}

int	destroy_window(window *init)
{
		mlx_destroy_window(init->mlx, init->mlx_win);
		exit(1);
		return (1);
}
