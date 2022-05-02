/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 10:52:12 by irifarac          #+#    #+#             */
/*   Updated: 2022/05/02 13:34:29 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_fractal.h"
#include "mlx/mlx.h"

int	key_event(int button, window *param, int value)
{
	printf("button es %d\n", button);
	if (button == 53)
		mlx_destroy_window(param->mlx, param->mlx_win);
	if (button == 126)
		value += 3;
	return (1);
}
