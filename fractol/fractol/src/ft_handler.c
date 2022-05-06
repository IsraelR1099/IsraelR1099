/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 10:52:12 by irifarac          #+#    #+#             */
/*   Updated: 2022/05/06 12:04:20 by irifarac         ###   ########.fr       */
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
	else if (button == 124)
		init->trl += 10;
	else if (button == 123)
		init->trl -= 10;
	else if (button == 69)
		init->max_iter += 3;
	else if (button == 78)
		init->max_iter -= 3;
	else if (button == 15)
	{
		init->zoom_x = 1;
		init->zoom_y = 1;
		init->trl = 0;
	}
	generateImage(init, init->values->fract_type);
	return (1);
}

int	ft_mouse_event(int button,int x, int y, window *init)
{
	(void)x;
	(void)y;
	printf("button es %d\n", button);
/*	if (button == 4)
	{
		init->zoom_y = 374;
		generateImage(init, init->values->fract_type);
	}*/
	if (button == 5)
	{
		printf("entro\n");
		init->zoom_x += 0.25;
		init->zoom_y += 0.25 ;
		generateImage(init, init->values->fract_type);
	}
	else if (button == 4)
	{
		init->zoom_x -= 0.25;
		init->zoom_y -= 0.25;
		generateImage(init, init->values->fract_type);
	}
	return (1);
}
