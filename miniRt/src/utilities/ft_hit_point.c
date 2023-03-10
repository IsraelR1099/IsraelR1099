/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hit_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:11:16 by irifarac          #+#    #+#             */
/*   Updated: 2023/03/10 12:30:06 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shaderec.h"

t_point3d	ft_hit_point(t_ray *ray, double t)
{
	t_vector3d	b;
	t_vector3d	sum;
	t_vector3d	origin;
	t_point3d	ret;

	origin.x = ray->origin.x;
	origin.y = ray->origin.y;
	origin.z = ray->origin.z;
	b = ft_product_vect_scalar(ray->direction, t);
	sum = ft_sum_vect(origin, b);
	ret.x = sum.x;
	ret.y = sum.y;
	ret.z = sum.z;
	return (ret);
}
