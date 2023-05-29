/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cyl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 09:59:21 by irifarac          #+#    #+#             */
/*   Updated: 2023/05/29 10:31:09 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "materials.h"

//a = d.x² + d.z²
static double	ft_calc_a(t_ray *ray)
{
	double	first;
	double	second;

	first = ray->direction.x * ray->direction.x;
	second = ray->direction.z * ray->direction.z;
	return (first + second);
}

//2 * (origin.x² + origin.z²)
static double	ft_calc_b(t_cylinder *cyl, t_ray *ray)
{
	double		first;
	double		second;
	t_vector3d	pos_center;
	t_vector3d	origin;
	t_vector3d	cyl_center;

	origin.x = ray->origin.x;
	origin.y = ray->origin.y;
	origin.z = ray->origin.z;
	cyl_center.x = cyl->x;
	cyl_center.y = cyl->y;
	cyl_center.z = cyl->z;
	pos_center = ft_rest_vect(origin, cyl_center);
	first = ray->direction.x * pos_center.x;
	second = ray->direction.z * pos_center.z;
	return (2.0 * (first + second));
}

//origin.x² + origin.z² - radius²
static double	ft_calc_c(t_cylinder *cyl, t_ray *ray)
{
	double	radius;
	double	first;
	double	second;

	first = (ray->origin.x - cyl->x) * (ray->origin.x - cyl->x);
	second = (ray->origin.z - cyl->z) * (ray->origin.z - cyl->z);
	radius = cyl->diameter / 2;
	return (first + second - (radius * radius));
}

static double	ft_check(double scalar_a, double scalar_b, double scalar_c)
{
	double	first;
	double	second;
	double	check;

	first = scalar_b * scalar_b;
	second = 4.0 * scalar_a * scalar_c;
	check = first - second;
	if (check >= 0)
	{
		check = ((-1 * scalar_b) - sqrt(first - second)) / (2.0 * scalar_a);
		if (check > 0.0001)
			return (check);
		check = ((-1 * scalar_b) + sqrt(first - second)) / (2.0 * scalar_a);
		if (check > 0.0001)
			return (check);
	}
	return (0);
}

double	ft_check_rf_cyly(t_cylinder *cyl, t_ray *ray)
{
	double	scalar_a;
	double	scalar_b;
	double	scalar_c;
	double	t;

	scalar_a = ft_calc_a(ray);
	scalar_b = ft_calc_b(cyl, ray);
	scalar_c = ft_calc_c(cyl, ray);
//	printf("scalar a %f, b %f, c %f\n", scalar_a, scalar_b, scalar_c);
	t = ft_check(scalar_a, scalar_b, scalar_c);
	if (t <= 0)
		return (0);
	return (t);
}
