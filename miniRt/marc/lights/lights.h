/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:09:09 by irifarac          #+#    #+#             */
/*   Updated: 2023/05/15 10:20:41 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHTS_H
# define LIGHTS_H

# include "../color/rgbcolor.h"
# include "../maths/maths.h"
# include "../utilities/shaderec.h"

typedef struct s_light_ambient
{
	double		light_s;
	t_rgb		color;
}	t_light_ambient;

t_rgb		ft_light(double light_s, t_rgb color);
t_vector3d	ft_get_dir(t_light *light, t_shaderec *shade);
bool		ft_hit_shadow(t_ray ray, t_world *world, double t);
double		ft_hit_sphere(t_sphere *sphere, t_ray ray);
double		ft_hit_plane(t_plane *plane, t_ray ray);
double		ft_hit_disk(t_disk *disk, t_ray ray);
bool		ft_in_shadow(t_ray shadow_ray, t_shaderec *shade, t_light *light);
t_object	*ft_advance(t_object *tmp);
double		ft_hit_cylon(t_cylinder cylon, t_ray ray);
//utilites check cylon
void		ft_cyl_center_normal_rad(t_cylinder cylon, t_vector3d *cyl_normal,
				t_vector3d *cyl_center);
void		ft_ray_origin(t_ray ray, t_vector3d *ray_orig);
double		distance(const t_vector3d p1, const t_vector3d p2);
double		solve_plane(t_vector3d o, t_vector3d d,
				t_vector3d p_p, t_vector3d p_nv);
void		swap_doubles(double *a, double *b);
t_vector3d	a_sqrt(t_ray ray, t_vector3d cyl_normal);
int			solve_quadratic(double quadratic[3], double *x0, double *x1);
double		ft_return(double t1, double t0);

#endif
