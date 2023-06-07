/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reflective_f.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:46:23 by irifarac          #+#    #+#             */
/*   Updated: 2023/05/10 11:50:10 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "materials.h"

// wi calc = -wo + 2.0 * normal * ndotwo
static t_vector3d	ft_calc_wi(t_vector3d wo, t_vector3d normal, double ndotwo)
{
	t_vector3d	sum_wo;
	t_vector3d	dot;

	dot = ft_product_vect_scalar(normal, ndotwo * 2.0);
	sum_wo = ft_sum_vect(wo, dot);
	return (sum_wo);
}

// total kr * cr / (normal * wi)
static t_rgb	ft_color_value(t_shaderec *shade, t_vector3d *wi,
t_vector3d normal)
{
	double		kr;
	double		angle_normal_wi;
	t_rgb		reflective;
	t_rgb		ret;

	kr = 0.75;
	reflective = ft_rgb_scalar_product(shade->colour, kr);
	angle_normal_wi = ft_dot_product_vect(normal, *wi);
	ret = ft_rgb_division(reflective, angle_normal_wi);
	return (ret);
}

t_rgb	ft_reflective_f(t_shaderec *shade, t_vector3d wo,
t_vector3d *wi)
{
	double		ndotwo;
	t_vector3d	tmp_wi;
	t_vector3d	normal;

	normal.x = shade->normal_hit.x;
	normal.y = shade->normal_hit.y;
	normal.z = shade->normal_hit.z;
	wo.x = (-1) * shade->ray.direction.x;
	wo.y = (-1) * shade->ray.direction.y;
	wo.z = (-1) * shade->ray.direction.z;
	ndotwo = ft_dot_product_vect(normal, shade->ray.direction);
	tmp_wi = ft_calc_wi(wo, normal, ndotwo);
	wi->x = tmp_wi.x;
	wi->y = tmp_wi.y;
	wi->z = tmp_wi.z;
	return (ft_color_value(shade, wi, normal));
}
