/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_rho.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 09:46:16 by irifarac          #+#    #+#             */
/*   Updated: 2023/04/07 14:03:46 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brdf.h"

//Diffuse reflection coefficient
//kd is diffuse reflection coefficient
//cd is the diffuse color of the material

//f_diffuse function kd * cd * INVPI

t_rgb	ft_f_diffuse(t_shaderec *shade, t_rgb material_color)
{
	t_rgb	material;
	t_rgb	ret;
	double	kd;

	material.r = material_color.r;
	material.g = material_color.g;
	material.b = material_color.b;
	kd = shade->kd;
	kd = 0.75;
	material = ft_rgb_scalar_product(material, kd);
	ret = ft_rgb_scalar_product(material, INVPI);
	return (ret);
}

t_rgb	ft_f_specular(t_shaderec *shade, t_vector3d dir[2],
t_rgb point_light, double dotwi)
{
	t_vector3d	product;
	t_vector3d	negative_wi;
	t_vector3d	r;
	double		r_wo;
	t_rgb		color;

	color.r = 0;
	color.g = 0;
	color.b = 0;
	negative_wi.x = (-1) * dir[1].x;
	negative_wi.y = (-1) * dir[1].y;
	negative_wi.z = (-1) * dir[1].z;
	product = ft_product(shade, dotwi);
	r = ft_sum_vect(negative_wi, product);
	r_wo = ft_dot_product_vect(r, dir[0]);
	if (r_wo > 0.00)
	{
		color.r = point_light.r;
		color.g = point_light.g;
		color.b = point_light.b;
		color = ft_rgb_scalar_product(color, 0.2 * pow(r_wo, 5));
	}
	return (color);
}

// reflectance or albedo function kd * cd
t_rgb	ft_rho(t_shaderec *shade, t_rgb color)
{
	t_rgb		ret;
	double		kd;

	ret.r = color.r;
	ret.g = color.g;
	ret.b = color.b;
	kd = shade->kd;
	kd = 0.15;
	ret = ft_rgb_scalar_product(ret, kd);
	return (ret);
}
