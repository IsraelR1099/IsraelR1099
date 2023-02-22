/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:34:33 by irifarac          #+#    #+#             */
/*   Updated: 2023/02/22 11:04:03 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

double	ft_translationX(t_vector cameraPos, t_vector direction, t_4dvector *look_at)
{
	double		translationX;
	t_vector	rightVector;
	t_vector	tmpUpVector;
	t_vector	forwardVector;

	tmpUpVector.x = 0;
	tmpUpVector.y = 1;
	tmpUpVector.z = 0;
	forwardVector = ft_forwardVector(cameraPos, direction);
	look_at[0].z = forwardVector.x;
	look_at[1].z = forwardVector.y;
	look_at[2].z = forwardVector.z;
	rightVector = ft_rightAxis(tmpUpVector, forwardVector);
	look_at[0].x = rightVector.x;
	look_at[1].x = rightVector.y;
	look_at[2].x = rightVector.z;
	translationX = ft_dot_product_vect(cameraPos, rightVector);
	return (translationX);
}

double	ft_translationY(t_vector cameraPos, t_vector direction, t_4dvector *look_at)
{
	double		translationY;
	t_vector	UpVector;
	t_vector	forwardVector;
	t_vector	rightVector;
	t_vector	tmpUpVector;

	tmpUpVector.x = 0;
	tmpUpVector.y = 1;
	tmpUpVector.z = 0;
	forwardVector = ft_forwardVector(cameraPos, direction);
	rightVector = ft_rightAxis(tmpUpVector, forwardVector);
	UpVector = ft_UpAxis(forwardVector, rightVector);
	look_at[0].y = UpVector.x;
	look_at[1].y = UpVector.y;
	look_at[2].y = UpVector.z;
	translationY = ft_dot_product_vect(cameraPos, UpVector);
	return (translationY);
}

double	ft_translationZ(t_vector cameraPos, t_vector direction)
{
	double		translationZ;
	t_vector	forwardVector;

	forwardVector = ft_forwardVector(cameraPos, direction);
	translationZ = ft_dot_product_vect(cameraPos, forwardVector);
	return (translationZ);
}

void	ft_translation(t_ambient *amb, t_4dvector *look_at)
{
	t_cam		*camera;
	t_vector	cameraPos;
	t_vector	direction;

	camera = (t_cam *)ft_find_lst(amb, C);
	cameraPos.x = camera->x;
	cameraPos.y = camera->y;
	cameraPos.z = camera->z;
	direction.x = camera->x_normal;
	direction.y = camera->y_normal;
	direction.z = camera->z_normal;
	look_at[3].x = -ft_translationX(cameraPos, direction, look_at);
	look_at[3].y = -ft_translationY(cameraPos, direction, look_at);
	look_at[3].z = -ft_translationZ(cameraPos, direction);
	look_at[0].w = 0;
	look_at[1].w = 0;
	look_at[2].w = 0;
	look_at[3].w = 0;
}
