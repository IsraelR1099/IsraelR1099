/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:47:39 by irifarac          #+#    #+#             */
/*   Updated: 2022/02/28 09:45:18 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "tc.h"

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

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
		ptr2 = get_next_line(fd);
		printf("%s/////\n%s", TC_RED, TC_NRM);
		ft_putstr(ptr2);
		ptr3 = get_next_line(fd);
		printf("%s/////\n%s", TC_RED, TC_NRM);
		ft_putstr(ptr3);
		ptr4 = get_next_line(fd);
		printf("%s/////\n%s", TC_RED, TC_NRM);
		ft_putstr(ptr4);
		//printf("\n");
		close(fd);
		//printf("%----------------------%s\n", TC_GRN, TC_NRM);
	}
	return (0);
}
