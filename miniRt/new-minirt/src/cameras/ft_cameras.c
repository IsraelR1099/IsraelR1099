/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cameras.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:54:24 by irifarac          #+#    #+#             */
/*   Updated: 2023/03/17 13:51:34 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../maths/maths.h"
#include "cameras.h"

t_vector3d	ft_forwardvector(t_cameras camera)
{
	t_vector3d	forwardvector;
	t_vector3d	forward_normal;
	t_vector3d	eye_vector;
	t_vector3d	lookat;
	double		magnitude;

	eye_vector.x = camera.eye.x;
	eye_vector.y = camera.eye.y;
	eye_vector.z = camera.eye.z;
	lookat.x = camera.lookat.x;
	lookat.y = camera.lookat.y;
	lookat.z = camera.lookat.z;
	forwardvector = ft_rest_vect(eye_vector, lookat);
	magnitude = sqrt(forwardvector.x * forwardvector.x + forwardvector.y
			* forwardvector.y + forwardvector.z * forwardvector.z);
	forward_normal.x = forwardvector.x / magnitude;
	forward_normal.y = forwardvector.y / magnitude;
	forward_normal.z = forwardvector.z / magnitude;
	return (forward_normal);
}

t_vector3d	ft_rightaxis(t_vector3d forward)
{
	t_vector3d	right_normal;
	t_vector3d	right;
	t_vector3d	uptmp;
	double		magnitude;

	uptmp.x = 0;
	uptmp.y = 1;
	uptmp.z = 0;
	right = ft_vectorial_product(uptmp, forward);
	magnitude = sqrt(right.x * right.x + right.y * right.y + right.z * right.z);
	right_normal.x = right.x / magnitude;
	right_normal.y = right.y / magnitude;
	right_normal.z = right.z / magnitude;
	return (right_normal);
}

t_vector3d	ft_upvector(t_cameras camera)
{
	t_vector3d	upvector;
	t_vector3d	up_normal;
	double		magnitude;

	upvector = ft_vectorial_product(camera.forward, camera.right);
	magnitude = sqrt(upvector.x * upvector.x + upvector.y * upvector.y
			+ upvector.z * upvector.z);
	up_normal.x = upvector.x / magnitude;
	up_normal.y = upvector.y / magnitude;
	up_normal.z = upvector.z / magnitude;
	return (up_normal);
}


static double	ft_distance_viewplane(t_cam *cam)
{
	double	d;
	double	radians;

	radians = cam->fov * PI / 180;
	d = (0.5 * hres) / tan(0.5 * radians);
	return (d);
}


t_cameras	*ft_build_camera(t_ambient *amb)
{
	t_cam		*cam;
	t_cameras	*camera;

	cam = (t_cam *)ft_find_amb(amb, C);
	if (!cam)
		return (NULL);
	camera = malloc(sizeof(*camera));
	if (!camera)
		return (NULL);
	camera->eye.x = cam->x;
	camera->eye.y = cam->y;
	camera->eye.z = cam->z;
	camera->lookat.x = cam->x_normal;
	camera->lookat.y = cam->y_normal;
	camera->lookat.z = cam->z_normal;
	camera->forward = ft_forwardvector(*camera);
	camera->right = ft_rightaxis(camera->forward);
	camera->up = ft_upvector(*camera);
	camera->d = ft_distance_viewplane(cam);
	//printf("d es %f\n", camera->d);
	return (camera);
}
