/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 09:49:08 by irifarac          #+#    #+#             */
/*   Updated: 2023/06/07 09:53:57 by irifarac         ###   ########.fr       */
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

int	ft_caps(t_vector3d point, t_vector3d normal,
t_cylinder *cylon, t_normal *ret)
{
	float	distancetotopcap;
	float	distancetobottomcap;

	distancetotopcap = ft_dot_product_vect(point, normal) + cylon->height / 2.0;
	distancetobottomcap = ft_dot_product_vect(point, normal)
		- cylon->height / 2.0;
	if (fabsf(distancetotopcap) < EPSILON)
	{
		ret->x = normal.x;
		ret->y = normal.y;
		ret->z = normal.z;
		return (1);
	}
	if (fabsf(distancetobottomcap) < EPSILON)
	{
		ret->x = normal.x;
		ret->y = normal.y;
		ret->z = normal.z;
		return (1);
	}
	return (0);
}

t_normal	ft_vect_normal_cyl(t_cylinder *cylon, t_point3d hit_point)
{
	double		projection;
	t_vector3d	normal;
	t_vector3d	point;
	t_vector3d	normalizedvector;
	t_normal	ret;

	normal.x = cylon->x_normal;
	normal.y = cylon->y_normal;
	normal.z = cylon->z_normal;
	point.x = hit_point.x - cylon->x;
	point.y = hit_point.y - cylon->y;
	point.z = hit_point.z - cylon->z;
	if (ft_caps(point, normal, cylon, &ret))
		return (ret);
	projection = ft_dot_product_vect(point, normal);
	normalizedvector = ft_normalize
		(ft_rest_vect(ft_product_vect_scalar(normal, projection), point));
	ret.x = normalizedvector.x;
	ret.y = normalizedvector.y;
	ret.z = normalizedvector.z;
	return (ret);
}
