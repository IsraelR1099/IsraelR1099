/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_to_world.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 09:55:42 by irifarac          #+#    #+#             */
/*   Updated: 2023/02/22 11:32:05 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

void	ft_pixel_to_world(t_vector *ray_dir, int x, int y)
{
/*	double	ndc_x;
	double	ndc_y;
	double	aspect_ratio;

	aspect_ratio = WIDTH / HEIGHT;
	ndc_x = (x + 0.5) / WIDTH;
	ndc_y = (y + 0.5) / HEIGHT;
	ray_dir->x = (2 * ndc_x - 1) * aspect_ratio * tan(80 /(2 * PI / 180));
	ray_dir->y = 1 - 2 * ndc_y * tan(80/(2 * PI / 180));
	ray_dir->z = -1;*/
	ray_dir->x = x - (WIDTH / 2);
	int y2 = 0;
	ray_dir->y = y2 - (HEIGHT / 2);
	ray_dir->z = -1;
	printf("x %f, y %f, z %f\n", ray_dir->x, ray_dir->y, ray_dir->z);
	(void)y;
}
