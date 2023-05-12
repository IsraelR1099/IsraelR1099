/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_rgb2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:46:59 by irifarac          #+#    #+#             */
/*   Updated: 2023/05/05 12:48:57 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rgbcolor.h"

t_rgb	ft_rgb_division(t_rgb up, double scalar)
{
	t_rgb	ret;

	ret.r = up.r / scalar;
	ret.g = up.g / scalar;
	ret.b = up.b / scalar;
	return (ret);
}
