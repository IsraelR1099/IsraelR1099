/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:58:41 by irifarac          #+#    #+#             */
/*   Updated: 2023/04/07 13:02:30 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brdf.h"

t_rgb	ft_calc_color(t_shaderec *shade, t_rgb point_light, double r_wo)
{
	t_rgb	ret;
	double	k_d;

	k_d = 0.6;
	if ((k_d + shade->kd) > 1)
		k_d = 1;
	ret = ft_rgb_scalar_product(point_light, k_d * pow(r_wo, 25));
	ret = ft_rgb_scalar_product(ret, k_d);
	return (ret);
}

t_vector3d	ft_product(t_shaderec *shade, double dotwi)
{
	t_vector3d	normal_hit;
	t_vector3d	product;

	normal_hit.x = shade->normal_hit.x;
	normal_hit.y = shade->normal_hit.y;
	normal_hit.z = shade->normal_hit.z;
	product = ft_product_vect_scalar(normal_hit, 2 * dotwi);
	return (product);
}
