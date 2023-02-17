/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersects_sphere.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:05:21 by irifarac          #+#    #+#             */
/*   Updated: 2023/02/15 13:48:53 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

static double	ft_a_value(t_vector ray_dir)
{
	return (ft_dot_product_vect(ray_dir, ray_dir));
}

static double	ft_b_value(t_ambient *amb, t_sphere *sphere, t_vector ray_dir)
{
	t_cam		*cam;
//	t_sphere	*sphere;
	t_vector	sphere_pos;
	t_vector	cam_pos;
	t_vector	res_cam_sphere;

	cam = (t_cam *)ft_find_lst(amb, C);
	cam_pos.x = cam->x;
	cam_pos.y = cam->y;
	cam_pos.z = cam->z;
//	sphere = (t_sphere *)ft_find_lst_obj(obj, sp);
	sphere_pos.x = sphere->x;
	sphere_pos.y = sphere->y;
	sphere_pos.z = sphere->z;
	res_cam_sphere = ft_rest_vect(cam_pos, sphere_pos);
	return (2 * ft_dot_product_vect(ray_dir, res_cam_sphere));
}

static double	ft_c_value(t_ambient *amb, t_sphere *sphere)
{
	t_vector	res_cam_sph;
	t_vector	cam_pos;
	t_vector	sphere_pos;
	t_cam		*cam;
//	t_sphere	*sphere;

	cam = (t_cam *)ft_find_lst(amb, C);
	cam_pos.x = cam->x;
	cam_pos.y = cam->y;
	cam_pos.z = cam->z;
//	sphere = (t_sphere *)ft_find_lst_obj(obj, sp);
	sphere_pos.x = sphere->x;
	sphere_pos.y = sphere->y;
	sphere_pos.z = sphere->z;
	res_cam_sph = ft_rest_vect(cam_pos, sphere_pos);
	return (ft_dot_product_vect(res_cam_sph, res_cam_sph) - (sphere->diameter / 2) * (sphere->diameter / 2));
}

static double	ft_calc_t(double scalar_a, double scalar_b, double scalar_c)
{
	double	ret;
	double	ret_positive;
	double	ret_negative;

	ret = scalar_b * scalar_b - (4 * scalar_a * scalar_c);
	ret_positive = -scalar_b + sqrt(ret) / 2 * scalar_a;
	ret_negative = -scalar_b - sqrt(ret) / 2 * scalar_a;
	if (ret_positive == ret_negative)
		return (0);
	return (ret_negative);
}

double	ft_distance_sphere(t_ambient *amb, t_sphere *sphere, t_vector ray_dir)
{
	double		scalar_a;
	double		scalar_b;
	double		scalar_c;
	double		ret;
	double		calc_t;

	if (!sphere)
		return (0);
	scalar_a = ft_a_value(ray_dir);
//	printf("dentro de distance x %f, y %f, z %f\n", sphere->x, sphere->y, sphere->z);
	scalar_b = ft_b_value(amb, sphere, ray_dir);
	scalar_c = ft_c_value(amb, sphere);
	ret = scalar_b * scalar_b - (4 * scalar_a * scalar_c);
//	printf("a %f, b %f, c %f, ret %f\n", scalar_a, scalar_b, scalar_c, ret);
	if (ret < 0)
		return (0);
	calc_t = ft_calc_t(scalar_a, scalar_b, scalar_c);
	if (calc_t < 0)
		calc_t *= -1;
	return (calc_t);
}
