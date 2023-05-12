/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:18:04 by irifarac          #+#    #+#             */
/*   Updated: 2023/05/12 13:19:58 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "materials.h"

t_vector3d	ft_dir_wo(t_shaderec *shade)
{
	t_vector3d	dir_wo;

	dir_wo = shade->ray.direction;
	dir_wo.x = shade->ray.direction.x * (-1);
	dir_wo.y = shade->ray.direction.y * (-1);
	dir_wo.z = shade->ray.direction.z * (-1);
	return (dir_wo);
}

t_vector3d	ft_normal_vector3d(t_shaderec *shade)
{
	t_vector3d	normal;

	normal.x = shade->normal_hit.x;
	normal.y = shade->normal_hit.y;
	normal.z = shade->normal_hit.z;
	return (normal);
}

t_normal	ft_vect_normal_rf_cyl(t_cylinder *cylon, t_point3d hit_point)
{
	t_vector3d	center_cyl;
	t_vector3d	hit_p;
	t_vector3d	rest;
	t_normal	ret;
	double		magnitude;

	center_cyl.x = cylon->x;
	center_cyl.y = cylon->y;
	center_cyl.z = cylon->z;
	hit_p.x = hit_point.x;
	hit_p.y = hit_point.y;
	hit_p.z = hit_point.z;
	rest = ft_rest_vect(hit_p, center_cyl);
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
