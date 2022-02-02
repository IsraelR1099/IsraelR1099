/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_putstr_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 20:39:02 by irifarac          #+#    #+#             */
/*   Updated: 2022/02/02 09:34:59 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tc.h"

int	main(void)
{
	int	fd;
	char	*s = "hola";

	fd = open("hola.txt", O_RDWR);
	if (fd == -1)
		printf("%sError al abrir el archivo\n%s", TC_RED, TC_NRM);
	else
	{
		ft_putstr_fd(s, fd);
		close(fd);
	}
	return (0);
}
