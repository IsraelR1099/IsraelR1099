/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:16:42 by irifarac          #+#    #+#             */
/*   Updated: 2022/01/17 14:22:20 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strdup(const char *s1);

int	main(void)
{
	char	source[] = "GeeksForGeeks";
	char	*target = strdup(source);
	char	source2[] = "GeeksForGeeks";
	char	*target2 = ft_strdup(source2);

	printf("\033[31;1;13mstrdup -> El origen es '%s' y el destino es '%s' \n\033[0m", source, target);

	printf("\033[32;1;13mft_strdup -> El origen es '%s' y el destino es '%s' \n\033[0m", source2, target2);
	return (0);
}
