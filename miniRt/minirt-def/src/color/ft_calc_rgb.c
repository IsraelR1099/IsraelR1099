/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:20:11 by irifarac          #+#    #+#             */
/*   Updated: 2023/04/26 13:52:03 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rgbcolor.h"

t_rgb	ft_rgb_scalar_product(t_rgb color, double scalar)
{
	t_rgb	ret;

	ret.r = color.r * scalar;
	ret.g = color.g * scalar;
	ret.b = color.b * scalar;
	return (ret);
}

t_rgb	ft_rgb_sum(t_rgb first, t_rgb second)
{
	t_rgb	ret;

	ret.r = first.r + second.r;
	ret.g = first.g + second.g;
	ret.b = first.b + second.b;
	return (ret);
}

t_rgb	ft_max_to_one(t_rgb light_color)
{
	t_rgb	ret;
	double	value;

	value = 1.00;
	if (light_color.r > 1)
		value = light_color.r;
	if (light_color.g > 1 && light_color.g > value)
		value = light_color.g;
	if (light_color.b > 1 && light_color.b > value)
		value = light_color.b;
	//if (light_color.r > 1 || light_color.g > 1 || light_color.b > 1)
	//	ft_clamp_to_color(&light_color);
	ret.r = light_color.r / value;
	ret.g = light_color.g / value;
	ret.b = light_color.b / value;
	return (ret);
}

t_rgb	ft_rgb_product_vect(t_rgb first, t_rgb second)
{
	t_rgb	ret;

	ret.r = first.r * second.r;
	ret.g = first.g * second.g;
	ret.b = first.b * second.b;
	return (ret);
}

t_rgb	*ft_clamp_to_color(t_rgb *light_color)
{
	light_color->r = 1;
	light_color->r = 1;
	light_color->r = 1;
	return (light_color);
}
