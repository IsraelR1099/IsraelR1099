/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersects_cylon.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoler-e <msoler-e@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:55:59 by msoler-e          #+#    #+#             */
/*   Updated: 2023/06/05 11:39:18 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometricobj.h"
#define EPSILON 1e-4

double	caps_intersection_return(double id[2],
	t_ray ray, t_cylinder cylon, t_vector3d c2)
{
	t_vector3d	ray_orig;
	t_vector3d	ip1;
	t_vector3d	ip2;
	t_vector3d	cyl_center;

	cyl_center.x = cylon.x;
	cyl_center.y = cylon.y;
	cyl_center.z = cylon.z;
	ft_ray_origin(ray, &ray_orig);
	ip1 = ft_sum_vect(ray_orig, ft_product_vect_scalar(ray.direction, id[0]));
	ip2 = ft_sum_vect(ray_orig, ft_product_vect_scalar(ray.direction, id[1]));
	if ((id[0] != -1 && distance(ip1, cyl_center) <= cylon.diameter / 2)
		&& (id[1] != -1 && distance(ip2, c2) <= cylon.diameter / 2))
	{	
		if (id[0] < id[1])
			return (id[0]);
		else
			return (id[1]);
	}
	else if (id[0] != -1 && distance(ip1, cyl_center) <= cylon.diameter / 2)
		return (id[0]);
	else if (id[1] != -1 && distance(ip2, c2) <= cylon.diameter / 2)
		return (id[1]);
	return (-1);
}

double	caps_intersection(t_ray ray, t_cylinder cylon,
		t_vector3d c2)
{
	double		id[2];
	t_vector3d	ray_orig;
	t_vector3d	cyl_normal;
	t_vector3d	cyl_center;

	ray_orig.x = ray.origin.x;
	ray_orig.y = ray.origin.y;
	ray_orig.z = ray.origin.z;
	ft_cyl_center_normal_rad(cylon, &cyl_normal, &cyl_center);
	id[0] = solve_plane(ray_orig, ray.direction, cyl_center, cyl_normal);
	id[1] = solve_plane(ray_orig, ray.direction, c2, cyl_normal);
	if (id[0] != -1 || id[1] != -1)
		return (caps_intersection_return(id, ray, cylon, c2));
	return (-1);
}

void	check_t(double *t, t_cylinder cylon, t_ray ray)
{
	t_vector3d	q;
	t_vector3d	p2;
	t_vector3d	cyl_normal;
	t_vector3d	cyl_center;
	t_vector3d	ray_orig;

	ft_cyl_center_normal_rad(cylon, &cyl_normal, &cyl_center);
	ray_orig.x = ray.origin.x;
	ray_orig.y = ray.origin.y;
	ray_orig.z = ray.origin.z;
	p2 = ft_sum_vect(cyl_center,
			ft_product_vect_scalar(cyl_normal, cylon.height));
	q = ft_sum_vect(ray_orig, ft_product_vect_scalar(ray.direction, *t));
	if (caps_intersection(ray, cylon, p2) == -1)
	{
		if (ft_dot_product_vect(cyl_normal, ft_rest_vect(q, cyl_center)) <= 0)
			*t = -1;
		if (ft_dot_product_vect(cyl_normal, ft_rest_vect(q, p2)) >= 0)
			*t = -1;
	}
	else
		*t = caps_intersection(ray, cylon, p2);
}

double	ft_get_cylon(double *t0, double *t1, t_cylinder cylon, t_ray ray)
{
	t_vector3d	right;
	t_vector3d	cyl_normal;
	t_vector3d	cyl_center;
	t_vector3d	ray_orig;
	double		quadratic[3];

	ft_cyl_center_normal_rad(cylon, &cyl_normal, &cyl_center);
	ft_ray_origin(ray, &ray_orig);
	quadratic[0] = ft_dot_product_vect(a_sqrt(ray, cyl_normal),
			a_sqrt(ray, cyl_normal));
	right = ft_rest_vect(ft_rest_vect(ray_orig, cyl_center),
			ft_product_vect_scalar(cyl_normal,
				ft_dot_product_vect(ft_rest_vect(ray_orig,
						cyl_center), cyl_normal)));
	quadratic[1] = 2 * ft_dot_product_vect(a_sqrt(ray, cyl_normal), right);
	quadratic[2] = ft_dot_product_vect(right, right)
		- ((cylon.diameter / 2) * (cylon.diameter / 2));
	if (!solve_quadratic(quadratic, t0, t1))
		return (0);
	return (1);
}

double	ft_check_cylon(t_cylinder cylon, t_ray ray)
{
	double	t0;
	double	t1;

	if (!ft_get_cylon(&t0, &t1, cylon, ray))
		return (0);
	if (t0 > 0)
		check_t(&t0, cylon, ray);
	if (t1 > 0)
		check_t(&t1, cylon, ray);
	if (t0 < 0 && t1 < 0)
		return (0);
	return (ft_return(t1, t0));
}
