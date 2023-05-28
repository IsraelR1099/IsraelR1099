#include "geometricobj.h"

void	ft_set_limits(t_cylinder *cyl, double limit[2])
{
	t_vector3d	n;

	n.x = cyl->x_normal;
	n.y = cyl->y_normal;
	n.z = cyl->z_normal;
	if (n.x == 1 && n.y == 0 && n.z == 0)
	{
		limit[0] = cyl->x - (cyl->height / 2);
		limit[1] = cyl->x + (cyl->height / 2);
	}
	else if (n.x == 0 && n.y == 1 && n.z == 0)
	{
		limit[0] = cyl->y - (cyl->height / 2);
		limit[1] = cyl->y + (cyl->height / 2);
	}
	else if (n.x == 0 && n.y == 0 && n.z == 1)
	{
		limit[0] = cyl->z - (cyl->height / 2);
		limit[1] = cyl->z + (cyl->height / 2);
	}
}

int	ft_check_limit(t_cylinder *cyl, t_point3d hit_p, double limit[2])
{
	t_vector3d	n;

	n.x = cyl->x_normal;
	n.y = cyl->y_normal;
	n.z = cyl->z_normal;
	if (n.x == 1 && n.y == 0 && n.z == 0)
	{
		if (hit_p.x > limit[0] && hit_p.x < limit[1])
			return (1);
	}
	else if (n.x == 0 && n.y == 1 && n.z == 0)
	{
		if (hit_p.y > limit[0] && hit_p.y < limit[1])
			return (1);
	}
	else if (n.x == 0 && n.y == 0 && n.z == 1)
	{
		if (hit_p.z > limit[0] && hit_p.z < limit[1])
			return (1);
	}
	return (0);
}

double	ft_check_normal(t_cylinder *cyl, t_ray *ray)
{
	t_vector3d	n;
	double		ret;

	n.x = cyl->x_normal;
	n.y = cyl->y_normal;
	n.z = cyl->z_normal;
	ret = 0;
	if (n.x == 0 && n.y == 1 && n.z == 0)
		ret = ft_check_cyly(cyl, ray);
	else if (n.x == 0 && n.y == 0 && n.z == 1)
		ret = ft_check_cylz(cyl, ray);
	return (ret);
}
