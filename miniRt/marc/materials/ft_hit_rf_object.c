/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hit_rf_object.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:37:36 by irifarac          #+#    #+#             */
/*   Updated: 2023/06/05 12:10:10 by msoler-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "materials.h"

static void	ft_hit_rf_sphere(t_object *tmp, t_ray *ray,
t_shaderec *shade)
{
	t_sphere	*sphere;
	double		t;

	sphere = (t_sphere *)tmp;
	t = ft_check_rf_sphere(sphere, ray);
	if (t != 0 && t < shade->t)
	{
		shade->hit_object = true;
		shade->ray = *ray;
		shade->t = t;
		shade->colour.r = sphere->r;
		shade->colour.g = sphere->g;
		shade->colour.b = sphere->b;
		shade->type = sphere->type;
		shade->hit_point = ft_hit_point(ray, t);
		shade->normal_hit = ft_vect_normal_sphere(sphere, shade->hit_point);
	}
}

static void	ft_hit_rf_plane(t_object *tmp, t_ray *ray,
t_shaderec *shade)
{
	t_plane		*plane;
	t_normal	normal_plane;
	double		t;

	plane = (t_plane *)tmp;
	t = ft_check_rf_plane(plane, ray);
	if (t != 0 && t < shade->t)
	{
		normal_plane.x = plane->x_normal;
		normal_plane.y = plane->y_normal;
		normal_plane.z = plane->z_normal;
		shade->hit_object = true;
		shade->ray = *ray;
		shade->normal_hit = normal_plane;
		shade->t = t;
		shade->colour.r = plane->r;
		shade->colour.g = plane->g;
		shade->colour.b = plane->b;
		shade->type = plane->type;
		shade->hit_point = ft_hit_point(ray, t);
	}
}

static void	ft_hit_rf_cyl(t_object *tmp, t_ray *ray,
t_shaderec *shade)
{
	t_cylinder	*cylon;
	double		t;

	cylon = (t_cylinder *)tmp;
	t = ft_check_rf_cylon(*cylon, *ray);
	if (t != 0 && t < shade->t)
	{
		shade->hit_object = true;
		shade->ray = *ray;
		shade->t = t;
		shade->colour.r = cylon->r;
		shade->colour.g = cylon->g;
		shade->colour.b = cylon->b;
		shade->type = cylon->type;
		shade->hit_point = ft_hit_point(ray, t);
		shade->normal_hit = ft_vect_normal_cyl(cylon, shade->hit_point);
	}
}

static void	ft_hit_rf_disk(t_object *tmp, t_ray *ray,
t_shaderec *shade)
{
	t_disk		*disk;
	t_normal	normal_disk;
	double		t;

	disk = (t_disk *)tmp;
	t = ft_check_rf_disk(disk, ray);
	if (t != 0 && t < shade->t)
	{
		normal_disk.x = disk->x_normal;
		normal_disk.y = disk->y_normal;
		normal_disk.z = disk->z_normal;
		shade->hit_object = true;
		shade->ray = *ray;
		shade->normal_hit = normal_disk;
		shade->t = t;
		shade->colour.r = disk->r;
		shade->colour.g = disk->g;
		shade->colour.b = disk->b;
		shade->type = disk->type;
		shade->hit_point = ft_hit_point(ray, t);
	}
}

t_shaderec	*ft_hit_rf_objects(t_object *obj, t_ray *ray, t_shaderec *shade)
{
	t_object	*tmp;

	tmp = obj;
	while (tmp)
	{
		if (tmp->type == sp)
			ft_hit_rf_sphere(tmp, ray, shade);
		else if (tmp->type == pl)
			ft_hit_rf_plane(tmp, ray, shade);
		else if (tmp->type == cy)
			ft_hit_rf_cyl(tmp, ray, shade);
		else if (tmp->type == di)
			ft_hit_rf_disk(tmp, ray, shade);
		else
			break ;
		tmp = ft_advance(tmp);
	}
	return (shade);
}
