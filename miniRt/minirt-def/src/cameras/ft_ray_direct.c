/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_direct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:14:55 by irifarac          #+#    #+#             */
/*   Updated: 2023/04/07 13:19:10 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cameras.h"

static t_vector3d	ft_normalize(t_vector3d vector)
{
	double		magnitude;
	t_vector3d	ret;

	magnitude = sqrt(vector.x * vector.x + vector.y * vector.y
			+ vector.z * vector.z);
	ret.x = vector.x / magnitude;
	ret.y = vector.y / magnitude;
	ret.z = vector.z / magnitude;
	return (ret);
}

t_vector3d	ft_ray_direction(t_cameras *camera, t_point2d points)
{
	t_vector3d	dir_a;
	t_vector3d	dir_b;
	t_vector3d	dir_c;
	t_vector3d	dir_ab;
	t_vector3d	dir_zc;

	dir_a = ft_product_vect_scalar(camera->right, points.x);
	dir_b = ft_product_vect_scalar(camera->up, points.y);
	dir_c = ft_product_vect_scalar(camera->forward, camera->d);
	dir_ab = ft_sum_vect(dir_a, dir_b);
	dir_zc = ft_rest_vect(dir_ab, dir_c);
	dir_zc = ft_normalize(dir_zc);
	return (dir_zc);
}
