/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 10:52:12 by irifarac          #+#    #+#             */
/*   Updated: 2022/05/10 13:50:21 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_fractal.h"
#include "mlx/mlx.h"

int	key_event(int button, window *init)
{
	printf("button es %d\n", button);
	if (button == 53)
	{
		mlx_destroy_window(init->mlx, init->mlx_win);
		exit(1);
	}
	//Mover arriba 
	else if (button == 126)
		init->trl_y += 15;
	//Mover abajo
	else if (button == 125)
		init->trl_y -= 15;
	//Mover hacia la izquierda
	else if (button == 124)
		init->trl_x -= 15;
	//Mover hacia la derecha
	else if (button == 123)
		init->trl_x += 15;
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
	generateImage(init, init->values->fract_type);
	return (1);
}

int	ft_mouse_event(int button,int x, int y, window *init)
{

	printf("button es %d, x es %d, y es %d\n", button, x, y);

	if (button == 5)
	{
		init->trl_x += x - 640 * (init->zoom_x);
		init->trl_y += y - 360 * (init->zoom_y);
		printf("entro\n");
		if (init->zoom_x <= 0.1 && init->zoom_y <= 0.1)
		{
			init->zoom_x -= 0.01;
			init->zoom_y -= 0.01;
			printf("entro en if zoom x %f y zoom y %f\n", init->zoom_x, init->zoom_y);
			generateImage(init, init->values->fract_type);
		}
		init->zoom_x -= 0.02;
		init->zoom_y -= 0.02;
		printf("zoom x %f y zoom y %f\n", init->zoom_x, init->zoom_y);
		generateImage(init, init->values->fract_type);
	}
	else if (button == 4)
	{
		init->trl_x += x - 640 * (init->zoom_x);
		init->trl_y += y - 360 * (init->zoom_y);
		init->zoom_x += 0.02;
		init->zoom_y += 0.02;
		generateImage(init, init->values->fract_type);
	}
	return (1);
}
