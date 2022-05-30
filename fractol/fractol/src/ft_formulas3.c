/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formulas3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:25:11 by irifarac          #+#    #+#             */
/*   Updated: 2022/05/30 13:48:07 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_fractal.h"

double	ft_calin3x(double a, double b, double x, double y)
{
	double	result;

	result = ((a * a * a) - (3 * a * b * b)) + (x / ((x * x) + (y * y)));
	return (result);
}

double	ft_calin3y(double a, double b, double x, double y)
{
	double	result;

	result = ((3 * a * a * b) - (b * b * b)) - (y / ((x * x) + (y * y)));
	return (result);
}
