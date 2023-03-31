/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:20:11 by irifarac          #+#    #+#             */
/*   Updated: 2023/03/31 10:20:12 by irifarac         ###   ########.fr       */
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
