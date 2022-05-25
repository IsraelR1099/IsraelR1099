/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iteration.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 11:55:36 by irifarac          #+#    #+#             */
/*   Updated: 2022/05/25 12:02:03 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_fractal.h"

int	ft_iter_mandel(t_window *init, double x, double y)
{
	int	iter;

	iter = 1;
	init->inf->atmp = 0;
	init->inf->btmp = 0;
	while (iter <= init->max_iter)
	{
		init->inf->a = ft_calcx(init->inf->atmp, init->inf->btmp, x);
		init->inf->b = ft_calcy(init->inf->atmp, init->inf->btmp, y);
		if (sqrt((init->inf->a * init->inf->a)
				+ (init->inf->b * init->inf->b)) >= 2)
			return (iter);
		init->inf->atmp = init->inf->a;
		init->inf->btmp = init->inf->b;
		iter++;
	}
	return (0);
}

int	ft_ijulia(t_window *init, double atmp, double btmp)
{
	int	iter;

	iter = 1;
	while (iter <= init->max_iter)
	{
		init->inf->a = ft_calcx(atmp, btmp, init->inf->x_julia);
		init->inf->b = ft_calcy(atmp, btmp, init->inf->y_julia);
		if (sqrt((init->inf->a * init->inf->a)
				+ (init->inf->b * init->inf->b)) >= 2)
			return (iter);
		atmp = init->inf->a;
		btmp = init->inf->b;
		iter++;
	}
	return (0);
}
