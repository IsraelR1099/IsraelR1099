#include "shaderec.h"

static void	ft_hit_sphere(t_object *tmp, t_world *world, t_ray ray, t_shaderec shade)
{
	t_sphere	*sphere;
	double		t;

	sphere = (t_sphere *)tmp;
	t = ft_check_sphere(world->camera, sphere, ray);
	if (t != 0 && t < shade.t)
	{
		shade.hit_object = true;
		shade.ray = ray;
		shade.t = t;
		shade.hit_point = ft_hit_point(ray);
	}
}


static void	ft_hit_plane(t_object *tmp, t_world *world, t_ray ray, t_shaderec shade)
{
	t_plane	*plane;
	double		t;

	plane = (t_plane *)tmp;
	t = ft_check_plane(world->camera, plane, ray);
	if (t != 0 && t < shade.t)
	{
		shade.hit_object = true;
		shade.ray = ray;
		shade.t = t;
		shade.hit_point = ft_hit_point(ray);
	}
}

t_object	ft_advance(t_object *tmp)
{
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cyl;
	t_object	*tmp2;

	tmp2 = tmp;
	if (tmp2->type = sp)
	{
		sphere = (t_sphere *)tmp2;
		return (sphere->obj);
	}
	else if (tmp2->type == pl)
	{
		plane = (t_plane *)tmp2;
		return (plane->obj);
	}
	else if (tmp2->type == cyl)
	{
		cyl = (t_cylinder *)tmp2;
		return (cyl->obj);
	}
	return (NULL);
}

t_shaderec	ft_hit_objects(t_object *obj, t_world *world, t_ray ray)
{
	t_shaderec	shade;
	t_normal	normal;
	t_point3d	p_hit;
	t_object	*tmp;
	double		t;

	tmp = obj;
	t = k_huge_value;
	shade.t = t;
	shade.hit_object = false;
	while (tmp)
	{
		if (tmp->type == sp)
			ft_hit_sphere(tmp, world, ray, shade);
		else if (tmp->type == pl)
			ft_hit_plane(tmp, world, ray, shade);
	//	else if (tmp->type == cyl)
	//		ft_hit_cyl(tmp, world, ray, shade);
		else
			tmp = ft_advance(tmp);
	}
	return (shade);
}
