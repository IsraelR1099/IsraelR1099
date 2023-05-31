/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hit_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 09:57:35 by irifarac          #+#    #+#             */
/*   Updated: 2023/05/31 14:00:20 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shaderec.h"

static void	ft_hit_sphere(t_object *tmp, t_world *world, t_ray *ray,
t_shaderec *shade)
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
		shade->type = sphere->type;
		shade->hit_point = ft_hit_point(ray, t);
		shade->normal_hit = ft_vect_normal_sphere(sphere, shade->hit_point);
	}
}

static void	ft_hit_plane(t_object *tmp, t_world *world, t_ray *ray,
t_shaderec *shade)
{
	t_plane		*plane;
	t_normal	normal_plane;
	double		t;

	plane = (t_plane *)tmp;
	t = ft_check_plane(world->camera, plane, ray);
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

static void	ft_hit_cyl(t_object *tmp, t_world *world, t_ray *ray,
t_shaderec *shade)
{
	t_cylinder	*cylon;
	double		t;

	(void)world;
	cylon = (t_cylinder *)tmp;
	//t = ft_check_cylon(*cylon, *ray);
	t = ft_check_cil(cylon, ray);
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
		printf("t es %f\n", t);
		shade->normal_hit = ft_vect_normal_cyl(cylon, ray, shade->hit_point, t);
	}
}

/*static void	ft_hit_cyl(t_object *tmp, t_world *world, t_ray *ray,
t_shaderec *shade)
{
	t_cylinder	*cylon;
	t_point3d	hit_p;
	double		t;
	double		limit[2];

	(void)world;
	cylon = (t_cylinder *)tmp;
	t = ft_check_cyl(cylon, ray);
	if (t != 0)
	{
		hit_p = ft_hit_point(ray, t);
		ft_set_limits(cylon, limit);
	}
	//if (t != 0 && t < shade->t && hit_p.x > limit[0] && hit_p.x < limit[1])
	if (t != 0 && t < shade->t && ft_check_limit(cylon, hit_p, limit))
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
*/
static void	ft_hit_disk(t_object *tmp, t_world *world, t_ray *ray,
t_shaderec *shade)
{
	t_disk		*disk;
	t_normal	normal_disk;
	double		t;

	disk = (t_disk *)tmp;
	t = ft_check_disk(world->camera, disk, ray);
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

t_shaderec	*ft_hit_objects(t_object *obj, t_world *world, t_ray *ray,
t_shaderec *shade)
{
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
		else if (tmp->type == di)
			ft_hit_disk(tmp, world, ray, shade);
		else
			break ;
		tmp = ft_advance(tmp);
	}
	return (shade);
}
