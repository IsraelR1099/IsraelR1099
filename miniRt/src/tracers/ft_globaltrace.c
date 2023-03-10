/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_globaltrace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:22:23 by irifarac          #+#    #+#             */
/*   Updated: 2023/03/10 13:45:12 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"

t_rgb	ft_trace_ray(t_world *world, t_ray *ray)
{
	t_shaderec	shade;
	t_rgb		colour;

	colour.r = 255;
	colour.g = 255;
	colour.b = 255;
	//printf("entro trace ray\n");
	ray->origin = world->camera->eye;
	shade = ft_hit_objects(world->obj, world, ray);
	if (shade.hit_object)
	{
		shade.ray = *ray;
		return (shade.colour);
	}
//	printf("salgo trace ray\n");
	return (colour);
}
