/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_direct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:14:55 by irifarac          #+#    #+#             */
/*   Updated: 2023/03/17 13:59:27 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cameras.h"

t_vector3d	ft_ray_direction(t_cameras *camera, t_point2d points)
{
	t_vector3d	dir_a;
	t_vector3d	dir_b;
	t_vector3d	dir_c;
	t_vector3d	dir_ab;
	t_vector3d	dir_zc;

	printf("point x es %f\n", points.x);
	dir_a = ft_product_vect_scalar(camera->right, points.x);
	dir_b = ft_product_vect_scalar(camera->up, points.y);
	dir_c = ft_product_vect_scalar(camera->forward, 1);
	dir_ab = ft_sum_vect(dir_a, dir_b);
	dir_zc = ft_rest_vect(dir_ab, dir_c);
	printf("ray direction x %f, y %f, z %f\n", dir_zc.x, dir_zc.y, dir_zc.z);
	return (dir_zc);
}
