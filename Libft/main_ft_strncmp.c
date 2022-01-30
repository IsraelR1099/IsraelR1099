/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_strncmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 18:00:25 by irifarac          #+#    #+#             */
/*   Updated: 2022/01/30 20:16:11 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tc.h"
#include <string.h>

int	main(void)
{
	int	result;
	int	result2;

	result = ft_strncmp("abcdefgh", "abcdefgxyz", 4);
	result2 = strncmp("abcdefgh", "abcdefgxyz", 4);

	printf("%sEl resultado es '%d'\n%s", TC_GRN, result, TC_NRM);
	printf("%sEl resultado es '%d'\n%s", TC_RED, result2, TC_NRM);

	return (0);
}
