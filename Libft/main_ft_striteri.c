/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_striteri.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:29:27 by irifarac          #+#    #+#             */
/*   Updated: 2022/02/01 13:36:20 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tc.h"

void	iter(unsigned int i, char *s)
{
	*s += i;
}

int	main(void)
{
	char	s[] = "0000000000";

	ft_striteri(s, iter);
	printf("%sLa string es '%s'\n%s", TC_GRN, s, TC_NRM);

	return (0);
}
