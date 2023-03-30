#include "shaderec.h"

t_normal	ft_vect_normal_sphere(t_sphere *sphere, t_ray *ray, double t)
{
	t_vector3d	tmp;
	t_vector3d	center_sph;
	t_vector3d	origin;
	t_vector3d	ray_dir;
	t_normal	ret;

	center_sph.x = sphere->x;
	center_sph.y = sphere->y;
	center_sph.z = sphere->z;
	origin.x = ray->origin.x;
	origin.y = ray->origin.y;
	origin.z = ray->origin.z;
	tmp = ft_rest_vect(origin, center_sph);
	ray_dir = ft_product_vect_scalar(ray->direction, t);
	tmp = ft_sum_vect(tmp, ray_dir);
	ret.x = tmp.x;
	ret.y = tmp.y;
	ret.z = tmp.z;
	ret.x /= (sphere->diameter / 2);
	ret.y /= (sphere->diameter / 2);
	ret.z /= (sphere->diameter / 2);
	return (ret);
}

t_vector3d	ft_normalize(t_vector3d vector)
{
	double		magnitude;
	t_vector3d	normal;

	magnitude = sqrt(vector.x * vector.x + vector.y * vector.y
	+ vector.z * vector.z);
	normal.x = vector.x;
	normal.y = vector.y;
	normal.z = vector.z;
	normal.x /= magnitude;
	normal.y /= magnitude;
	normal.z /= magnitude;
	return (normal);
}
