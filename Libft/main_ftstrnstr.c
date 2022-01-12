/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ftstrnstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:04:05 by irifarac          #+#    #+#             */
/*   Updated: 2022/01/12 13:33:04 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strnstr(const char *dest, const char *src, size_t count);

int	main(void)
{
	char	test1[30] = "Thisa is a simple example";
	char	test2[10] = "a";
	char	*resultado;
	char	*resultado2;

	resultado =	strnstr(test1, test2, 3);
	printf("El resultado es: %s\n", resultado);

	resultado2 = ft_strnstr(test1, test2, 3);
	printf("El resultado es: %s\n", resultado2);

	return (0);
}

