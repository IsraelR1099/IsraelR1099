/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_brdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:20:22 by irifarac          #+#    #+#             */
/*   Updated: 2023/05/08 11:04:45 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brdf.h"

t_rgb	ft_brdf(t_rgb lights[2], t_shaderec *shade, t_vector3d dir[2],
double dotwi)
{
	t_rgb	f;
	t_rgb	light;
	t_rgb	tmp_color;
	t_rgb	product;

	tmp_color.r = lights[0].r;
	tmp_color.g = lights[0].g;
	tmp_color.b = lights[0].b;
	f = ft_f_phong(shade, dir, lights[1], dotwi);
	light = ft_rgb_scalar_product(lights[1], shade->kd);
	product = ft_rgb_product_vect(f, light);
	tmp_color = product;
	lights[0].r = tmp_color.r;
	lights[0].g = tmp_color.g;
	lights[0].b = tmp_color.b;
	return (lights[0]);
}
