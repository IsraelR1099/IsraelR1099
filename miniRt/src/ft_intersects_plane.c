/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersects_plane.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:38:13 by irifarac          #+#    #+#             */
/*   Updated: 2023/02/08 13:53:24 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

static double	ft_a_value(t_ambient *amb, t_plane *plane)
{
	t_cam		*cam;
	t_vector	cam_pos;
	t_vector	res_point_orig;
	t_vector	normal_plane;
	t_vector	point_plane;

	cam = (t_cam *)ft_find_lst(amb, C);
	cam_pos.x = cam->x;
	cam_pos.y = cam->y;
	cam_pos.z = cam->z;
	normal_plane.x = plane->x_normal;
	normal_plane.y = plane->y_normal;
	normal_plane.z = plane->z_normal;
	point_plane.x = plane->x;
	point_plane.y = plane->y;
	point_plane.z = plane->z;
	res_point_orig = ft_rest_vect(point_plane, cam_pos);
	return (ft_dot_product_vect(normal_plane, res_point_orig));
}

int	ft_inter_plane(t_ambient *amb, t_object *obj, t_vector ray_dir)
{
	t_vector	normal_plane;
	t_plane		*plane;
	double		ret_b;
	double		t;

	plane = (t_plane *)ft_find_lst_obj(obj, pl);
	normal_plane.x = plane->x_normal;
	normal_plane.y = plane->y_normal;
	normal_plane.z = plane->z_normal;
	ret_b = ft_dot_product_vect(normal_plane, ray_dir);
	if (ret_b == 0)
		return (0);
	t = ft_a_value(amb, plane) / ret_b;
	(void)t;
	return (1);
}
