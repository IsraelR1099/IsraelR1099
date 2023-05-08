/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   materials.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:22:17 by irifarac          #+#    #+#             */
/*   Updated: 2023/05/08 12:40:18 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIALS_H
# define MATERIALS_H

# include "../brdf/brdf.h"
# include "../maths/maths.h"
# include "../world/world.h"
# include "../utilities/shaderec.h"
# include "../lights/lights.h"
# include "../color/rgbcolor.h"
# include "../tracers/tracer.h"

typedef struct s_matte
{
	t_lambertian	*ambient_brdf;
	t_lambertian	*diffuse_brdf;
	t_rgb			(*ft_shade)(t_world * world, t_shaderec *shade);
}	t_matte;

t_rgb		ft_shade_phong(t_world *world, t_shaderec *shade);
t_rgb		ft_reflective_f(t_shaderec *shade, t_vector3d wo, t_vector3d *wi);
t_rgb		ft_shade_reflective(t_world *world, t_shaderec *shade);
t_shaderec	*ft_hit_rf_objects(t_object *obj, t_ray *ray, t_shaderec *shade);

//hit reflective objects
t_shaderec	*ft_hit_rf_objects(t_object *obj, t_ray *ray, t_shaderec *shade);

//check objects intersection
double		ft_check_rf_sphere(t_sphere *sphere, t_ray *ray);
double		ft_check_rf_plane(t_plane *plane, t_ray *ray);
double		ft_check_rf_disk(t_disk *disk, t_ray *ray);

//Utils
t_vector3d	ft_normal_vector3d(t_shaderec *shade);
t_vector3d	ft_dir_wo(t_shaderec *shade);
#endif
