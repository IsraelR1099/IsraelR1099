/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 11:35:58 by irifarac          #+#    #+#             */
/*   Updated: 2022/05/17 13:55:46 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
//#include "ft_printf/includes/ft_printf.h"

int	ft_strlen(char *str)
{
	int	position;

	position = 0;
	while (*(str + position))
		position++;
	return (position);
}

void	sign_handler(int sign)
{
//	unsigned char	bits;
//	int				byte;
	//char	*str = "mensaje recibido de SIGUSR1";
	//char	*str2 = "mensaje recibido de SIGUSR2";

//	bits = 0;
//	byte = 8;
//	while (byte--)
//	{
		//Valor 0
/*		if (sign == SIGUSR1)
		{
			write(1, "0", 1);
		//	bits = bits >> byte | 1;
		}
		else if (sign == SIGUSR2)
		{
			write(1, "1", 1);
		//	bits = bits << 1;
		}
//	}
	//write(1, &bits, 1);*/
	static int	cont = 0;
	static char	letter = 0;

	if (sign == SIGUSR1)
		write(1, "1", 1);
//		letter = letter | 1 << cont;
	else
		write(1, "0", 1);		
	cont++;
	if (cont == 8)
	{
		write(1, &letter, 1);
		cont = 0;
		letter = 0;
	}
}

int	main(void)
{
	int	pid = getpid();
	struct sigaction	act;

	act.sa_handler = &sign_handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_RESTART;
	printf("PID: %d\n", pid);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
}
