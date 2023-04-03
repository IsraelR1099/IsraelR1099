/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matte.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 09:48:19 by irifarac          #+#    #+#             */
/*   Updated: 2023/04/03 13:56:59 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "materials.h"

static t_rgb	ft_set_ambient(t_world *world)
{
	t_lambertian	ambient;
	t_rgb			ambient_color;
	t_alight		*alight;
	t_rgb			f;
	t_rgb			rho;

	alight = (t_alight *)ft_find_amb(world->amb, A);
	ambient.kd = alight->ratio;
	ambient_color.r = alight->r;
	ambient_color.g = alight->g;
	ambient_color.b = alight->b;
	rho = ft_rgb_scalar_product(ambient_color, ambient.kd);
	f = ft_rgb_scalar_product(ambient_color, ambient.kd * invPI);
	ambient_color = ft_rgb_product_vect(rho, f);
	return (ambient_color);
}

static t_rgb	ft_check(t_shaderec *shade, t_vector3d dir[2], t_rgb total_light,
t_light *light)
{
	double		dotwi;
	bool		in_shadow;
	t_ray		shadow_ray;
	t_vector3d	normal;
	t_rgb		point_light;

	normal.x = shade->normal_hit.x;
	normal.y = shade->normal_hit.y;
	normal.z = shade->normal_hit.z;
	dotwi = ft_dot_product_vect(normal, dir[1]); //cosine of the angle between
//	the surface normal and the light direction
/*	if (shade->type == sp)
	{
		printf("normal es x %f, y %f, z %f\n", normal.x, normal.y, normal.z);
		printf("direction light x %f, y %f, z %f\n", dir[1].x, dir[1].y,
		dir[1].z);
		printf("hit point es x %f, y %f, z %f\n", shade->hit_point.x,
		shade->hit_point.y, shade->hit_point.z);
		printf("colour r %f, g %f, b %f\n", shade->colour.r, shade->colour.g,
		shade->colour.b);
		printf("dotwi es %f\n", dotwi);
		exit(1);
	}*/
	if (dotwi > 0.0)
	{
		in_shadow = false;
		shadow_ray.origin = shade->hit_point;
		shadow_ray.direction = dir[1];
		point_light.r = light->r / 255;
		point_light.g = light->g / 255;
		point_light.b = light->b / 255;
		in_shadow = ft_in_shadow(shadow_ray, shade, light);
		if (!in_shadow)
			ft_brdf(&total_light, shade, point_light, dotwi);
	}
	return (total_light);
}

t_rgb	ft_shade(t_world *world, t_shaderec *shade)
{
	t_vector3d	dir[2];
	t_rgb		total_light;
	t_rgb		tmp_color;
	t_light		**tmp;
	int			i;

	//printf("shade colour r %f, g %f, b %f y type %d\n", shade->colour.r,
//	shade->colour.g, shade->colour.b, shade->type);
	tmp = world->lights;
	dir[0] = shade->ray.direction; //dir_wo
	total_light = ft_set_ambient(world);
	tmp_color = total_light;
//	printf("light_color r %f, g %f, b %f\n", light_color.r, light_color.g,
//	light_color.b);
	i = 0;
	while (tmp[i])
	{
		shade->kd = tmp[i]->ratio;
		dir[1] = ft_get_dir(tmp[i], shade); //direction of the lights vector3d
//		dir_wi
		total_light = ft_check(shade, dir, total_light, tmp[i]);
		total_light = ft_rgb_sum(total_light, tmp_color);
		tmp_color = total_light;
		i++;
	}
	if (total_light.r > 255 || total_light.g > 255 || total_light.b > 255)
		total_light = ft_clamp_color(total_light);
	return (total_light);
}
