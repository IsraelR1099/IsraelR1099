/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_samplers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 09:40:23 by irifarac          #+#    #+#             */
/*   Updated: 2023/03/11 09:36:20 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "samplers.h"

size_t	ft_samplers(t_world *world, t_ray *ray, double x, double y)
{
	int			p;
	int			q;
	int			num_samples;
	t_rgb		colour;
	t_point2d	points;

	p = 0;
	q = 0;
	num_samples = (int)sqrt(25);
	colour.r = 255;
	colour.g = 255;
	colour.b = 255;
//	printf("entro samplers\n");
	while (p < num_samples)
	{
		while (q < num_samples)
		{
			points.x = 1 * (x - 0.5 * HEIGHT + (q + 0.5) / num_samples);
			points.y = 1 * (y - 0.5 * WIDTH + (p + 0.5) / num_samples);
			ray->direction = ft_ray_direction(world->camera, points);
			colour = ft_trace_ray(world, ray);
			q++;
		}
		p++;
	}
//	printf("salgo samplers\n");
	return ((int)colour.r << 16 | (int)colour.g << 8 | (int)colour.b);
}
