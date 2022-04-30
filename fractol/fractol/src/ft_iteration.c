/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iteration.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 11:55:36 by irifarac          #+#    #+#             */
/*   Updated: 2022/04/30 13:33:43 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_fractal.h"
#include "mlx/mlx.h"

int	ft_iterationMandelbrot(points *values, double x, double y)
{
	int	iter;

	iter = 1;
	values->a_temp = 0;
	values->b_temp = 0;
	while (iter <= 50)
	{
		values->a = ft_calcx(values->a_temp, values->b_temp, x);
		values->b = ft_calcy(values->a_temp, values->b_temp, y);
		if (sqrt(pow(values->a, 2) + pow(values->b, 2)) > 2)
			return (iter);
		values->a_temp = values->a;
		values->b_temp = values->b;
		iter++;
	}
	return (0);
}
