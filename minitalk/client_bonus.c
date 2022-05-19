/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:22:53 by irifarac          #+#    #+#             */
/*   Updated: 2022/05/19 10:57:16 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int counter, char **str)
{
	int	pid_server;
	int	position;

	signal(SIGUSR1, sign);
	if (counter == 3)
	{
		pid_server = ft_atoi(str[1]);
		position = 0;
		while (*(*(str + 2) + position))
		{
			sign_handler(pid_server, *(*(str + 2) + position));
			position++;
		}
	}
	else
		ft_putstr("Numero de argumentos incorrecto\n");
	return (0);
}

void	sign_handler(int pid_server, char c)
{
	int	bit;
	int	position;

	position = 0;
	bit = 8;
	while (bit--)
	{
		if (c >> bit & 1)
			kill(pid_server, SIGUSR1);
		else
			kill(pid_server, SIGUSR2);
		usleep(250);
	}
}

void	sign(int sig)
{
	(void)sig;
	ft_putstr("Signal receipt\n");
}
