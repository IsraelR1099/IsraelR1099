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
