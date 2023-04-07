/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_samplers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 09:40:23 by irifarac          #+#    #+#             */
/*   Updated: 2023/04/07 14:07:56 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "samplers.h"

size_t	ft_samplers(t_world *world, t_ray *ray, double c, double r)
{
	int			p;
	int			q;
	int			num_samples;
	t_rgb		colour;
	t_point2d	points;

	p = 0;
	num_samples = (int)sqrt(world->vp.num_samples);
	world->vp.color.r = 0;
	world->vp.color.g = 0;
	world->vp.color.b = 0;
	while (p < num_samples)
	{
		q = 0;
		while (q < num_samples)
		{
			points.x = 1 * (c - 0.5 * HRES + (q + 0.5) / num_samples);
			points.y = 1 * (r - 0.5 * VRES + (p + 0.5) / num_samples);
			ray->direction = ft_ray_direction(world->camera, points);
			colour = ft_trace_ray(world, ray);
			world->vp.color.r += colour.r;
			world->vp.color.g += colour.g;
			world->vp.color.b += colour.b;
			q++;
		}
		p++;
	}
	world->vp.color.r *= 255;
	world->vp.color.g *= 255;
	world->vp.color.b *= 255;
	world->vp.color.r /= num_samples;
	world->vp.color.g /= num_samples;
	world->vp.color.b /= num_samples;
	return ((int)world->vp.color.r << 16 | (int)world->vp.color.g << 8 | (int)world->vp.color.b);
}
