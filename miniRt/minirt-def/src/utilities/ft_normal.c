/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 09:49:08 by irifarac          #+#    #+#             */
/*   Updated: 2023/05/17 13:33:03 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shaderec.h"

t_normal	ft_vect_normal_sphere(t_sphere *sphere, t_point3d hit_point)
{
	t_vector3d	center_sph;
	t_vector3d	hit_p;
	t_vector3d	rest;
	t_normal	ret;
	double		magnitude;

	center_sph.x = sphere->x;
	center_sph.y = sphere->y;
	center_sph.z = sphere->z;
	hit_p.x = hit_point.x;
	hit_p.y = hit_point.y;
	hit_p.z = hit_point.z;
	rest = ft_rest_vect(hit_p, center_sph);
	magnitude = sqrt(rest.x * rest.x + rest.y * rest.y
			+ rest.z * rest.z);
	ret.x = rest.x / magnitude;
	ret.y = rest.y / magnitude;
	ret.z = rest.z / magnitude;
	ret.x *= -1;
	ret.y *= -1;
	ret.z *= -1;
	return (ret);
}

t_vector3d	ft_normalize(t_vector3d vector)
{
	double		magnitude;
	t_vector3d	normal;

	magnitude = sqrt(vector.x * vector.x + vector.y * vector.y
			+ vector.z * vector.z);
	normal.x = vector.x;
	normal.y = vector.y;
	normal.z = vector.z;
	normal.x /= magnitude;
	normal.y /= magnitude;
	normal.z /= magnitude;
	return (normal);
}

/*static t_normal	ft_transform_normal(t_normal ret)
{
	t_normal	new_normal;

	new_normal.x = ret.x * (cos(PI/2) - sin(PI/2));
	new_normal.y = ret.y;
	new_normal.z = ret.z * (cos(PI/2) + cos(PI/2));
	return (new_normal);
}*/

static void	ft_check_n(t_cylinder *cyl, t_vector3d *point, double radius)
{
	t_vector3d	n;

	n.x = cyl->x_normal;
	n.y = cyl->y_normal;
	n.z = cyl->z_normal;
	if (n.x == 1 && n.y == 0 && n.z == 0)
	{
		point->x = 0.0;
		point->y = point->y * radius;
		point->z = point->z * radius;
	}
	else if (n.x == 0 && n.y == 1 && n.z == 0)
	{
		point->x = point->x * radius;
		point->y = 0.0;
		point->z = point->z * radius;
	}
	else if (n.x == 0 && n.y == 0 && n.z == 1)
	{
		point->x = point->x * radius;
		point->y = point->y * radius;
		point->z = 0.0;
	}
}

t_normal	ft_vect_normal_cyl(t_cylinder *cylon, t_point3d hit_point)
{
	t_vector3d	point;
	t_vector3d	hit;
	t_vector3d	center;
	t_normal	ret;
	double		radius;

	center.x = cylon->x;
	center.y = cylon->y;
	center.z = cylon->z;
	hit.x = hit_point.x;
	hit.y = hit_point.y;
	hit.z = hit_point.z;
	point = ft_rest_vect(hit, center);
	radius = cylon->diameter / 2;
/*	point.x = point.x * radius;
	point.y = 0.0;
	point.z = point.z * radius;*/
	ft_check_n(cylon, &point, radius);
	point = ft_normalize(point);
	ret.x = point.x;
	ret.y = point.y;
	ret.z = point.z;
	//ret = ft_transform_normal(ret);
	return (ret);
/*	t_vector3d	hit_center;
	t_vector3d	center;
	t_vector3d	hit;
	t_vector3d	normal;
	t_vector3d	multi;
	t_vector3d	ret;
	t_normal	ret_normal;
	double		magnitude;

	center.x = cylon->x;
	center.y = cylon->y;
	center.z = cylon->z;
	hit.x = hit_point.x;
	hit.y = hit_point.y;
	hit.z = hit_point.z;
	hit_center = ft_rest_vect(hit, center);
	normal.x = cylon->x_normal;
	normal.y = cylon->y_normal;
	normal.z = cylon->z_normal;
	multi = ft_vectorial_product(normal, hit_center);
	multi = ft_vectorial_product(multi, normal);
	ret = ft_rest_vect(hit_center, multi);
	magnitude = sqrt(ret.x * ret.x + ret.y * ret.y
			+ ret.z * ret.z);
	ret_normal.x = ret.x / magnitude;
	ret_normal.y = ret.y / magnitude;
	ret_normal.z = ret.z / magnitude;
	return (ret_normal);*/
}
