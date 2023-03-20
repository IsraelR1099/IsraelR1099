/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_globaltrace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:22:23 by irifarac          #+#    #+#             */
/*   Updated: 2023/03/20 13:23:33 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"

t_rgb	ft_trace_ray(t_world *world, t_ray *ray)
{
	t_shaderec	shade;
	t_rgb		colour;

	colour.r = 0;
	colour.g = 0;
	colour.b = 0;
	shade.hit_object = false;
	shade.world = world;
	shade.ray = *ray;
	shade.colour = colour;
	shade.t = k_huge_value;
	ray->origin = world->camera->eye;
	ft_hit_objects(world->obj, world, ray, &shade);
	if (shade.hit_object)
	{
		shade.ray = *ray;
		return (shade.colour);
	}
	return (colour);
}
