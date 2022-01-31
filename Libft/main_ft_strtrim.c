/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_strtrim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 09:52:06 by irifarac          #+#    #+#             */
/*   Updated: 2022/01/31 13:22:58 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tc.h"

int	main(void)
{
	char	s1[] = "papapaHello Worldapap";
	char	*pch;
	char	seit[] = "pa";
	int	counter;
	int	lenS1;
	char	*ret;
	char	*set = " \n\t";
	char	*test1 = "  \t \n\n \t\t  \n\n\nHello \t  Please\n Trim	me !\n	\n \n \t\t\n  ";
	
	printf("%sarray original '%s'\n%s",TC_RED, s1, TC_NRM);
	lenS1 = ft_strlen(s1);
	pch = ft_strnstr(s1, "ab", lenS1); 
	printf("%sEl resultado es: %s\n%s", TC_GRN, ft_strtrim(s1, "pa"), TC_NRM);
	counter = 0;
	while (pch != NULL)
	{
		//printf("Found at %ld\n", pch - s1 + 1);
		counter++;
		pch = ft_strnstr(pch + 1, "ab", 10);
	}
	printf("Numero de veces %d\n", counter);
	printf("%sArray original %s\n%s", TC_GRN, test1, TC_NRM);
	
	int	lens1;
	int	realens1;
	int	position = 0;

	lens1 = ft_strlen((char *)test1);
	realens1 = lens1;
	printf("Lens1 es %d\n", lens1);
	while (lens1 >= 0 && ft_strchr((char *)set, test1[lens1]) != NULL)
	{
		lens1--;
	}
	while ((ft_strchr((char *)set, test1[position]) != NULL))
			position++;
	int	lens12;
	int	counter2;

	counter2 = 0;
	lens12 = ft_strlen((char *)s1) - 1;
	while (ft_strchr((char *)seit, s1[lens12]) != NULL)
	{
		lens12--;
		counter2++;
	}
	printf("%sEl len es %d\n%s", TC_GRN, ft_strlen(s1), TC_NRM); 
	printf("%sEl numero es %d y counter %d\n%s", TC_GRN, lens12, counter2, TC_NRM);
	realens1 = realens1 - lens1;
	printf("Lens1 es %d\n", lens1);
	printf("position es %d\n", position);
	printf("%sArray casi original %s\n%s", TC_GRN, test1 , TC_NRM);
	ret = ft_strtrim("abcdba", "acb");
	printf("%sEl resultado con ft_strtrim es '%s'\n%s", TC_GRN, ret, TC_NRM);
	


	return (0);
}
