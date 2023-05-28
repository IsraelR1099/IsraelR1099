/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:18:04 by irifarac          #+#    #+#             */
/*   Updated: 2023/05/17 12:15:33 by irifarac         ###   ########.fr       */
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

double	ft_check_rf_normal(t_cylinder *cyl, t_ray *ray)
{

	t_vector3d	n;
	double		ret;

	n.x = cyl->x_normal;
	n.y = cyl->y_normal;
	n.z = cyl->z_normal;
	ret = 0;
	if (n.x == 0 && n.y == 1 && n.z == 0)
		ret = ft_check_rf_cyly(cyl, ray);
	else if (n.x == 0 && n.y == 0 && n.z == 0)
		ret = ft_check_rf_cylz(cyl, ray);
	return (ret);
}
