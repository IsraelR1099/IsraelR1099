/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_strrchr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:28:50 by irifarac          #+#    #+#             */
/*   Updated: 2022/01/30 20:51:32 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tc.h"
#include <string.h>

int	main(void)
{
	char	s[] = "tripouille";

	if (strrchr(s, 't' + 256))
		printf("%sEncontrado \n%s", TC_RED, TC_NRM);
	else
		printf("%sNo encontrado \n%s", TC_RED, TC_NRM);
	if (ft_strrchr(s, 't' + 256))
		printf("%sEncontrado \n%s", TC_GRN, TC_NRM);
	else
		printf("%sNo encontrado \n%s", TC_GRN, TC_NRM);

	return (0);
}
