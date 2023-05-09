#include "materials.h"

t_rgb	ft_ray_cast(t_world *world, t_shaderec *shade, t_vector3d *wi)
{
	t_rgb		sample_f;
	t_vector3d	wo;
	t_vector3d	wi;
	t_ray		reflective_ray;

	wo.x = shade->ray.direction.x * (-1);
	wo.y = shade->ray.direction.y * (-1);
	wo.z = shade->ray.direction.z * (-1);
	sample_f = ft_reflective_f(shade, wo, wi);
	reflective_ray.origin = shade->hit_point;
	reflective_ray.direction = *wi;
	return (ft_trace_reflective(world, &reflective_ray));
}
