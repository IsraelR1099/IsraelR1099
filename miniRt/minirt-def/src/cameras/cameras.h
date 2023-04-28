/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cameras.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:56:12 by irifarac          #+#    #+#             */
/*   Updated: 2023/04/28 12:36:09 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERAS_H
# define CAMERAS_H

# include "../parser/parser.h"
# include "../maths/maths.h"
# include "../window/window.h"

typedef struct s_cameras
{
	t_point3d	eye;
	t_point3d	lookat;
	t_vector3d	right; //u
	t_vector3d	up; //v
	t_vector3d	forward; //w
	double		d; //distance to viewplane
}	t_cameras;

t_cameras	*ft_build_camera(t_ambient *amb);
t_vector3d	ft_upvector(t_cameras camera);
t_vector3d	ft_rightaxis(t_vector3d forward);
t_vector3d	ft_forwardvector(t_cameras camera);

//Utils
t_ambient	*ft_find_amb(t_ambient *amb, int type);
t_vector3d	ft_ray_direction(t_cameras *camera, t_ray *ray, t_point2d points);

#endif
