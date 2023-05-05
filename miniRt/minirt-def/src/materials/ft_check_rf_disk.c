/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_rf_disk.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:56:57 by irifarac          #+#    #+#             */
/*   Updated: 2023/05/05 12:51:21 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "materials.h"

static t_point3d	ft_hit(t_ray *ray, double t)
{
	t_vector3d	b;
	t_vector3d	sum;
	t_vector3d	origin;
	t_point3d	ret;

	origin.x = ray->origin.x;
	origin.y = ray->origin.y;
	origin.z = ray->origin.z;
	b = ft_product_vect_scalar(ray->direction, t);
	sum = ft_sum_vect(origin, b);
	ret.x = sum.x;
	ret.y = sum.y;
	ret.z = sum.z;
	return (ret);
}

static double	ft_a_value(t_point3d eye, t_disk *disk)
{
	t_vector3d	origin;
	t_vector3d	center;
	t_vector3d	normal;
	t_vector3d	rest_c_o;

	origin.x = eye.x;
	origin.y = eye.y;
	origin.z = eye.z;
	center.x = disk->x;
	center.y = disk->y;
	center.z = disk->z;
	normal.x = disk->x_normal;
	normal.y = disk->y_normal;
	normal.z = disk->z_normal;
	rest_c_o = ft_rest_vect(center, origin);
	return (ft_dot_product_vect(rest_c_o, normal));
}

static bool	ft_check_point(t_disk *disk, t_ray *ray, double t, double radius)
{
	t_point3d	point;
	t_vector3d	vec_point;
	t_vector3d	center;
	t_vector3d	rest;
	double		distance;

	point = ft_hit(ray, t);
	vec_point.x = point.x;
	vec_point.y = point.y;
	vec_point.z = point.z;
	center.x = disk->x;
	center.y = disk->y;
	center.z = disk->z;
	rest = ft_rest_vect(vec_point, center);
	distance = sqrt(rest.x * rest.x + rest.y * rest.y
			+ rest.z * rest.z);
	if (distance > radius)
		return (false);
	return (true);
}

double	ft_check_rf_disk(t_disk *disk, t_ray *ray)
{
	t_vector3d	normal_disk;
	bool		in_disk;
	double		ret_b;
	double		t;

	normal_disk.x = disk->x_normal;
	normal_disk.y = disk->y_normal;
	normal_disk.z = disk->z_normal;
	in_disk = false;
	ret_b = ft_dot_product_vect(normal_disk, ray->direction);
	if (ret_b == 0)
		return (0);
	t = ft_a_value(ray->origin, disk) / ret_b;
	if (t < KEPSILONDI)
		return (0);
	in_disk = ft_check_point(disk, ray, t, disk->radius);
	if (in_disk == false)
		return (0);
	return (t);
}
