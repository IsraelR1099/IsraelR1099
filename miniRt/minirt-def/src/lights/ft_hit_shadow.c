/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hit_shadow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:59:19 by irifarac          #+#    #+#             */
/*   Updated: 2023/05/05 11:17:33 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lights.h"

static bool	ft_hit_sph(t_object *tmp, t_ray ray, double t_min)
{
	t_sphere	*sphere;
	double		distance;

	sphere = (t_sphere *)tmp;
	distance = ft_hit_sphere(sphere, ray);
	if (distance != 0 && distance < t_min)
		return (true);
	return (false);
}

static bool	ft_hit_pl(t_object *tmp, t_ray ray, double t_min)
{
	t_plane	*plane;
	double	distance;

	plane = (t_plane *)tmp;
	distance = ft_hit_plane(plane, ray);
	if (distance != 0 && distance < t_min)
		return (true);
	return (false);
}

static bool	ft_hit_cy(t_object *tmp, t_ray ray, double t_min)
{
	(void)tmp;
	(void)ray;
	(void)t_min;
	return (false);
}

static bool	ft_hit_di(t_object *tmp, t_ray ray, double t_min)
{
	t_disk	*disk;
	double	distance;

	disk = (t_disk *)tmp;
	distance = ft_hit_disk(disk, ray);
	if (distance != 0 && distance < t_min)
		return (true);
	return (false);
}

bool	ft_hit_shadow(t_ray ray, t_world *world, double t)
{
	t_object	*tmp;
	bool		ret;

	tmp = world->obj;
	ret = false;
	while (tmp)
	{
		if (tmp->type == sp)
			ret = ft_hit_sph(tmp, ray, t);
		else if (tmp->type == pl)
			ret = ft_hit_pl(tmp, ray, t);
		else if (tmp->type == cy)
			ret = ft_hit_cy(tmp, ray, t);
		else if (tmp->type == di)
			ret = ft_hit_di(tmp, ray, t);
		else
			break ;
		if (ret == true)
			return (true);
		tmp = ft_advance(tmp);
	}
	return (ret);
}
