/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:21:12 by irifarac          #+#    #+#             */
/*   Updated: 2022/05/25 12:02:08 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_fractal.h"

void	ft_show_options(void)
{
	printf("%s------------HELP-------------\n%s", TC_RED, TC_NRM);
	printf("%sESC, + max iter, - less iter\n%s", TC_BLU, TC_NRM);
	printf("%sFlechas: mover el fractal\n%s", TC_BLU, TC_NRM);
	printf("%sTecla 'r': restablecer valores\n%s", TC_BLU, TC_NRM);
	printf("%sTecla 'c': cambiar colores\n%s", TC_BLU, TC_NRM);
	printf("%s-----------------------------\n%s", TC_RED, TC_NRM);
	printf("%sUtilizar los parametros siguientes:\n%s", TC_GRN, TC_NRM);
	printf("%s1. Mandelbrot\n%s", TC_CYN, TC_NRM);
	printf("%s2. Julia\n%s", TC_RED, TC_NRM);
	printf("%s3. Julia [parametros]\n%s", TC_RED, TC_NRM);
}
