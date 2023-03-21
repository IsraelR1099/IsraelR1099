/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_samplers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 09:40:23 by irifarac          #+#    #+#             */
/*   Updated: 2023/03/20 13:23:41 by irifarac         ###   ########.fr       */
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
	num_samples = (int)sqrt(16);
//	printf("entro samplers\n");
	while (p < num_samples)
	{
		q = 0;
		while (q < num_samples)
		{
			points.x = 1 * (c - 0.5 * hres + (q + 0.5) / num_samples);
			points.y = 1 * (r - 0.5 * vres + (p + 0.5) / num_samples);
			//printf("ppx %f, ppy %f\n", points.x, points.y);
			ray->direction = ft_ray_direction(world->camera, points);
		//	printf("ray dir x %f, y %f, z %f\n", ray->direction.x, ray->direction.y, ray->direction.z);
			colour = ft_trace_ray(world, ray);
			q++;
		}
		p++;
	}
/*	if (c == 0)
	{
		printf("ppx %f, ppy %f\n", points.x, points.y);
		printf("ray dir x %f, y %f, z %f\n", ray->direction.x, ray->direction.y, ray->direction.z);
	}
	if (c == 1000)
	{
		printf("---c %f---\n", c);
		printf("ppx %f, ppy %f\n", points.x, points.y);
		printf("ray dir x %f, y %f, z %f\n", ray->direction.x, ray->direction.y, ray->direction.z);
		exit(1);
	}*/
	return (colour.r << 16 | colour.g << 8 | colour.b);
}
