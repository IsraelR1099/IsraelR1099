/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_albedo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:20:22 by irifarac          #+#    #+#             */
/*   Updated: 2023/03/31 13:57:27 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brdf.h"

//Diffuse reflection coefficient

t_rgb	ft_f(t_shaderec *shade, t_rgb light_color)
{
	t_vector3d	first;
	t_vector3d	second;
	t_rgb		ret;

	first.x = light_color.r;
	first.y = light_color.g;
	first.z = light_color.b;
	first = ft_product_vect_scalar(first, shade->kd);
	second = ft_product_vect_scalar(first, invPI);
	ret.r = second.x;
	ret.g = second.y;
	ret.b = second.z;
	return (ret);
}

void	ft_brdf(t_rgb *light_color, t_shaderec *shade, t_vector3d dir[2], double dotwi)
{
	t_rgb	color;

	//color.r = light_color->r / 255;
//	color.g = light_color->g / 255;
//	color.b = light_color->b / 255;
	color.r = (float)shade->colour.r / 255;
	if (color.r != 1 && color.r != 0)
		printf("colour despues %f\n", color.r);
	color.g = (float)shade->colour.g / 255;
	color.b = (float)shade->colour.b / 255;
	color = ft_f(shade, color);
	light_color->r = color.r * 255;
	light_color->g = color.g * 255;
	light_color->b = color.b * 255;
	(void)dir;
	(void)dotwi;
}
