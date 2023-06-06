/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:18:04 by irifarac          #+#    #+#             */
/*   Updated: 2023/05/17 12:44:56 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "materials.h"

t_vector3d	ft_dir_wo(t_shaderec *shade)
{
	t_vector3d	dir_wo;

	dir_wo = shade->ray.direction;
	dir_wo.x = shade->ray.direction.x * (-1);
	dir_wo.y = shade->ray.direction.y * (-1);
	dir_wo.z = shade->ray.direction.z * (-1);
	return (dir_wo);
}

t_vector3d	ft_normal_vector3d(t_shaderec *shade)
{
	t_vector3d	normal;

	normal.x = shade->normal_hit.x;
	normal.y = shade->normal_hit.y;
	normal.z = shade->normal_hit.z;
	return (normal);
}
