/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_rf_plane.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:54:25 by irifarac          #+#    #+#             */
/*   Updated: 2023/05/17 13:28:58 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "materials.h"

static double	ft_a_value(t_point3d eye, t_plane *plane)
{
	t_vector3d	origin;
	t_vector3d	rest_point_orig;
	t_vector3d	normal_plane;
	t_vector3d	point_plane;

	origin.x = eye.x;
	origin.y = eye.y;
	origin.z = eye.z;
	normal_plane.x = plane->x_normal;
	normal_plane.y = plane->y_normal;
	normal_plane.z = plane->z_normal;
	point_plane.x = plane->x;
	point_plane.y = plane->y;
	point_plane.z = plane->z;
	rest_point_orig = ft_rest_vect(point_plane, origin);
	return (ft_dot_product_vect(normal_plane, rest_point_orig));
}

double	ft_check_rf_plane(t_plane *plane, t_ray *ray)
{
	t_vector3d	normal_plane;
	double		ret_b;
	double		t;

	normal_plane.x = plane->x_normal;
	normal_plane.y = plane->y_normal;
	normal_plane.z = plane->z_normal;
	ret_b = ft_dot_product_vect(normal_plane, ray->direction);
	if (ret_b == 0)
		return (0);
	t = ft_a_value(ray->origin, plane) / ret_b;
	if (t < KEPSILONPL)
		return (0);
	return (t);
}
