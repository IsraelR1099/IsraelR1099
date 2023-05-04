#include "materials.h"

//Shoot another ray from the hit point to the direction of wi (reflected)

t_rgb	ft_shade_reflective(t_world *world, t_shaderec *shade)
{
	t_rgb		l;
	t_rgb		l2;
	t_rgb		sample_f;
	t_vector3d	wo;
	t_vector3d	wi;
	t_ray		reflective_ray;
	t_vector3d	normal;
	static int	depth = 0;
	double		dotnwi;

	wo.x = shade->ray.direction.x * (-1);
	wo.y = shade->ray.direction.y * (-1);
	wo.z = shade->ray.direction.z * (-1);
	l = ft_shade_phong(world, shade);
	sample_f = ft_reflective_f(world, shade, wo, &wi);
	reflective_ray.origin = shade->hit_point;
	reflective_ray.direction = wi;
	l2 = ft_rgb_product_vect(sample_f, ft_trace_ray(world, &reflective_ray, depth));
	depth++;
	if (depth > shade->max_bounces)
		depth = 0;
	normal.x = shade->normal_hit.x;
	normal.y = shade->normal_hit.y;
	normal.z = shade->normal_hit.z;
	dotnwi = ft_dot_product_vect(normal, wi);
	l2 = ft_rgb_scalar_product(l, dotnwi);
	l = ft_rgb_sum(l, l2);
	return (l);
}

