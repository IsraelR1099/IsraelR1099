/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_memchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:05:45 by irifarac          #+#    #+#             */
/*   Updated: 2022/01/30 20:39:16 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tc.h"
#include <string.h>


int	main(void)
{
	char	ptr[] = "This is a random string";
	char	ch = 'r';
	char	ptr1[] = "This is a random string";
	char	ch1 = 'r';
	char	s[] = {0, 1, 2, 3, 4, 5};
	char	number = '2';

	if (memchr(ptr, ch, 15))
			printf("%c esta presente en %s\n", ch, ptr);
	else
		printf("No esta presente\n");
	if (ft_memchr(ptr1, ch1, 15))
		printf("%c esta presente en %s\n", ch1, ptr1);
	else
		printf("No esta presente %c\n", ch1);
	if (ft_memchr(s, 2 + 256, 3))
		printf(" esta presente en %s\n", s);
	else
		printf("No esta presente %c\n", number);
	if (memchr(s, 2 + 256, 3))
		printf(" esta presente en %s\n", s);
	else
		printf("No esta presente %c\n", number);
	if (memchr("bonjourno", 'n', 2))
		printf("%sCon memchr esta presente en \n%s",TC_RED, TC_NRM);
	else
		printf("%sNo esta presente \n%s", TC_RED, TC_NRM);
	if (ft_memchr("bonjourno", 'n', 2))
		printf("%sCon ft_memchr esta presente en \n%s",TC_GRN, TC_NRM);
	else
		printf("%sNo esta presente \n%s",TC_GRN, TC_NRM);


	return (0);
	}
