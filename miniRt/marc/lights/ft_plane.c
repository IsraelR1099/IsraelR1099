/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plane.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:34:07 by irifarac          #+#    #+#             */
/*   Updated: 2023/04/07 13:34:45 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lights.h"

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

double	ft_hit_plane(t_plane *plane, t_ray ray)
{
	t_vector3d	normal_plane;
	double		ret_b;
	double		t;

	normal_plane.x = plane->x_normal;
	normal_plane.y = plane->y_normal;
	normal_plane.z = plane->z_normal;
	ret_b = ft_dot_product_vect(normal_plane, ray.direction);
	if (ret_b == 0)
		return (0);
	t = ft_a_value(ray.origin, plane) / ret_b;
	if (t < KEPSILONPL)
		return (0);
	return (t);
}
