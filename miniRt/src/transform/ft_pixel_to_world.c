/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_to_world.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 09:55:42 by irifarac          #+#    #+#             */
/*   Updated: 2023/02/24 13:54:17 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

static t_vector	ft_make_dir(t_4dvector *look_at, double x, double y)
{
	t_vector	right_x;
	t_vector	up_y;
	t_vector	direction;
	t_vector	tmp;
	double		len;

	tmp.x = look_at[0].x;
	tmp.y = look_at[0].y;
	tmp.z = look_at[0].z;
	right_x = ft_product_vect_scalar(tmp, x);
	tmp.x = look_at[1].x;
	tmp.y = look_at[1].y;
	tmp.z = look_at[1].z;
	up_y = ft_product_vect_scalar(tmp, y);
	tmp.x = look_at[2].x;
	tmp.y = look_at[2].y;
	tmp.z = look_at[2].z;
	direction = ft_sum_vect(tmp, right_x);
	direction = ft_sum_vect(direction, up_y);
	len = sqrt(direction.x * direction.x + direction.y * direction.y + direction.z * direction.z);
	direction.x /= len;
	direction.y /= len;
	return (direction);
}

void	ft_makeray(t_vector *ray_dir, t_4dvector *look_at, int x, int y)
{
/*	double	ndc_x;
	double	ndc_y;
	double	aspect_ratio;

	aspect_ratio = WIDTH / HEIGHT;
	ndc_x = (x + 0.5) / WIDTH;
	ndc_y = (y + 0.5) / HEIGHT;
	ray_dir->x = (2 * ndc_x - 1) * aspect_ratio * tan(80 /(2 * PI / 180));
	ray_dir->y = 1 - 2 * ndc_y * tan(80/(2 * PI / 180));
	ray_dir->z = -1;
	ray_dir->x = x - (WIDTH / 2);
	int y2 = 0;
	ray_dir->y = y2 - (HEIGHT / 2);
	ray_dir->z = -1;
//	printf("x %f, y %f, z %f\n", ray_dir->x, ray_dir->y, ray_dir->z);
	(void)y;
	(void)look_at;*/
	double	u;
	double	v;
	double	w;
	double	h;
	t_vector	direction;

	h = tan(80);
	w = h * WIDTH / HEIGHT;
	u = (2 * x / WIDTH) - 1;
	v = (-2 * y / HEIGHT) + 1;
//	printf("u es %f, v %f\n", u, v);
	ray_dir->z = -1;
	direction = ft_make_dir(look_at, u * w, v * h);
	ray_dir->x = direction.x;
	ray_dir->y = direction.y;
//	printf("x %f, y %f, z %f\n", ray_dir->x, ray_dir->y, ray_dir->z);
}
