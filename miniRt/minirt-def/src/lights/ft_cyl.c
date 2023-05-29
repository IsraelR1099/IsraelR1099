/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cyl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:28:45 by irifarac          #+#    #+#             */
/*   Updated: 2023/05/29 09:24:39 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lights.h"

//a = d.x² + d.z²
static double	ft_calc_a(t_ray ray)
{
	double	first;
	double	second;

	first = ray.direction.y * ray.direction.y;
	second = ray.direction.z * ray.direction.z;
	return (first + second);
}

//2 * (origin.x² + origin.z²)
static double	ft_calc_b(t_cylinder *cyl, t_ray ray)
{
	double		first;
	double		second;
	t_vector3d	pos_center;
	t_vector3d	origin;
	t_vector3d	cyl_center;

	/*first = ray->origin.x * ray->direction.x;
	second = ray->origin.z * ray->direction.z;*/
//	printf("first es %f second %f\n", first, second);
	origin.x = ray.origin.x;
	origin.y = ray.origin.y;
	origin.z = ray.origin.z;
	cyl_center.x = cyl->x;
	cyl_center.y = cyl->y;
	cyl_center.z = cyl->z;
	pos_center = ft_rest_vect(origin, cyl_center);
	first = ray.direction.y * pos_center.y;
	second = ray.direction.z * pos_center.z;
	return (2.0 * (first + second));
}

//origin.x² + origin.z² - radius²
static double	ft_calc_c(t_cylinder *cyl, t_ray ray)
{
	double	radius;
	double	first;
	double	second;

/*	first = ray->origin.x * ray->origin.x;
	second = ray->origin.z * ray->origin.z;*/
	first = (ray.origin.y - cyl->y) * (ray.origin.y - cyl->y);
	second = (ray.origin.z - cyl->z) * (ray.origin.z - cyl->z);
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
	if (check > 0)
	{
		check = ((-1 * scalar_b) - sqrt(first - second)) / (2.0 * scalar_a);
		if (check > 0.001)
			return (check);
		check = ((-1 * scalar_b) + sqrt(first - second)) / (2.0 * scalar_a);
		if (check > 0.001)
			return (check);
	}
	return (0);
}

double	ft_hit_cyl(t_cylinder *cyl, t_ray ray)
{
	double	scalar_a;
	double	scalar_b;
	double	scalar_c;
	double	t;

	t = ft_check_l_normal(cyl, &ray);
	if (t > 0)
		return (t);
	scalar_a = ft_calc_a(ray);
	scalar_b = ft_calc_b(cyl, ray);
	scalar_c = ft_calc_c(cyl, ray);
	t = ft_check(scalar_a, scalar_b, scalar_c);
	if (t <= 0)
		return (0);
	return (t);
}
