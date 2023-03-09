/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_globaltrace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:22:23 by irifarac          #+#    #+#             */
/*   Updated: 2023/03/06 14:00:20 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracer.h"

size_t	ft_trace_ray(t_world *world, t_ray ray)
{
	t_shaderec	shade;

	shade = ft_hit_objects(world->obj, ray);
	if (shade.hit_object)
	{
		shade.ray = ray;
		return (colour);
	}
	return (255);
}
