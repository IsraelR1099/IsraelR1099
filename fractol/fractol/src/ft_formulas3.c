/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formulas3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:25:11 by irifarac          #+#    #+#             */
/*   Updated: 2022/05/31 10:38:27 by irifarac         ###   ########.fr       */
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

double	ft_glnx(double a, double b, double x)
{
	double	s_a;
	double	result;

	if (a < 0)
		a *= -1;
	s_a = sqrt(a);
	result = a * s_a - (3 * b * b / 8 * s_a) + x;
	return (result);
}

double	ft_glny(double a, double b, double y)
{
	double	s_a;
	double	result;

	if (a < 0)
		a *= -1;
	s_a = sqrt(a);
	result = (3 * s_a * b / 2) + (b * b * b / 16 * a * s_a) + y;
	return (result);
}
