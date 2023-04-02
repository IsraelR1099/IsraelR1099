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

t_rgb	ft_f(t_shaderec *shade, t_rgb light_color) //f function kd * cd * invPI
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

t_rgb	ft_rho(t_shaderec *shade, t_rgb color)
{
	t_vector3d	first;
	t_rgb		ret;

	first.x = color.r;
	first.y = color.g;
	first.z = color.b;
	first = ft_product_vect_scalar(first, shade->kd);
	ret.r = first.x;
	ret.g = first.y;
	ret.b = first.z;
	return (ret);
}

void	ft_brdf(t_rgb *light_color, t_shaderec *shade, t_vector3d dir[2], double dotwi)
{
	t_rgb	color;
	t_vector3d	tmp;

	/*if (shade->type == sp)
	{
		printf("color sphere r %f, g %f, b %f\n", shade->colour.r,
		shade->colour.g, shade->colour.b);
	}*/
	if (shade->hit_object == true)
	{
		color.r = shade->colour.r / 255;
		color.g = shade->colour.g / 255;
		color.b = shade->colour.b / 255;
	}
	else
	{
		color.r = light_color->r / 255;
		color.g = light_color->g / 255;
		color.b = light_color->b / 255;
	}
	color = ft_f(shade, color);
	color =ft_rho(shade, color);
	tmp.x = color.r;
	tmp.y = color.g;
	tmp.z = color.b;
	tmp = ft_product_vect_scalar(tmp, dotwi);
	color.r = tmp.x;
	color.g = tmp.y;
	color.b = tmp.z;
	light_color->r = color.r * 255;
	light_color->g = color.g * 255;
	light_color->b = color.b * 255;
	(void)dir;
}
