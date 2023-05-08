/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cameras.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:56:12 by irifarac          #+#    #+#             */
/*   Updated: 2023/05/08 11:08:33 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERAS_H
# define CAMERAS_H

# include "../parser/parser.h"
# include "../maths/maths.h"
# include "../window/window.h"

//d distance to viewplane
//right vector u
//up vector v
//forward vector w

typedef struct s_cameras
{
	t_point3d	eye;
	t_point3d	lookat;
	t_vector3d	right;
	t_vector3d	up;
	t_vector3d	forward;
	double		d;
}	t_cameras;

t_cameras	*ft_build_camera(t_ambient *amb);
t_vector3d	ft_upvector(t_cameras camera);
t_vector3d	ft_rightaxis(t_vector3d forward);
t_vector3d	ft_forwardvector(t_cameras camera);

//Utils
t_ambient	*ft_find_amb(t_ambient *amb, int type);
t_vector3d	ft_ray_direction(t_cameras *camera, t_ray *ray, t_point2d points);

#endif
