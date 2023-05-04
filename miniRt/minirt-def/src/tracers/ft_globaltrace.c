/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_globaltrace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:22:23 by irifarac          #+#    #+#             */
/*   Updated: 2023/04/28 12:32:19 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"

static void	ft_shade_init(t_world *world, t_shaderec *shade, t_ray *ray, t_rgb
colour)
{
	t_alight	*alight;


	alight = (t_alight *)ft_find_amb(world->amb, A);
	shade->hit_object = false;
	shade->world = world;
	shade->ray = *ray;
	shade->colour = colour;
	shade->t = K_HUGE_VALUE;
	shade->ka = alight->ratio;
	shade->max_bounces = 1;
}

t_rgb	ft_trace_ray(t_world *world, t_ray *ray, int depth)
{
	t_shaderec	shade;
	t_rgb		colour;
	t_matte		matte;

	colour.r = 0;
	colour.g = 0;
	colour.b = 0;
	ft_shade_init(world, &shade, ray, colour);
	if (depth > shade.max_bounces)
		return (colour);
	ray->origin = world->camera->eye;
	ft_hit_objects(world->obj, world, ray, &shade);
	if (shade.hit_object)
	{
		shade.ray = *ray;
		//matte.ft_shade = &ft_shade_phong;
		matte.ft_shade = &ft_shade_reflective;
		colour = matte.ft_shade(world, &shade);
		return (colour);
	}
	return (colour);
}
