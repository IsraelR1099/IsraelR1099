/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shade_reflective.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:46:56 by irifarac          #+#    #+#             */
/*   Updated: 2023/05/15 11:37:45 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "materials.h"

//Shoot another ray from the hit point to the direction of wi (reflected)
//L (phong trace) + fr * new_trace * dotnwi
t_rgb	ft_shade_reflective(t_world *world, t_shaderec *shade)
{
	t_rgb		array_rgb[4];
	t_vector3d	wo;
	t_vector3d	wi;
	t_ray		reflective_ray;
	double		dotnwi;

	wo.x = shade->ray.direction.x * (-1);
	wo.y = shade->ray.direction.y * (-1);
	wo.z = shade->ray.direction.z * (-1);
	array_rgb[0] = ft_shade_phong(world, shade);
	array_rgb[1] = ft_reflective_f(shade, wo, &wi);
	reflective_ray.origin = shade->hit_point;
	reflective_ray.direction = wi;
	array_rgb[2] = ft_trace_reflective(world, &reflective_ray);
	array_rgb[3] = ft_rgb_product_vect(array_rgb[1], array_rgb[2]);
	dotnwi = ft_dot_product_vect(ft_normal_vector3d(shade), wi);
	array_rgb[3] = ft_rgb_scalar_product(array_rgb[3], dotnwi);
	array_rgb[0] = ft_rgb_sum(array_rgb[0], array_rgb[3]);
	if (array_rgb[0].r > 1 || array_rgb[0].g > 1 || array_rgb[0].b > 1)
		array_rgb[0] = ft_max_to_one(array_rgb[0]);
	return (array_rgb[0]);
}

/*t_rgb	ft_shade_reflective(t_world *world, t_shaderec *shade)
{
	t_rgb		l;
	t_rgb		fr;
	t_rgb		sample_f;
	t_rgb		new_trace;
	t_vector3d	wo;
	t_vector3d	wi;
	t_ray		reflective_ray;
	double		dotnwi;

	wo.x = shade->ray.direction.x * (-1);
	wo.y = shade->ray.direction.y * (-1);
	wo.z = shade->ray.direction.z * (-1);
//	l = ft_shade_phong(world, shade);
//	sample_f = ft_reflective_f(shade, wo, &wi);
	reflective_ray.origin = shade->hit_point;
	reflective_ray.direction = wi;
//	new_trace = ft_trace_reflective(world, &reflective_ray);
//	fr = ft_rgb_product_vect(sample_f, new_trace);
	dotnwi = ft_dot_product_vect(ft_normal_vector3d(shade), wi);
	//fr = ft_rgb_scalar_product(fr, dotnwi);
	//l = ft_rgb_sum(l, fr);
	//if (l.r > 1 || l.g > 1 || l.b > 1)
	//	l = ft_max_to_one(l);
	//return (l);
}*/
