/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:08:28 by irifarac          #+#    #+#             */
/*   Updated: 2023/06/02 11:08:29 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometricobj.h"

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

static double	ft_value_a(t_point3d origin, t_cylinder *cyl)
{
	t_vector3d	ori;
	t_vector3d	n_plane;
	t_vector3d	point;
	t_vector3d	rest;

	n_plane.x = cyl->x_normal;
	n_plane.y = cyl->y_normal;
	n_plane.z = cyl->z_normal;
	ori.x = origin.x;
	ori.y = origin.y;
	ori.z = origin.z;
	point.x = cyl->x;
	point.y = cyl->y;
	point.z = cyl->z;
	rest = ft_rest_vect(point, ori);
	return (ft_dot_product_vect(n_plane, rest));
}

static bool	ft_check_p(t_cylinder *cyl, t_ray *ray, double t, double radius)
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
	center.x = cyl->x;
	center.y = cyl->y;
	center.z = cyl->z;
	rest = ft_rest_vect(vec_point, center);
	distance = sqrt(rest.x * rest.x + rest.y * rest.y
			+ rest.z * rest.z);
	if (distance > radius)
		return (false);
	return (true);
}

double	ft_check_cap(t_cylinder *cyl, t_ray *ray)
{
	t_vector3d	n_plane;
	bool		in_disk;
	double		ret_b;
	double		t;

	n_plane.x = cyl->x_normal;
	n_plane.y = cyl->y_normal;
	n_plane.z = cyl->z_normal;
	in_disk = false;
	ret_b = ft_dot_product_vect(n_plane, ray->direction);
	if (ret_b == 0)
		return (0);
	t = ft_value_a(ray->origin, cyl);
	if (t < KEPSILONPL)
		return (0);
	in_disk = ft_check_p(cyl, ray, t, cyl->diameter / 2);
	if (in_disk == false)
		return (0);
	return (t);
}
