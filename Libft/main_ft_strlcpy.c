/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_strlcpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 13:57:41 by irifarac          #+#    #+#             */
/*   Updated: 2022/01/28 14:28:34 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "libft.h"
#include "tc.h"


int	main(void)
{
	char	destination[5];
	char	*source = "LARGE";
	char	destination2[5];
	char	*source2 = "LARGE";
	int	result;
	int	result2;
	int	result3;
	char	src[] = "coucou";
	char	dest[10]; ft_memset(dest, 'A', 10);

	result = strlcpy(destination, source, sizeof(destination));
	printf("\033[31;1;13mCon strlcpy resultado: %s y longitud %d\n\033[0m", destination, result);

	result2 = ft_strlcpy(destination2, source2, sizeof(destination2));
	printf("\033[32;1;13mCon ft_strlcpy resultado: %s y longitud %d\n\033[0m", destination2, result2);

	result3 = ft_strlcpy(dest, src, 0);
	printf("%sEl resultado con ft_strlcpy es '%s' y longitud '%d'\n%s", TC_GRN, dest, result3, TC_NRM);

	return (0);
}


