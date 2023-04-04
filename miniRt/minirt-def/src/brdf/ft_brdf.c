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
//cd is the diffuse color of the material

t_rgb	ft_f_diffuse(t_shaderec *shade, t_rgb material_color) //f function kd * cd * invPI
{
	t_rgb	material;
	t_rgb	ret;
	double	kd;

	material.r = material_color.r / 255;
	material.g = material_color.g / 255;
	material.b = material_color.b / 255;
	kd = shade->kd;
	kd = 0.50;
	material = ft_rgb_scalar_product(material, kd);
	ret = ft_rgb_scalar_product(material, invPI);
	return (ret);
}

t_rgb	ft_f_specular(t_shaderec *shade, t_vector3d dir[2], t_rgb point_light, double dotwi)
{
	t_vector3d	product;
	t_vector3d	negative_wi;
	t_vector3d	normal_hit;
	t_vector3d	r;
	double		r_wo;
	t_rgb		color;

	color.r = 0;
	color.g = 0;
	color.b = 0;
	negative_wi.x = (-1) * dir[1].x;
	negative_wi.y = (-1) * dir[1].y;
	negative_wi.z = (-1) * dir[1].z;
	normal_hit.x = shade->normal_hit.x;
	normal_hit.y = shade->normal_hit.y;
	normal_hit.z = shade->normal_hit.z;
	product = ft_product_vect_scalar(normal_hit, 2.0 * dotwi);
	r = ft_sum_vect(negative_wi, product);
	r_wo = ft_dot_product_vect(r, dir[0]);
	if (r_wo > 0.00)
	{
		color.r = point_light.r / 255;
		color.g = point_light.g / 255;
		color.b = point_light.b / 255;
		color = ft_rgb_scalar_product(color, 0.75 * pow(r_wo, 5));
		/*printf("dir es x %f, y %f, z %f\n", dir[1].x, dir[1].y, dir[1].z);
		printf("negative es x %f, y %f, z %f\n", negative_wi.x, negative_wi.y,
		negative_wi.z);
		printf("color es r %f, g %f, b %f\n", color.r, color.g, color.b);
		printf("dot es %f y r_wo %f\n", 0.75 * pow(r_wo, 1), r_wo);*/
	}
	return (color);
}

t_rgb	ft_rho(t_shaderec *shade, t_rgb color) // reflectance or albedo function kd * cd
{
	t_vector3d	first;
	t_rgb		ret;
	double		kd;

	first.x = color.r;
	first.y = color.g;
	first.z = color.b;
	kd = shade->kd;
	kd = 0.50;
	first = ft_product_vect_scalar(first, kd);
	ret.r = first.x;
	ret.g = first.y;
	ret.b = first.z;
	return (ret);
}

t_rgb	ft_f(t_shaderec *shade, t_vector3d dir[2],t_rgb point_light, double dotwi)
{
	t_rgb	f;
	t_rgb	f_diffuse;
	t_rgb	f_specular;
	t_rgb	sum_diff_spec;

	f_diffuse = ft_f_diffuse(shade, shade->colour);
	f_specular = ft_f_specular(shade, dir, point_light, dotwi);
	sum_diff_spec = ft_rgb_sum(f_diffuse, f_specular);
	f = ft_rgb_scalar_product(sum_diff_spec, dotwi);
	return (f);
}

t_rgb	ft_brdf(t_rgb lights[2], t_shaderec *shade, t_vector3d dir[2], double dotwi)
{
	t_rgb	f;
	t_rgb	light;
	t_rgb	tmp_color;
	t_rgb	product;

	tmp_color.r = lights[0].r / 255;
	tmp_color.g = lights[0].g / 255;
	tmp_color.b = lights[0].b / 255;
	f = ft_f(shade, dir, lights[1], dotwi);
	light = ft_rgb_scalar_product(lights[1], shade->kd);
	product = ft_rgb_product_vect(f, light);
	tmp_color = product;
	lights[0].r = tmp_color.r * 255;
	lights[0].g = tmp_color.g * 255;
	lights[0].b = tmp_color.b * 255;
	return (lights[0]);
}
/*void	ft_brdf(t_rgb *total_light, t_shaderec *shade, t_rgb point_light, double dotwi)
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
	color = ft_rgb_scalar_product(color, dotwi);
	color = ft_rgb_product_vect(color, point_light);
	total_light->r = color.r * 255;
	total_light->g = color.g * 255;
	total_light->b = color.b * 255;
}*/
