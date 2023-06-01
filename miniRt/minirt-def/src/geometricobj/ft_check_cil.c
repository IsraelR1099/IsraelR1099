/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cil.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:15:09 by irifarac          #+#    #+#             */
/*   Updated: 2023/05/31 13:56:31 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometricobj.h"

static double	ft_calc_a(t_cylinder *cyl, t_ray *ray)
{
	double		dot_a;
	double		dot_b;
	double		ret;
	t_vector3d	axis;

	axis.x = cyl->x_normal;
	axis.y = cyl->y_normal;
	axis.z = cyl->z_normal;
	dot_a = ft_dot_product_vect(ray->direction, ray->direction);
	dot_b = ft_dot_product_vect(ray->direction, axis);
	dot_b *= dot_b;
	ret = dot_a - dot_b;
	return (ret);
}

//ray dir dot product (origin - center) - (ray dir dot product cylinder axis) *
//(origin - center) dot product cylinder axis
static double	ft_calc_b(t_cylinder *cyl, t_ray *ray)
{
	double		dot_pro[5];
	t_vector3d	origin;
	t_vector3d	center;
	t_vector3d	orig_cent;
	t_vector3d	axis;

	axis.x = cyl->x_normal;
	axis.y = cyl->y_normal;
	axis.z = cyl->z_normal;
	origin.x = ray->origin.x;
	origin.y = ray->origin.y;
	origin.z = ray->origin.z;
	center.x = cyl->x;
	center.y = cyl->y;
	center.z = cyl->z;
	orig_cent = ft_rest_vect(origin, center);
	dot_pro[0] = ft_dot_product_vect(ray->direction, orig_cent);
	dot_pro[1] = ft_dot_product_vect(ray->direction, axis);
	dot_pro[2] = ft_dot_product_vect(orig_cent, axis);
	dot_pro[3] = dot_pro[1] * dot_pro[2];
	dot_pro[4] = dot_pro[0] - dot_pro[3];
	return (2.0 * dot_pro[4]);
}

static double	ft_calc_c(t_cylinder *cyl, t_ray *ray)
{
	t_vector3d	orig_cent;
	t_vector3d	origin;
	t_vector3d	center;
	t_vector3d	axis;
	double		dot_pro[4];

	origin.x = ray->origin.x;
	origin.y = ray->origin.y;
	origin.z = ray->origin.z;
	center.x = cyl->x;
	center.y = cyl->y;
	center.z = cyl->z;
	axis.x = cyl->x_normal;
	axis.y = cyl->y_normal;
	axis.z = cyl->z_normal;
	orig_cent = ft_rest_vect(origin, center);
	dot_pro[0] = ft_dot_product_vect(orig_cent, orig_cent);
	dot_pro[1] = ft_dot_product_vect(orig_cent, axis);
	dot_pro[1] *= dot_pro[1];
	dot_pro[2] = (cyl->diameter / 2) * (cyl->diameter / 2);
	dot_pro[3] = dot_pro[0] - dot_pro[1] - dot_pro[2];
	return (dot_pro[3]);
}

static double	ft_calc_t(t_cylinder *cyl, t_ray *ray, double scalar[3])
{
	double	ret;
	double	ret_positive;
	double	ret_negative;
	double	limits[2];

	ret = scalar[1] * scalar[1] - (4 * scalar[0] * scalar[2]);
	ret_negative = (-1) * scalar[1] - sqrt(ret) / (2 * scalar[0]);
	ret_positive = (-1) * scalar[1] + sqrt(ret) / (2 * scalar[0]);
	ft_set_limits(cyl, limits);
	if (ret_positive == ret_negative)
		return (0);
	if (ret_negative > KEPSILONSP && ft_cyl_inter(cyl, ray,
			limits, ret_negative))
		return (ret_negative);
	else if (ret_positive > KEPSILONSP && ft_cyl_inter(cyl, ray,
			limits, ret_positive))
		return (ret_positive);
	return (0);
}

double	ft_check_cil(t_cylinder *cyl, t_ray *ray, bool *plane)
{
	double	scalar[3];
	double	ret;

	scalar[0] = ft_calc_a(cyl, ray);
	scalar[1] = ft_calc_b(cyl, ray);
	scalar[2] = ft_calc_c(cyl, ray);
	ret = scalar[1] * scalar[1] - (4 * scalar[0] * scalar[2]);
	if (ret <= 0)
		return (0);
	ret = ft_calc_t(cyl, ray, scalar);
	if (ret <= 0)
	{
		ret = ft_check_cap(cyl, ray);
		if (ret <= 0)
			return (0);
		*plane = true;
		return (ret);
	}
	return (ret);
}
