/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formulas.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:27:42 by irifarac          #+#    #+#             */
/*   Updated: 2022/04/28 12:23:50 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_fractal.h"

double	ft_calcx(double a, double b, double x)
{
	double	result;

	result = pow(a, 2) - pow(b, 2) + x;
	return (result);
}

double	ft_calcy(double a, double b, double y)
{
	double	result;

	result = (2 * a * b) + y;
	return (result);
}
