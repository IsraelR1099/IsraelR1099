/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:20:11 by irifarac          #+#    #+#             */
/*   Updated: 2023/04/03 13:37:03 by irifarac         ###   ########.fr       */
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

t_rgb	ft_clamp_color(t_rgb light_color)
{
	t_rgb	ret;
	double	value;

	value = 1.00;
	if (light_color.r > 255)
		value = light_color.r;
	else if (light_color.g > 255)
		value = light_color.g;
	else if (light_color.b > 255)
		value = light_color.b;
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

