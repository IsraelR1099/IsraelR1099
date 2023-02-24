/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_operation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:05:48 by irifarac          #+#    #+#             */
/*   Updated: 2023/02/24 11:52:15 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"
#include "../../mlx/mlx.h"

double	ft_dot_product_vect(t_vector vector_left, t_vector vector_right)
{
	float	x;
	float	y;
	float	z;
	float	ret;

	x = vector_left.x * vector_right.x;
	y = vector_left.y * vector_right.y;
	z = vector_left.z * vector_right.z;
	ret = x + y + z;
	return (ret);
}

t_vector	ft_vectorial_product(t_vector vector_left, t_vector vector_right)
{
	t_vector	crossVector;

	crossVector.x = vector_left.y * vector_right.z - vector_left.z *
	vector_right.y;
	crossVector.y = vector_right.x * vector_left.z - vector_right.z *
	vector_left.x;
	crossVector.z = vector_left.x * vector_right.y - vector_right.x *
	vector_left.y;
	return (crossVector);
}

t_vector	ft_rest_vect(t_vector origin, t_vector obj)
{
	t_vector	ret;

	ret.x = origin.x - obj.x;
	ret.y = origin.y - obj.y;
	ret.z = origin.z - obj.z;
	return (ret);
}

t_vector	ft_sum_vect(t_vector first, t_vector second)
{
	t_vector	ret;

	ret.x = first.x + second.x;
	ret.y = first.y + second.y;
	ret.y = first.z + second.z;
	return (ret);
}

t_vector	ft_product_vect_scalar(t_vector vector, double scalar)
{
	t_vector	ret;

	ret.x = vector.x * scalar;
	ret.y = vector.y * scalar;
	ret.z = vector.z * scalar;
	return (ret);
}
