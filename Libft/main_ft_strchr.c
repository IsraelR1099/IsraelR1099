/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_strchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:05:25 by irifarac          #+#    #+#             */
/*   Updated: 2022/01/18 14:35:34 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	main(void)
{
	char	s[] = "tripouille";
	char	*pch;
	printf("Looking for the '0' character in \"%s\"...\n", s);
	pch = strchr(s, 0);
	while (pch!=NULL)
	{
		printf("Found at %ld\n", pch-s+1);
		pch = strchr(pch+1, '0');
	}

	printf("Looking for the '0' character in \"%s\"...\n", s);
	pch = strchr(s, 0);
	while (pch!=NULL)
	{
		printf("Found at %ld\n", pch-s+1);
		pch = ft_strchr(pch+1, '0');
	}
	return (0);
}
