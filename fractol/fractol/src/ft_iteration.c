/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iteration.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 11:55:36 by irifarac          #+#    #+#             */
/*   Updated: 2022/05/04 14:09:06 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_fractal.h"
#include "mlx/mlx.h"

int	ft_iterationMandelbrot(window *init, double x, double y)
{
	int	iter;

	iter = 1;
	init->values->a_temp = 0;
	init->values->b_temp = 0;
	while (iter <= init->max_iter)
	{
		init->values->a = ft_calcx(init->values->a_temp, init->values->b_temp, x);
		init->values->b = ft_calcy(init->values->a_temp, init->values->b_temp, y);
		if (sqrt(pow(init->values->a, 2) + pow(init->values->b, 2)) > 2)
			return (iter);
		init->values->a_temp = init->values->a;
		init->values->b_temp = init->values->b;
		iter++;
	}
	return (0);
}

int	ft_iterationJulia(window *init, double a_temp, double b_temp)
{
	int	iter;

	iter = 1;
	init->values->x_julia = -0.51;
	init->values->y_julia = -0.601;
	while (iter <= init->max_iter)
	{
		init->values->a = ft_calcx(a_temp, b_temp, init->values->x_julia);
		init->values->b = ft_calcy(a_temp, b_temp, init->values->y_julia);
		if (sqrt(pow(init->values->a, 2) + pow(init->values->b, 2)) > 2)
			return (iter);
		a_temp = init->values->a;
		b_temp = init->values->b;
		iter++;
	}
	return (0);
}
