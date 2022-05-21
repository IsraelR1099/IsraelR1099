/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_plus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:43:07 by irifarac          #+#    #+#             */
/*   Updated: 2022/05/21 10:01:17 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_fractal.h"
#include "mlx/mlx.h"

double	pixel_to_point_x(window *init, int pixel_x)
{
	double	value_x;

	value_x = 0;
	value_x = (((2 * 4 * init->zoom_x) * (float)pixel_x) / HEIGHT) - (4 * init->zoom_x);
	return (value_x);
}

double	pixel_to_point_y(window *init, int pixel_y)
{
	double	value_y;

	value_y = 0;
	value_y = (3 * init->zoom_y) - (((2 * 3 * init->zoom_y) * (float)pixel_y) / WIDTH);
	return (value_y);
}
