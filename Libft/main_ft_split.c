/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 10:06:34 by irifarac          #+#    #+#             */
/*   Updated: 2022/02/07 13:51:22 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tc.h"


int	main(void)
{
	char	*str = "hello!";
	char	**ptr;

	ptr = ft_split(str, ' ');

	printf("%sresultado ptr 0 es '%s'\n%s", TC_GRN, ptr[0], TC_NRM);
	printf("%sresultado ptr 1 es '%s'\n%s", TC_GRN, ptr[1], TC_NRM);
	printf("%sresultado ptr 2 es '%s'\n%s", TC_GRN, ptr[2], TC_NRM);
	printf("%sresultado ptr 3 es '%s'\n%s", TC_GRN, ptr[3], TC_NRM);
	printf("%sresultado ptr 4 es '%s'\n%s", TC_GRN, ptr[4], TC_NRM);
	printf("%sresultado ptr 5 es '%s'\n%s", TC_GRN, ptr[5], TC_NRM);
//	printf("%sresultado ptr 6 es '%s'\n%s", TC_GRN, ptr[6], TC_NRM);
	free(ptr);

	return (0);
}
