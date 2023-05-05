/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matte.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 09:48:19 by irifarac          #+#    #+#             */
/*   Updated: 2023/05/05 11:03:52 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "materials.h"

static t_rgb	ft_set_ambient(t_world *world, t_shaderec *shade)
{
	t_lambertian	ambient;
	t_rgb			ambient_color;
	t_alight		*alight;
	t_rgb			l;
	t_rgb			rho;

	alight = (t_alight *)ft_find_amb(world->amb, A);
	ambient.kd = alight->ratio; //Lambertian surface
	ambient_color.r = alight->r;
	ambient_color.g = alight->g;
	ambient_color.b = alight->b;
	l = ft_rgb_scalar_product(ambient_color, ambient.kd);
	//rho = ft_rgb_scalar_product(shade->colour, ambient.kd);
	rho = ft_rho(shade, shade->colour);
	//rho = ft_rho(shade, ambient_color);
	ambient_color = ft_rgb_product_vect(rho, l);
	return (ambient_color);
}

static t_rgb	ft_check(t_shaderec *shade, t_vector3d dir[2],
t_rgb total_light, t_light *light)
{
	double		dotwi;
	t_ray		shadow_ray;
	t_vector3d	normal;
	t_rgb		point_light;
	t_rgb		lights[2];

	normal.x = shade->normal_hit.x;
	normal.y = shade->normal_hit.y;
	normal.z = shade->normal_hit.z;
	dotwi = ft_dot_product_vect(normal, dir[1]); //cosine of the angle between
//	the surface normal and the light direction
	if (dotwi > 0.0)
	{
		shade->in_shadow = false;
		shadow_ray.origin = shade->hit_point;
		shadow_ray.direction = dir[1];
		point_light.r = light->r;
		point_light.g = light->g;
		point_light.b = light->b;
		shade->in_shadow = ft_in_shadow(shadow_ray, shade, light);
		if (!shade->in_shadow)
		{
			lights[0] = total_light;
			lights[1] = point_light;
			total_light = ft_brdf(lights, shade, dir, dotwi);
		}
	}
	return (total_light);
}

t_rgb	ft_shade_phong(t_world *world, t_shaderec *shade)
{
	t_vector3d	dir[2];
	t_rgb		total_light;
	t_rgb		tmp_color;
	t_light		**tmp;
	int			i;

	tmp = world->lights;
	dir[0] = shade->ray.direction; //dir_wo
	dir[0].x = (-1) * shade->ray.direction.x;
	dir[0].y = (-1) * shade->ray.direction.y;
	dir[0].z = (-1) * shade->ray.direction.z;
	total_light = ft_set_ambient(world, shade);
	tmp_color = total_light;
	i = 0;
	while (tmp[i])
	{
		shade->kd = tmp[i]->ratio;
		dir[1] = ft_get_dir(tmp[i], shade); //direction of the lights vector3d
//		dir_wi
		total_light = ft_check(shade, dir, total_light, tmp[i]);
		if (total_light.r > 1 || total_light.g > 1 || total_light.b > 1)
			total_light = ft_max_to_one(total_light);
		if (shade->in_shadow == false)
			total_light = ft_rgb_sum(total_light, tmp_color);
		tmp_color = total_light;
		i++;
	}
	if (total_light.r > 1 || total_light.g > 1 || total_light.b > 1)
		total_light = ft_max_to_one(total_light);
	return (total_light);
}
