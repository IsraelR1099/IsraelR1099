/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cil_util.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:18:30 by irifarac          #+#    #+#             */
/*   Updated: 2023/05/31 14:00:24 by irifarac         ###   ########.fr       */
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

bool	ft_cyl_inter(t_cylinder *cyl, t_ray *ray, double limits[2], double t)
{
	t_point3d	hit_p;
	t_vector3d	hit[2];
	t_vector3d	cyl_center;
	t_vector3d	axis;
	double		hit_projection;

	cyl_center.x = cyl->x;
	cyl_center.y = cyl->y;
	cyl_center.z = cyl->z;
	axis.x = cyl->x_normal;
	axis.y = cyl->y_normal;
	axis.z = cyl->z_normal;
	hit_p = ft_hit(ray, t);
	hit[0].x = hit_p.x;
	hit[0].y = hit_p.y;
	hit[0].z = hit_p.z;
	hit[1] = ft_rest_vect(hit[0], cyl_center);
	hit_projection = ft_dot_product_vect(hit[1], axis);
//	if (hit_projection >= limits[0] && hit_projection <= limits[1])
//		return (true);
	if (hit_projection >= 0 && hit_projection <= cyl->height)
		return (true);
	(void)limits;
	return (false);
}

static double	ft_length_vec(t_vector3d vec)
{
	double	len;

	len = sqrt(vec.x * vec.x + vec.y * vec.y
			+ vec.z * vec.z);
	return (len);
}

double	ft_cap_t(t_vector3d cap, t_ray *ray)
{
	t_vector3d	origin;
	t_vector3d	v_subs;
	double		len_cap;
	double		len_dir;

	origin.x = ray->origin.x;
	origin.y = ray->origin.y;
	origin.z = ray->origin.z;
	v_subs = ft_rest_vect(cap, origin);
	len_cap = ft_length_vec(v_subs);
	len_dir = ft_length_vec(ray->direction);
	return (len_cap / len_dir);
}
