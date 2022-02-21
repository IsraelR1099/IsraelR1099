/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:47:39 by irifarac          #+#    #+#             */
/*   Updated: 2022/02/21 12:42:35 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "tc.h"

int	main(void)
{
	int		fd;
	char	*ptr;
	char	*ptr2;
	char	*ptr3;
	char	*ptr4;

	fd = open("hola.txt", O_RDONLY);
	if (fd == -1)
		printf("%sError al abrir el archivo.\n%s", TC_RED, TC_NRM);
	else
	{
		printf("%s----------------------%s\n", TC_GRN, TC_NRM);
		ptr = get_next_line(fd);
		printf("%s/////\n%s", TC_RED, TC_NRM);
		ft_putstr(ptr);
		printf("\n");
		ptr2 = get_next_line(fd);
		printf("%s/////\n%s", TC_RED, TC_NRM);
		ft_putstr(ptr2);
		printf("\n");
		ptr3 = get_next_line(fd);
		printf("ptr3 es\n");
		printf("%s/////\n%s", TC_RED, TC_NRM);
		ft_putstr(ptr3);
		printf("\n");
		//ptr4 = get_next_line(fd);
		//printf("%s/////\n%s", TC_RED, TC_NRM);
		//ft_putstr(ptr4);
		//printf("\n");
		close(fd);
		printf("%s\n----------------------%s\n", TC_GRN, TC_NRM);
	}
	return (0);
}
