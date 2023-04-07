/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_globaltrace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:22:23 by irifarac          #+#    #+#             */
/*   Updated: 2023/04/07 14:08:43 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"

t_rgb	ft_trace_ray(t_world *world, t_ray *ray)
{
	t_shaderec	shade;
	t_rgb		colour;
	t_alight	*alight;
	t_matte		matte;

	alight = (t_alight *)ft_find_amb(world->amb, A);
	colour.r = 0;
	colour.g = 0;
	colour.b = 0;
	shade.hit_object = false;
	shade.world = world;
	shade.ray = *ray;
	shade.colour = colour;
	shade.t = K_HUGE_VALUE;
	shade.ka = alight->ratio;
	ray->origin = world->camera->eye;
	ft_hit_objects(world->obj, world, ray, &shade);
	if (shade.hit_object)
	{
		shade.ray = *ray;
		matte.ft_shade = &ft_shade_matte;
		colour = matte.ft_shade(world, &shade);
		return (colour);
	}
	return (colour);
}
