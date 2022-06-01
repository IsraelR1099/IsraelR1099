/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:21:12 by irifarac          #+#    #+#             */
/*   Updated: 2022/06/01 10:45:40 by irifarac         ###   ########.fr       */
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
	printf("%s2. Mandelbrot3\n%s", TC_CYN, TC_NRM);
	printf("%s3. Mandelbrot_inverse\n%s", TC_CYN, TC_NRM);
	printf("%s4. Mandelbrot_inverse3\n%s", TC_CYN, TC_NRM);
	printf("%s5. Julia\n%s", TC_RED, TC_NRM);
	printf("%s6. Julia [parametros]\n%s", TC_RED, TC_NRM);
	printf("%s6. Julia_glynn [parametros]\n%s", TC_RED, TC_NRM);
	printf("%s7. Julia3 [parametros]\n%s", TC_RED, TC_NRM);
	printf("%s--------Puntos de Julia ------\n%s", TC_GRN, TC_NRM);
	printf("%s0.285 - 0.01, -1.3 + 0.005, -0.72 - 0.196\n%s", TC_BLU, TC_NRM);
	printf("%s-0.4 + 0.6, -0.7589 - 0.0753, 0.3 + 0.01\n%s", TC_BLU, TC_NRM);
	printf("%s--------Puntos de Julia3 ------\n%s", TC_GRN, TC_NRM);
	printf("%s0.4 + 0.002275, -0.58384 - 0.27022\n%s", TC_BLU, TC_NRM);
}
