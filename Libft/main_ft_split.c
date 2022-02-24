/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 10:06:34 by irifarac          #+#    #+#             */
/*   Updated: 2022/02/24 12:14:59 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tc.h"

size_t	allocation_size(void *ptr)
{
	return ((size_t *)ptr)[-1];
}

int	main(void)
{
	char	*str = "";
	char	*str2 = "  holaa   como   ";
	char	**ptr;
	char	**ptr2;




	ptr = ft_split(str, ' ');
	ptr2 = ft_split(str2, ' ');
	
	printf("El tamanio de malloc es: %lu\n", allocation_size(ptr));
	printf("%sresultado ptr 0 es '%s'\n%s", TC_GRN, ptr[0], TC_NRM);
//	printf("%sresultado ptr 1 es '%s'\n%s", TC_GRN, ptr[1], TC_NRM);
//	printf("%sresultado ptr 2 es '%s'\n%s", TC_GRN, ptr[2], TC_NRM);

//	printf("%sresultado ptr 2 es '%s'\n%s", TC_GRN, ptr[2], TC_NRM);
//	printf("%sresultado ptr 3 es '%s'\n%s", TC_GRN, ptr[3], TC_NRM);
//	printf("%sresultado ptr 4 es '%s'\n%s", TC_GRN, ptr[4], TC_NRM);
//	printf("%sresultado ptr 5 es '%s'\n%s", TC_GRN, ptr[5], TC_NRM);
//	printf("%sresultado ptr 6 es '%s'\n%s", TC_GRN, ptr[6], TC_NRM)
//	;
//	printf("%sresultado ptr2 0 es '%s'\n%s", TC_GRN, ptr2[0], TC_NRM);
//	printf("%sresultado ptr2 1 es '%s'\n%s", TC_GRN, ptr2[1], TC_NRM);
//	free(ptr2);
	free(ptr);

	return (0);
}
