/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:47:39 by irifarac          #+#    #+#             */
/*   Updated: 2022/02/15 11:59:07 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "tc.h"

int	main(void)
{
	int		fd;
	char	*ptr;

	fd = open("hola.txt", O_RDONLY);
	if (fd == -1)
		printf("%sError al abrir el archivo.\n%s", TC_RED, TC_NRM);
	else
	{
		ptr = get_next_line(fd);
		ft_putstr(ptr);
		close(fd);
	}
	printf("fd es '%d'\n", fd);
	return (0);
}
