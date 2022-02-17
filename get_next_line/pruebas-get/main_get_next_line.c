/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:47:39 by irifarac          #+#    #+#             */
/*   Updated: 2022/02/17 13:44:12 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "tc.h"

int	main(void)
{
	int		fd;
	char	*ptr;
	//char	*ptr2;
//	char	*ptr3;

	fd = open("hola.txt", O_RDONLY);
	if (fd == -1)
		printf("%sError al abrir el archivo.\n%s", TC_RED, TC_NRM);
	else
	{
		printf("%s----------------------%s\n", TC_GRN, TC_NRM);
		ptr = get_next_line(fd);
		ft_putstr(ptr);
		printf("\n");
		//ptr2 = get_next_line(fd);
		//ft_putstr(ptr2);
		//printf("\n");
		//ptr3 = get_next_line(fd);
		//ft_putstr(ptr3);
		//printf("\n");
		close(fd);
		printf("%s\n----------------------%s\n", TC_GRN, TC_NRM);
	}
	printf("fd es '%d'\n", fd);
	return (0);
}
