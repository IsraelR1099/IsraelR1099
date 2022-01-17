/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ftstrnstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:04:05 by irifarac          #+#    #+#             */
/*   Updated: 2022/01/17 11:15:23 by irifarac         ###   ########.fr       */
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
	printf("\033[31;1;13mEl resultado con strnstr es: %s\n\033[0m", resultado);

	resultado2 = ft_strnstr(test1, test2, 3);
	printf("\033[32;1;13mEl resultado con ft_strnstr es: %s\n\033[0m", resultado2);



	return (0);
}

