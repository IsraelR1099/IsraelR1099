/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_direct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:14:55 by irifarac          #+#    #+#             */
/*   Updated: 2023/03/20 13:24:13 by irifarac         ###   ########.fr       */
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

	//printf("point x es %f\n", points.x);
	dir_a = ft_product_vect_scalar(camera->right, points.x);
//	printf("dir a es x %f, y %f, z %f\n", dir_a.x, dir_a.y, dir_a.z);
	dir_b = ft_product_vect_scalar(camera->up, points.y);
//	printf("camera up es x %f, y %f, z %f\n", camera->up.x, camera->up.y, camera->up.z);
	//printf("dir b x %f, y %f, z %f\n", dir_b.x, dir_b.y, dir_b.z);
	dir_c = ft_product_vect_scalar(camera->forward, 100);
	dir_ab = ft_sum_vect(dir_a, dir_b);
	//printf("dir ab es x %f, y %f, z %f\n", dir_ab.x, dir_ab.y, dir_ab.z);
	dir_zc = ft_rest_vect(dir_ab, dir_c);
	dir_zc = ft_normalize(dir_zc);
	//printf("normal dir zc x %f, y %f, z %f\n", dir_zc.x, dir_zc.y, dir_zc.z);
	return (dir_zc);
}
