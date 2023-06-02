/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_caps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:12:23 by irifarac          #+#    #+#             */
/*   Updated: 2023/05/31 13:36:52 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometricobj.h"

static double	ft_dot_origin(t_cylinder *cyl, t_ray *ray)
{
	double		v_dot;
	t_vector3d	origin;
	t_vector3d	axis;

	origin.x = ray->origin.x;
	origin.y = ray->origin.y;
	origin.z = ray->origin.z;
	axis.x = cyl->x_normal;
	axis.y = cyl->y_normal;
	axis.z = cyl->z_normal;
	v_dot = ft_dot_product_vect(origin, axis);
	return (v_dot);
}

static double	ft_dot_dir(t_cylinder *cyl, t_ray *ray)
{
	t_vector3d	axis;
	double		v_dot;

	axis.x = cyl->x_normal;
	axis.y = cyl->y_normal;
	axis.z = cyl->z_normal;
	v_dot = ft_dot_product_vect(ray->direction, axis);
	return (v_dot);
}

static t_vector3d	ft_cap_start(double limit[2], t_ray *ray, double ret)
{
	t_vector3d	v_mult;
	t_vector3d	v_add;
	t_vector3d	origin;
	double		cap;

	cap = limit[0] - ret;
	v_mult = ft_product_vect_scalar(ray->direction, cap);
	origin.x = ray->origin.x;
	origin.y = ray->origin.y;
	origin.z = ray->origin.z;
	v_add = ft_sum_vect(origin, v_mult);
	return (v_add);
}

static t_vector3d	ft_cap_end(double limit[2], t_ray *ray, double ret)
{
	t_vector3d	v_mult;
	t_vector3d	v_add;
	t_vector3d	origin;
	double		cap;

	cap = limit[1] - ret;
	v_mult = ft_product_vect_scalar(ray->direction, cap);
	origin.x = ray->origin.x;
	origin.y = ray->origin.y;
	origin.z = ray->origin.z;
	v_add = ft_sum_vect(origin, v_mult);
	return (v_add);
}

double	ft_check_caps(t_cylinder *cyl, t_ray *ray)
{
	double		v_dot[3];
	double		dot[2];
	double		limit[2];
	t_vector3d	caps[2];
	double		radius;

	radius = cyl->diameter / 2;
	v_dot[0] = ft_dot_origin(cyl, ray);
	v_dot[1] = ft_dot_dir(cyl, ray);
	v_dot[2] = v_dot[0] / v_dot[1];
	ft_set_limits(cyl, limit);
	caps[0] = ft_cap_start(limit, ray, v_dot[2]);
	caps[1] = ft_cap_end(limit, ray, v_dot[2]);
	dot[0] = ft_dot_product_vect(caps[0], caps[0]);
	dot[1] = ft_dot_product_vect(caps[1], caps[1]);
	if (caps[0].x >= limit[0] && dot[0] <= sqrt(radius))
		return (ft_cap_t(caps[0], ray));
	else if (caps[1].x >= limit[1] && dot[1] <= sqrt(radius))
		return (ft_cap_t(caps[1], ray));
	return (0);
}
