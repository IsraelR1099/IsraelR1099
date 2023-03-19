/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_samplers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 09:40:23 by irifarac          #+#    #+#             */
/*   Updated: 2023/03/17 13:52:52 by irifarac         ###   ########.fr       */
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
	q = 0;
	num_samples = (int)sqrt(16);
	colour.r = 255;
	colour.g = 255;
	colour.b = 255;
//	printf("entro samplers\n");
	while (p < num_samples)
	{
		while (q < num_samples)
		{
			points.x = 1 * (c - 0.5 * HEIGHT + (q + 0.5) / num_samples);
			points.y = 1 * (r - 0.5 * WIDTH + (p + 0.5) / num_samples);
			//printf("ppx %f, ppy %f\n", points.x, points.y);
			ray->direction = ft_ray_direction(world->camera, points);
			//printf("ray dir x %f, y %f, z %f\n", ray->direction.x,
			//ray->direction.y, ray->direction.z);
			colour = ft_trace_ray(world, ray);
			q++;
		}
		p++;
	}
//	printf("salgo samplers\n");
	return ((int)colour.r << 16 | (int)colour.g << 8 | (int)colour.b);
}
