/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_rf_cylon_utilites2.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:26:45 by msoler-e          #+#    #+#             */
/*   Updated: 2023/06/07 09:26:56 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "materials.h"

t_vector3d	a_sqrt(t_ray ray, t_vector3d cyl_normal)
{
	return (ft_rest_vect(ray.direction, ft_product_vect_scalar(cyl_normal,
				ft_dot_product_vect(ray.direction, cyl_normal))));
}

int	solve_quadratic(double quadratic[3], double *x0, double *x1)
{
	double	discr;
	double	q;

	discr = pow(quadratic[1], 2) - 4 * quadratic[0] * quadratic[2];
	if (discr < 0)
		return (0);
	else if (discr == 0)
	{
		*x0 = -0.5 * quadratic[1] / quadratic[0];
		*x1 = -0.5 * quadratic[1] / quadratic[0];
	}
	else
	{
		if (quadratic[1] > 0)
			q = -1 * (quadratic[1] + sqrt(discr)) / 2;
		else
			q = -1 * (quadratic[1] - sqrt(discr)) / 2;
		*x0 = q / quadratic[0];
		*x1 = quadratic[2] / q;
	}
	if (*x0 > *x1)
		swap_doubles(x0, x1);
	return (1);
}

double	ft_return(double t1, double t0)
{
	double	t;

	t = 0;
	if (t1 < t0)
	{
		if (t1 > 0)
			t = t1;
		else
			t = t0;
	}
	else
	{
		if (t0 > 0)
			t = t0;
		else
			t = t1;
	}
	return (t);
}
