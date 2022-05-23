/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iteration.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 11:55:36 by irifarac          #+#    #+#             */
/*   Updated: 2022/05/23 14:03:16 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_fractal.h"
#include "mlx/mlx.h"

int	ft_iter_mandel(window *init, double x, double y)
{
	int	iter;

	iter = 1;
	init->inf->a_temp = 0;
	init->inf->b_temp = 0;
	while (iter <= init->max_iter)
	{
		init->inf->a = ft_calcx(init->inf->a_temp, init->inf->b_temp, x);
		init->inf->b = ft_calcy(init->inf->a_temp, init->inf->b_temp, y);
		if (sqrt((init->inf->a * init->inf->a)
				+ (init->inf->b * init->inf->b)) >= 2)
			return (iter);
		init->inf->a_temp = init->inf->a;
		init->inf->b_temp = init->inf->b;
		iter++;
	}
	return (0);
}

int	ft_iter_julia(window *init, double a_temp, double b_temp)
{
	int	iter;

	iter = 1;
	while (iter <= init->max_iter)
	{
		init->inf->a = ft_calcx(a_temp, b_temp, init->inf->x_julia);
		init->inf->b = ft_calcy(a_temp, b_temp, init->inf->y_julia);
		if (sqrt((init->inf->a * init->inf->a)
				+ (init->inf->b * init->inf->b)) >= 2)
			return (iter);
		a_temp = init->inf->a;
		b_temp = init->inf->b;
		iter++;
	}
	return (0);
}
