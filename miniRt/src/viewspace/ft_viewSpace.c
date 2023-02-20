/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_viewSpace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:34:44 by irifarac          #+#    #+#             */
/*   Updated: 2023/02/20 13:20:00 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

t_vector	ft_forwardVector(t_vector cameraPos, t_vector direction)
{
	t_vector	forwardVector;
	t_vector	forward_normal;
	double		magnitude;

	forwardVector = ft_rest_vect(cameraPos, direction);
	magnitude = sqrt(forwardVector.x * forwardVector.x + forwardVector.y *
	forwardVector.y + forwardVector.z * forwardVector.z);
	forward_normal.x = forwardVector.x / magnitude;
	forward_normal.y = forwardVector.y / magnitude;
	forward_normal.z = forwardVector.z / magnitude;
	return (forward_normal);
}

t_vector	ft_rightAxis(t_vector UpVector, t_vector forward_normal)
{
	t_vector	right_normal;
	t_vector	rightVector;
	double		magnitude;

	rightVector = ft_vectorial_product(UpVector, forward_normal);
	magnitude = sqrt(rightVector.x * rightVector.x + rightVector.y *
	rightVector.y + rightVector.z * rightVector.z);
	right_normal.x = rightVector.x / magnitude;
	right_normal.y = rightVector.y / magnitude;
	right_normal.z = rightVector.z / magnitude;
	return (right_normal);
}

t_vector	ft_UpAxis(t_vector forward_normal, t_vector right_normal)
{
	t_vector	UpVector;
	t_vector	Up_normal;
	double		magnitude;

	UpVector = ft_vectorial_product(forward_normal, right_normal);
	magnitude = sqrt(UpVector.x * UpVector.x + UpVector.y * UpVector.y +
	UpVector.z * UpVector.z);
	Up_normal.x = UpVector.x / magnitude;
	Up_normal.y = UpVector.y / magnitude;
	Up_normal.z = UpVector.z / magnitude;
	return (Up_normal);
}
