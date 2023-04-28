/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glossy_material.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 09:53:21 by irifarac          #+#    #+#             */
/*   Updated: 2023/04/28 13:05:35 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brdf.h"

t_rgb	ft_f_phong(t_shaderec *shade, t_vector3d dir[2], t_rgb point_light,
double dotwi)
{
	t_rgb	f;
	t_rgb	f_diffuse;
	t_rgb	f_specular;
	t_rgb	sum_diff_spec;

	f_diffuse = ft_f_diffuse(shade, shade->colour, dotwi);
	//f_diffuse = ft_f_diffuse(shade, point_light, dotwi);
	f_specular = ft_f_specular(shade, dir, point_light, dotwi);
	sum_diff_spec = ft_rgb_sum(f_diffuse, f_specular);
	f = sum_diff_spec;
//	f = ft_rgb_scalar_product(sum_diff_spec, dotwi);
	return (f);
}
