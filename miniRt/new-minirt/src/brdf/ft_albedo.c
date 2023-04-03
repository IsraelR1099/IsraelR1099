/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_albedo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:20:22 by irifarac          #+#    #+#             */
/*   Updated: 2023/04/03 13:56:57 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brdf.h"

//Diffuse reflection coefficient
//kd is diffuse reflection coefficient
//cd is the diffuse color

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

t_rgb	ft_rho(t_shaderec *shade, t_rgb color) // reflectance or albedo function kd * cd
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

/*void	ft_brdf(t_rgb *total_light, t_shaderec *shade, t_rgb point_light, double dotwi)
{
	t_rgb	color;
	t_rgb	f;
	t_rgb	rho;
	t_rgb	tmp;
	t_rgb	material;

	if (shade->hit_object == true)
	{
		color.r = shade->colour.r / 255;
		color.g = shade->colour.g / 255;
		color.b = shade->colour.b / 255;
		color = ft_rgb_product_vect(*total_light, shade->colour);
		color.r /= 255;
		color.g /= 255;
		color.b /= 255;
	}
	color.r = total_light->r / 255;
	color.g = total_light->g / 255;
	color.b = total_light->b / 255;
	f = ft_f(shade, color);
	tmp = ft_rgb_scalar_product(f, dotwi);
	rho = ft_rho(shade, color);
	color = ft_rgb_sum(rho, tmp);
	color = ft_rgb_product_vect(color, point_light);
	if (shade->hit_object == true)
	{
		material.r = shade->colour.r / 255;
		material.g = shade->colour.g / 255;
		material.b = shade->colour.b / 255;
		color = ft_rgb_product_vect(color, material);
	}
	total_light->r = color.r * 255;
	total_light->g = color.g * 255;
	total_light->b = color.b * 255;
}
*/

void	ft_brdf(t_rgb *total_light, t_shaderec *shade, t_rgb point_light, double dotwi)
{
	t_rgb	color;

	if (shade->hit_object == true)
	{
		color.r = shade->colour.r / 255;
		color.g = shade->colour.g / 255;
		color.b = shade->colour.b / 255;
	}
	else
	{
		color.r = total_light->r / 255;
		color.g = total_light->g / 255;
		color.b = total_light->b / 255;
	}
	color = ft_f(shade, color);
	color =ft_rho(shade, color);
	color = ft_rgb_scalar_product(color, dotwi);
	color = ft_rgb_product_vect(color, point_light);
	total_light->r = color.r * 255;
	total_light->g = color.g * 255;
	total_light->b = color.b * 255;
}
