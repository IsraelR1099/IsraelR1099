/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_strrchr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:28:50 by irifarac          #+#    #+#             */
/*   Updated: 2022/01/28 14:55:35 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tc.h"

int	main(void)
{
	char	s[] = "tripouille";

	printf("%sEncontrado %s \n%s", TC_GRN, ft_strrchr(s, 't' + 256), TC_NRM);

	return (0);
}
