/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_strmapi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:40:49 by irifarac          #+#    #+#             */
/*   Updated: 2022/02/01 13:05:56 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tc.h"

char	prueba(unsigned int i, char c)
{
	return (i + c);
}

int	main(void)
{
	char	*str;
	int	len;
	char *s = "1234";

	str = ft_strmapi("1234",prueba);
	len = ft_strlen(s);

	printf("%sLen es '%d'\n%s", TC_GRN, len, TC_NRM);
	printf("%sEl resultado es '%s'\n%s", TC_GRN, str, TC_NRM);
	return (0);
}
