/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iteration2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 10:05:14 by irifarac          #+#    #+#             */
/*   Updated: 2022/06/01 09:39:06 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_fractal.h"

int	ft_julg(t_window *init, double atmp, double btmp)
{
	int	iter;

	iter = 1;
	while (iter <= init->max_iter)
	{
		init->inf->a = ft_glnx(atmp, btmp, init->inf->x_julia);
		init->inf->b = ft_glny(atmp, btmp, init->inf->y_julia);
		if (sqrt((init->inf->a * init->inf->a)
				+ (init->inf->b * init->inf->b)) >= 2)
			return (iter);
		atmp = init->inf->a;
		btmp = init->inf->b;
		iter++;
	}
	return (0);
}

int	ft_ijul3(t_window *init, double atmp, double btmp)
{
	int	iter;

	iter = 1;
	while (iter <= init->max_iter)
	{
		init->inf->a = ft_calcx_3(atmp, btmp, init->inf->x_julia);
		init->inf->b = ft_calcy_3(atmp, btmp, init->inf->y_julia);
		if (sqrt((init->inf->a * init->inf->a)
				+ (init->inf->b * init->inf->b)) >= 2)
			return (iter);
		atmp = init->inf->a;
		btmp = init->inf->b;
		iter++;
	}
	return (0);
}
