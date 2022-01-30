/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_strnstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:04:05 by irifarac          #+#    #+#             */
/*   Updated: 2022/01/30 14:07:51 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tc.h"
#include <string.h>
#include <stdio.h>

char *strnstr(const char *s, const char *find, size_t slen);

int	main(void)
{
	char	test1[30] = "This a is a simple example";
	char	test2[10] = "a";
	char	*resultado;
	char	*resultado2;
	char	*resultado3;
	char	*resultado4;
	char	haystack[30] = "aaabcabcd";

	resultado = strnstr(test1, test2, 10);
	printf("\033[31;1;13mEl resultado con strnstr es: %s\n\033[0m", resultado);

	resultado2 = ft_strnstr(test1, test2, 10);
	printf("\033[32;1;13mEl resultado con ft_strnstr es: %s\n\033[0m", resultado2);
	

	resultado3 = ft_strnstr(haystack, "abcd", 9);
	printf("%sEl resultado con ft_strnstr es %s\n%s", TC_GRN, resultado3, TC_NRM);

	resultado4 = strnstr(haystack, "abcd", 9);
	printf("%sEl resultado con strnstr es %s\n%s", TC_GRN, resultado4, TC_NRM);

	return (0);
}

