/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hit_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 09:57:35 by irifarac          #+#    #+#             */
/*   Updated: 2023/03/20 14:03:12 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shaderec.h"

static void	ft_hit_sphere(t_object *tmp, t_world *world, t_ray *ray, t_shaderec *shade)
{
	t_sphere	*sphere;
	double		t;

	sphere = (t_sphere *)tmp;
	t = ft_check_sphere(world->camera, sphere, ray);
	if (t != 0 && t < shade->t)
	{
		shade->hit_object = true;
		shade->ray = *ray;
		shade->t = t;
		shade->colour.r = sphere->r;
		shade->colour.g = sphere->g;
		shade->colour.b = sphere->b;
		shade->hit_point = ft_hit_point(ray, t);
	}
}

static void	ft_hit_plane(t_object *tmp, t_world *world, t_ray *ray, t_shaderec *shade)
{
	t_plane	*plane;
	double		t;

	plane = (t_plane *)tmp;
	t = ft_check_plane(world->camera, plane, ray);
	if (t != 0 && t < shade->t)
	{
		shade->hit_object = true;
		shade->ray = *ray;
		shade->t = t;
		shade->colour.r = plane->r;
		shade->colour.g = plane->g;
		shade->colour.b = plane->b;
		shade->hit_point = ft_hit_point(ray, t);
	}
}

static t_object	*ft_advance(t_object *tmp)
{
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cyl;

	if (!tmp)
		return (NULL);
	if (tmp->type == sp)
	{
		sphere = (t_sphere *)tmp;
		tmp = sphere->obj;
	}
	else if (tmp->type == pl)
	{
		plane = (t_plane *)tmp;
		tmp = plane->obj;
	}
	else if (tmp->type == cy)
	{
		cyl = (t_cylinder *)tmp;
		tmp = cyl->obj;
	}
	return (tmp);
}

static void	ft_hit_cyl(t_object *tmp, t_world *world, t_ray *ray, t_shaderec *shade)
{
	(void)tmp;
	(void)world;
	(void)ray;
	(void)shade;
}

t_shaderec	*ft_hit_objects(t_object *obj, t_world *world, t_ray *ray, t_shaderec *shade)
{
//	t_normal	normal;
//	t_point3d	p_hit;
	t_object	*tmp;

	tmp = obj;
	while (tmp)
	{
		if (tmp->type == sp)
			ft_hit_sphere(tmp, world, ray, shade);
		else if (tmp->type == pl)
			ft_hit_plane(tmp, world, ray, shade);
		else if (tmp->type == cy)
			ft_hit_cyl(tmp, world, ray, shade);
//			ft_hit_cyl(tmp, world, ray, shade);
		else
			break ;
		tmp = ft_advance(tmp);
	}
	return (shade);
}
