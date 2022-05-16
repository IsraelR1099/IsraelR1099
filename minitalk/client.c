/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:22:53 by irifarac          #+#    #+#             */
/*   Updated: 2022/05/16 20:54:48 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	sign_handler2(int pid_server, char *str)
{
	int	bit;
	int	position;

	position = 0;
	while (*(str + position))
	{

		bit = 8;
		write(1, &*(str + position), 1);
		while (bit--)
		{
			if (*(str + position) >> bit & 1)
				kill(pid_server, SIGUSR1);
			else
				kill(pid_server, SIGUSR2);
		}
		position++;
	}
}

int	ft_atoi(char *str)
{
	int	nbr;
	int	sign;
	int	position;

	position = 0;
	sign = 1;
	nbr = 0;
	while (((str[position] >= 9) && (str[position] <= 13))
			|| (str[position] == 32))
		position++;
	if ((str[position] == '-') || (str[position] == '+'))
	{
		if (str[position] == '-')
			sign = -1;
		position++;
	}
	while ((str[position] >= 48) && (str[position] <= 57))
	{
		nbr = (nbr * 10) + str[position] - 48;
		position++;
	}
	return (sign * nbr);
}

int	main(int counter, char **str)
{
//	struct sigaction	act2;
	int					pid2;

	(void)counter;
	printf("hola\n");
	pid2 = ft_atoi(str[1]);
	printf("pid en cliente es %d\n", pid2);
//	act2.sa_handler = sign_handler2;
//	act2.sa_flags = SA_SIGINFO;
//	sigemptyset(&act2.sa_mask);
//	signal(SIGUSR1, sign_handler2);
//	signal(SIGUSR2, sign_handler2);
	sign_handler2(pid2, str[2]);
//	kill(pid2, SIGUSR1);
	return (0);
}
