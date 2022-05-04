/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 10:52:12 by irifarac          #+#    #+#             */
/*   Updated: 2022/05/04 14:00:50 by irifarac         ###   ########.fr       */
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
	generateImage(init, "Julia");
	return (1);
}

int	ft_mouse_event(int button, window *init)
{
	printf("button es %d\n", button);
	/*if (button == 4)
		init->zoom = 0.8;
	else if (button == 5)
		init->zoom = 1.25;
	else
		init->zoom = 1;*/
	(void)init;
	return (1);
}
