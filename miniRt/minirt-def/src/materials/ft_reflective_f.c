#include "materials.h"

// wi calc = -wo + 2.0 * normal * ndotwo
static t_vector3d	*ft_calc_wi(t_vector3d wo, t_vector3d normal, double ndotwo)
{
	t_vector3d	sum_wo;
	t_vector3d	dot;
	t_vector3d	*ret;

	dot = ft_product_vect_scalar(normal, ndotwo * 2.0);
	sum_wo = ft_sum_vect(wo, dot);
	ret->x = sum_wo.x;
	ret->y = sum_wo.y;
	ret->z = sum_wo.z;
	return (ret);
}

// total kr * cr / (normal * wi)
static t_rgb	ft_color_value(t_shaderec *shade, t_vector3d *wi, t_vector3d normal)
{
	double		kr;
	double		angle_normal_wi;
	t_rgb		reflective;
	t_rgb		ret;

	kr = 0.5;
	reflective = ft_rgb_scalar_product(shade->colour, kr);
	angle_normal_wi = ft_dot_product_vect(normal, *wi);
	ret = ft_rgb_division(reflective, angle_normal_wi);
	return (ret);
}

t_rgb	ft_reflective_f(t_world *world, t_shaderec *shade, t_vector3d wo,
t_vector3d *wi)
{
	double		ndotwo;
	t_vector3d	normal;

	normal.x = shade->normal_hit.x;
	normal.y = shade->normal_hit.y;
	normal.z = shade->normal_hit.z;
	wo.x = (-1) * shade->ray.direction.x;
	wo.y = (-1) * shade->ray.direction.y;
	wo.z = (-1) * shade->ray.direction.z;
	ndotwo = ft_dot_product_vect(normal, shade->ray.direction);
	wi = ft_calc_wi(wo, normal, ndotwo);
	(void)world;
	return (ft_color_value(shade, wi, normal));
}
