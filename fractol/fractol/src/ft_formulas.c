/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formulas.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:27:42 by irifarac          #+#    #+#             */
/*   Updated: 2022/05/10 13:37:13 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_fractal.h"

double	ft_calcx(double a, double b, double x)
{
	double	result;

	result = (a * a) - (b * b) + x;
	return (result);
}

double	ft_calcy(double a, double b, double y)
{
	double	result;

	result = (2 * a * b) + y;
	return (result);
}
