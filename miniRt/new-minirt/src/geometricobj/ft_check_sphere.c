/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sphere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:18:57 by irifarac          #+#    #+#             */
/*   Updated: 2023/03/31 12:17:18 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometricobj.h"

static double	ft_a_value(t_ray *ray)
{
	return (ft_dot_product_vect(ray->direction, ray->direction));
}

static double	ft_b_value(t_ray *ray, t_sphere *sphere, t_point3d eye)
{
	t_vector3d	origin;
	t_vector3d	sph_pos;
	t_vector3d	rest_cam_sphere;

	origin.x = eye.x;
	origin.y = eye.y;
	origin.z = eye.z;
	sph_pos.x = sphere->x;
	sph_pos.y = sphere->y;
	sph_pos.z = sphere->z;
	rest_cam_sphere = ft_rest_vect(origin, sph_pos);
	return (2 * ft_dot_product_vect(ray->direction, rest_cam_sphere));
}

static double	ft_c_value(t_sphere *sphere, t_point3d eye)
{
	t_vector3d	origin;
	t_vector3d	sph_pos;
	t_vector3d	rest_cam_sphere;
	double		radio;
	double		r_2;

	origin.x = eye.x;
	origin.y = eye.y;
	origin.z = eye.z;
	sph_pos.x = sphere->x;
	sph_pos.y = sphere->y;
	sph_pos.z = sphere->z;
	rest_cam_sphere = ft_rest_vect(origin, sph_pos);
	radio = sphere->diameter / 2;
	r_2 = radio * radio;
	return (ft_dot_product_vect(rest_cam_sphere, rest_cam_sphere) - r_2);
}

static double	ft_calc_t(double scalar_a, double scalar_b, double scalar_c)
{
	double	ret;
	double	ret_positive;
	double	ret_negative;

	ret = scalar_b * scalar_b - (4 * scalar_a * scalar_c);
	ret_positive = (-1) * scalar_b + sqrt(ret) / 2 * scalar_a;
	ret_negative = (-1) * scalar_b - sqrt(ret) / 2 * scalar_a;
	if (ret_positive == ret_negative)
		return (0);
	if (ret_negative > kEpsilon)
		return (ret_negative);
	else if (ret_positive > kEpsilon)
		return (ret_positive);
	return (0);
}

double	ft_check_sphere(t_cameras *camera, t_sphere *sphere, t_ray *ray)
{
	double	scalar_a;
	double	scalar_b;
	double	scalar_c;
	double	ret;
	double	calc_t;

	if (!sphere)
		return (0);
//	printf("ray x %f, y %f, z %f\n", ray->direction.x, ray->direction.y, ray->direction.z);
	scalar_a = ft_a_value(ray);
	scalar_b = ft_b_value(ray, sphere, camera->eye);
	scalar_c = ft_c_value(sphere, camera->eye);
	ret = scalar_b * scalar_b - ( 4 * scalar_a * scalar_c);
	if (ret < 0)
		return (0);
	calc_t = ft_calc_t(scalar_a, scalar_b, scalar_c);
	/*if (calc_t < 0)
		calc_t *= -1;*/
	//printf("scalar_a %f, scalar b %f, scalar c %f\n", scalar_a, scalar_b, scalar_c);
	//printf("calc t es %f\n", calc_t);
	return (calc_t);
}
