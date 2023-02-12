#include "../include/miniRT.h"

static t_object	*ft_ret_sphere(t_object *obj, int type)
{
	static t_object		*tmp = NULL;

	if (!tmp)
		tmp = obj;
	while (tmp)
	{
		if (tmp->type == type)
			return (tmp);
		else
		{
			if (tmp->type == 3)
				tmp = ft_util_find(tmp, 3);
			else if (tmp->type == 4)
				tmp = ft_util_find(tmp, 4);
			else if (tmp->type == 5)
				tmp = ft_util_find(tmp, 5);
			else
				break;
		}
	}
	return (0);
}

static t_object	*ft_ret_plane(t_object *obj, int type)
{
	static t_object		*tmp = NULL;

	if (!tmp)
		tmp = obj;
	while (tmp)
	{
		if (tmp->type == type)
			return (tmp);
		else
		{
			if (tmp->type == 3)
				tmp = ft_util_find(tmp, 3);
			else if (tmp->type == 4)
				tmp = ft_util_find(tmp, 4);
			else if (tmp->type == 5)
				tmp = ft_util_find(tmp, 5);
			else
				break;
		}
	}
	return (0);
}

static t_object	*ft_ret_cyl(t_object *obj, int type)
{
	static t_object		*tmp = NULL;

	if (!tmp)
		tmp = obj;
	while (tmp)
	{
		if (tmp->type == type)
			return (tmp);
		else
		{
			if (tmp->type == 3)
				tmp = ft_util_find(tmp, 3);
			else if (tmp->type == 4)
				tmp = ft_util_find(tmp, 4);
			else if (tmp->type == 5)
				tmp = ft_util_find(tmp, 5);
			else
				break;
		}
	}
	return (0);
}

t_object	*ft_check_obj(t_object *obj, int type)
{
	t_sphere	*sph;
	t_plane		*plane;
	t_cylinder	*cyl;

	if (type == sp)
	{
		sph = (t_sphere *)ft_ret_sphere(obj, sp);
		return ((t_object *)sph);
	}
	else if (type == pl)
	{
		plane = (t_plane *)ft_ret_plane(obj, pl);
		return ((t_object *)plane);
	}
	else if (type == cy)
	{
		cyl = (t_cylinder *)ft_ret_cyl(obj, cy);
		return ((t_object *)cyl);
	}
	return (NULL);
}

int	ft_inter_sphere(t_ambient *amb, t_object *obj, t_vector ray_dir)
{
	t_sphere	*sphere;
	double		t;
	double		t_prima;
	int			color;

	sphere = (t_sphere *)ft_check_obj(obj, sp);
	color = sphere->r << 16 | sphere->g << 8 | sphere->b;
	t = ft_distance_sphere(amb, sphere, ray_dir);
	if (t == 0)
		return (0);
	t_prima = 0;
	while (sphere != NULL)
	{
		sphere = (t_sphere *)ft_check_obj(obj, sp);
		if (!sphere)
			break ;
		t_prima = ft_distance_sphere(amb, sphere, ray_dir);
		if (t_prima == 0)
			return (1);
		if (t_prima < t)
		{
			t = t_prima;
			color = sphere->r << 16 | sphere->g << 8 | sphere->b;
		}
	}
	return (color);
}
