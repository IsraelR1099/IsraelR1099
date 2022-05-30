/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formulas2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 09:23:46 by irifarac          #+#    #+#             */
/*   Updated: 2022/05/30 13:26:52 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_fractal.h"

double	ft_calsinx(double a, double b, double x)
{
	double	result;

	result = (x * sin(a) * cosh(b)) + (x * cos(a) * sinh(b));
	return (result);
}

double	ft_calsiny(double a, double b, double y)
{
	double	result;

	result = (y * sin(a) * cosh(b)) + (y * cos(a) * sinh(b));
	return (result);
}

double	ft_calinx(double a, double b, double x, double y)
{
	double	result;

	result = (a * a) - (b * b) + (x / ((x * x) + (y * y)));
	return (result);
}

double	ft_caliny(double a, double b, double x, double y)
{
	double	result;

	result = (2 * a * b) - (y / ((x * x) + (y * y)));
	return (result);
}
