/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_samplers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 09:40:23 by irifarac          #+#    #+#             */
/*   Updated: 2023/03/31 11:42:26 by irifarac         ###   ########.fr       */
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
//			printf("column %f, row %f\n", c, r);
			points.x = 1 * (c - 0.5 * hres + (q + 0.5) / num_samples);
			points.y = 1 * (r - 0.5 * vres + (p + 0.5) / num_samples);
//			printf("ppx %f, ppy %f\n", points.x, points.y);
			ray->direction = ft_ray_direction(world->camera, points);
//			printf("ray dir x %f, y %f, z %f\n", ray->direction.x, ray->direction.y, ray->direction.z);
			colour = ft_trace_ray(world, ray);
			world->vp.color.r += colour.r;
			world->vp.color.g += colour.g;
			world->vp.color.b += colour.b;
//			printf("colour es r %d, g %d, b %d\n", colour.r, colour.g, colour.b);
			q++;
		}
		p++;
	}
	world->vp.color.r /= num_samples;
	world->vp.color.g /= num_samples;
	world->vp.color.b /= num_samples;
	return((int)world->vp.color.r << 16 | (int)world->vp.color.g << 8 | (int)world->vp.color.b);
}
