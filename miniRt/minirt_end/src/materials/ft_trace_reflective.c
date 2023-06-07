/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trace_reflective.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:31:15 by irifarac          #+#    #+#             */
/*   Updated: 2023/05/15 11:37:21 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "materials.h"

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

t_rgb	ft_trace_reflective(t_world *world, t_ray *ray)
{
	t_shaderec	shade;
	t_rgb		colour;

	colour.r = 0;
	colour.g = 0;
	colour.b = 0;
	ft_shade_init(world, &shade, ray, colour);
	ft_hit_rf_objects(world->obj, ray, &shade);
	if (shade.hit_object)
	{
		shade.ray = *ray;
		colour = ft_shade_phong(world, &shade);
		return (colour);
	}
	return (colour);
}
