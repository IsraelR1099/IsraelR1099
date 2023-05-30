/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:09:09 by irifarac          #+#    #+#             */
/*   Updated: 2023/05/15 10:20:26 by irifarac         ###   ########.fr       */
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
double		ft_hit_sphere(t_sphere *sphere, t_ray ray);
double		ft_hit_plane(t_plane *plane, t_ray ray);
double		ft_hit_disk(t_disk *disk, t_ray ray);
double		ft_hit_cylon(t_cylinder cylon, t_ray ray);
double		ft_hit_cyl(t_cylinder *cyl, t_ray ray);
double		ft_hit_cil(t_cylinder *cyl, t_ray *ray);
double		ft_hit_cyly(t_cylinder *cyl, t_ray *ray);
double		ft_hit_cylz(t_cylinder *cyl, t_ray *ray);
bool		ft_in_shadow(t_ray shadow_ray, t_shaderec *shade, t_light *light);
bool		ft_hit_shadow(t_ray ray, t_world *world, double t);
t_object	*ft_l_advance(t_object *tmp);

//Utilities check cylon
double		ft_check_l_normal(t_cylinder *cyl, t_ray *ray);
void		ft_cyl_center_normal_rad(t_cylinder cylon, t_vector3d *cyl_normal,
				t_vector3d *cyl_center);
void		ft_ray_origin(t_ray ray, t_vector3d *ray_orig);
void		swap_doubles(double *a, double *b);
double		distance(const t_vector3d p1, const t_vector3d p2);
double		solve_plane(t_vector3d o, t_vector3d d, t_vector3d p_p,
				t_vector3d p_nv);
double		ft_return(double t1, double t0);
t_vector3d	a_sqrt(t_ray ray, t_vector3d cyl_normal);
int			solve_quadratic(double quadratic[3], double *x0, double *x1);
#endif
