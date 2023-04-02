/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matte.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 09:48:19 by irifarac          #+#    #+#             */
/*   Updated: 2023/03/31 13:56:58 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "materials.h"

static t_rgb	ft_set_ambient(t_world *world)
{
	t_lambertian	ambient;
	t_rgb			ambient_color;
	t_alight		*alight;

	alight = (t_alight *)ft_find_amb(world->amb, A);
	ambient.kd = alight->ratio;
	ambient_color.r = alight->r;
	ambient_color.g = alight->g;
	ambient_color.b = alight->b;
	ambient_color = ft_rgb_scalar_product(ambient_color, ambient.kd);
	return (ambient_color);
}

void	ft_check(t_shaderec *shade, t_vector3d dir[2], t_rgb *light_color,
t_light *light)
{
	double		dotwi;
	bool		in_shadow;
	t_ray		shadow_ray;
	t_vector3d	normal;

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
		in_shadow = ft_in_shadow(shadow_ray, shade, light);
		if (!in_shadow)
			ft_brdf(light_color, shade, dir, dotwi);
		else
		{
			light_color->r = 0;
			light_color->g = 0;
			light_color->b = 0;
		}
	}
}

t_rgb	ft_shade(t_world *world, t_shaderec *shade)
{
//	t_vector3d	dir_wo;
//	t_vector3d	dir_wi;
	t_vector3d	dir[2];
	t_rgb		light_color;
	t_light		**tmp;
	int			i;

	//printf("shade colour r %f, g %f, b %f y type %d\n", shade->colour.r,
//	shade->colour.g, shade->colour.b, shade->type);
	tmp = world->lights;
	dir[0] = shade->ray.direction; //dir_wo
	light_color = ft_set_ambient(world);
//	printf("light_color r %f, g %f, b %f\n", light_color.r, light_color.g,
//	light_color.b);
	i = 0;
	while (tmp[i])
	{
		shade->kd = tmp[i]->ratio;
		dir[1] = ft_get_dir(tmp[i], shade); //direction of the lights vector3d
//		dir_wi
		ft_check(shade, dir, &light_color, tmp[i]);
		i++;
	}
	return (light_color);
}
