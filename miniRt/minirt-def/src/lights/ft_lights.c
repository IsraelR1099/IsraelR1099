/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lights.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 09:56:51 by irifarac          #+#    #+#             */
/*   Updated: 2023/04/03 12:05:04 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lights.h"

bool	ft_in_shadow(t_ray shadow_ray, t_shaderec *shade, t_light *light)
{
	double		distance;
	t_vector3d	l_coord;
	t_vector3d	rest;

	//printf("colour in shadow r %f, g %f, b %f, type %d\n", shade->colour.r,
	//shade->colour.g, shade->colour.b, shade->type);
	l_coord.x = light->x;
	l_coord.y = light->y;
	l_coord.z = light->z;
	rest.x = l_coord.x - shadow_ray.origin.x;
	rest.y = l_coord.y - shadow_ray.origin.y;
	rest.z = l_coord.z - shadow_ray.origin.z;
	distance = sqrt(rest.x * rest.x + rest.y * rest.y
	+ rest.z * rest.z); //distance between light origin and hit point
	if (ft_hit_shadow(shadow_ray, shade->world, distance))
		return (true);
	return (false);
}

//inverse square law applied to the brightness of each light (kd)

/*static void	ft_attenuation_light(t_shaderec *shade, double magnitude)
{
	double	constant;
	double	linear;
	double	quadratic;
	double	attenuation;

	constant = 1;
	linear = 0.1;
	quadratic = 0.01;
	attenuation = 1 / constant + linear * magnitude + quadratic * magnitude * magnitude;
	shade->kd = shade->kd * attenuation;
	if (shade->hit_object == true)
	{
		printf("attenuation %f\n", attenuation);
		exit(1);
	}
}*/

t_vector3d	ft_get_dir(t_light *light, t_shaderec *shade)
{
	t_vector3d	rest;
	t_vector3d	location;
	t_vector3d	hit_point;
	double		magnitude;

	location.x = light->x;
	location.y = light->y;
	location.z = light->z;
	hit_point.x = shade->hit_point.x;
	hit_point.y = shade->hit_point.y;
	hit_point.z = shade->hit_point.z;
	rest = ft_rest_vect(location, hit_point);
	magnitude = sqrt(rest.x * rest.x + rest.y * rest.y
	+ rest.z * rest.z);
	rest.x /= magnitude;
	rest.y /= magnitude;
	rest.z /= magnitude;
//	ft_attenuation_light(shade, magnitude);
	return (rest);
}
