/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_putnbr_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:09:45 by irifarac          #+#    #+#             */
/*   Updated: 2022/02/02 13:26:28 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tc.h"

int	main(void)
{
	int	fd;
	int	number = 1234;



	fd = open("hola.tx", O_RDWR | O_CREAT, 0777);
	if (fd == -1)
		printf("%sError al abrir el archivo\n%s", TC_RED, TC_NRM);
	else
	{
		ft_putnbr_fd(number, fd);
		close(fd);
	}
	return (0);
}

