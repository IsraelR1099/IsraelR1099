/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometricobj.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:27:51 by irifarac          #+#    #+#             */
/*   Updated: 2023/06/07 09:50:45 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRICOBJ_H
# define GEOMETRICOBJ_H

# include <math.h>
# include <stdbool.h>
# include "../parser/parser.h"
# include "../maths/maths.h"
# include "../cameras/cameras.h"
# define KEPSILONPL 0.001
# define KEPSILONSP 0.001
# define KEPSILONDI 0.001

double		ft_check_sphere(t_cameras *camera, t_sphere *sphere, t_ray *ray);
double		ft_check_plane(t_cameras *camera, t_plane *plnae, t_ray *ray);
double		ft_check_disk(t_cameras *camera, t_disk *disk, t_ray *ray);
double		ft_check_cylon(t_cylinder cylon, t_ray ray);
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
