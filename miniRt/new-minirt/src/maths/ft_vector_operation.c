/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector3d_operation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:05:48 by irifarac          #+#    #+#             */
/*   Updated: 2023/03/20 11:18:19 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths.h"

double	ft_dot_product_vect(t_vector3d vector_left, t_vector3d vector_right)
{
	float	x;
	float	y;
	float	z;
	float	ret;

	x = vector_left.x * vector_right.x;
	y = vector_left.y * vector_right.y;
	z = vector_left.z * vector_right.z;
	//printf("left x %f, right x %f\n", vector_left.x, vector_right.x);
	ret = x + y + z;
	return (ret);
}

t_vector3d	ft_vectorial_product(t_vector3d vector_left, t_vector3d vector_right)
{
	t_vector3d	crossvector;

	crossvector.x = vector_left.y * vector_right.z - vector_left.z
		* vector_right.y;
	crossvector.y = vector_right.x * vector_left.z - vector_right.z
		* vector_left.x;
	crossvector.z = vector_left.x * vector_right.y - vector_right.x
		* vector_left.y;
	return (crossvector);
}

t_vector3d	ft_rest_vect(t_vector3d origin, t_vector3d obj)
{
	t_vector3d	ret;

	ret.x = origin.x - obj.x;
	ret.y = origin.y - obj.y;
	ret.z = origin.z - obj.z;
	return (ret);
}

t_vector3d	ft_sum_vect(t_vector3d first, t_vector3d second)
{
	t_vector3d	ret;

	ret.x = first.x + second.x;
	ret.y = first.y + second.y;
	ret.z = first.z + second.z;
	return (ret);
}

t_vector3d	ft_product_vect_scalar(t_vector3d vector, double scalar)
{
	t_vector3d	ret;

	ret.x = vector.x * scalar;
	ret.y = vector.y * scalar;
	ret.z = vector.z * scalar;
	return (ret);
}
