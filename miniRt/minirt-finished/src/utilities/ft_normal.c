/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 09:49:08 by irifarac          #+#    #+#             */
/*   Updated: 2023/06/02 12:51:50 by irifarac         ###   ########.fr       */
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

/*double	ft_calc_m(t_cylinder *cyl, t_ray *ray, double t)
{
	double		ret[3];
	t_vector3d	axis;
	t_vector3d	orig;
	t_vector3d	center;
	t_vector3d	ori_center;

	orig.x = ray->origin.x;
	orig.y = ray->origin.y;
	orig.z = ray->origin.z;
	center.x = cyl->x;
	center.y = cyl->y;
	center.z = cyl->z;
	axis.x = cyl->x_normal;
	axis.y = cyl->y_normal;
	axis.z = cyl->z_normal;
	ret[0] = ft_dot_product_vect(ray->direction, axis);
	ret[0] *= t;
	ori_center = ft_rest_vect(orig, center);
	ret[1] = ft_dot_product_vect(ori_center, axis);
	ret[2] = ret[0] + ret[1];
	return (ret[2]);
}*/

double	ft_calc_m(t_cylinder *cyl, t_point3d hit_p)
{
	t_vector3d	hit;
	t_vector3d	center;
	t_vector3d	p_center;
	t_vector3d	axis;
	double		ret;

	hit.x = hit_p.x;
	hit.y = hit_p.y;
	hit.z = hit_p.z;
	center.x = cyl->x;
	center.y = cyl->y;
	center.z = cyl->z;
	axis.x = cyl->x_normal;
	axis.y = cyl->y_normal;
	axis.z = cyl->z_normal;
	p_center = ft_rest_vect(hit, center);
	ret = ft_dot_product_vect(p_center, axis);
	return (ret);
}

//t_normal	ft_vect_ncyl(t_cylinder *cyl, t_ray *ray, t_point3d hit_p, double t)
t_normal	ft_vect_ncyl(t_cylinder *cyl, t_point3d hit_p)
{
	t_vector3d	tools[2];
	t_vector3d	axis;
	t_vector3d	ret[3];
	double		m;
	t_normal	normal;

	m = ft_calc_m(cyl, hit_p);
	tools[0].x = hit_p.x;
	tools[0].y = hit_p.y;
	tools[0].z = hit_p.z;
	tools[1].x = cyl->x;
	tools[1].y = cyl->y;
	tools[1].z = cyl->z;
	axis.x = cyl->x_normal;
	axis.y = cyl->y_normal;
	axis.z = cyl->z_normal;
	ret[0] = ft_rest_vect(tools[0], tools[1]);
	ret[1] = ft_rest_vect(ret[0], axis);
	ret[2] = ft_product_vect_scalar(ret[1], m);
	ret[2] = ft_normalize(ret[2]);
	normal.x = ret[2].x;
	normal.y = ret[2].y;
	normal.z = ret[2].z;
	return (normal);
}
