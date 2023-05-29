/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 09:24:18 by irifarac          #+#    #+#             */
/*   Updated: 2023/05/29 09:24:19 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometricobj.h"


static t_point3d	ft_transform_origin(t_point3d origin)
{
	t_point3d	ret;
	double		tetta;

//	tetta = PI / 2;
	tetta = 0.7854;
	ret.x = origin.x * (cos(tetta) - sin(tetta));
	ret.y = origin.y;
	ret.z = origin.z * (sin(tetta) + cos(tetta));
/*	ret.x = origin.x * (cos(tetta) + sin(tetta));
	ret.y = origin.y * (-sin(tetta) + cos(tetta));
	ret.z = origin.z;*/
	return (ret);
}

static t_vector3d	ft_transform_dir(t_vector3d dir)
{
	t_vector3d	ret;
	double		tetta;

//	tetta = PI / 2;
	tetta = 0.7854;
/*	ret.x = dir.x * (cos(tetta) + sin(tetta));
	ret.y = dir.y * (-sin(tetta) + cos(tetta));
	ret.z = dir.z;*/
	ret.x = dir.x * (cos(tetta) - sin(tetta));
	ret.y = dir.y;
	ret.z = dir.z * (sin(tetta) + cos(tetta));
	return (ret);
}


t_ray	ft_transform_ray(t_ray *ray)
{
	t_ray	new_ray;

	new_ray.origin = ft_transform_origin(ray->origin);
	new_ray.direction = ft_transform_dir(ray->direction);
	return (new_ray);
}
