/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_putchar_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 18:04:06 by irifarac          #+#    #+#             */
/*   Updated: 2022/02/01 18:23:17 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	int	fd;
	char	c;

	fd = open("hola.txt", O_RDWR);
	if (fd == -1)
		printf("Error al abrir el archivod");
	else
	{
		c = 'p';
		ft_putchar_fd(c, fd);
		close(fd);
	}
}

