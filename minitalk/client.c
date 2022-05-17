/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:22:53 by irifarac          #+#    #+#             */
/*   Updated: 2022/05/17 13:55:44 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	sign_handler2(int pid_server, char c)
{
	int	bit;
	int	position;

	position = 0;
	bit = 8;
	printf("c dentro es %c\n", c);
	while (bit--)
	{
		if ( c >> bit & 1)
			kill(pid_server, SIGUSR1);
		else
			kill(pid_server, SIGUSR2);
		usleep(500);
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
	int					position;

	(void)counter;
	printf("hola\n");
	pid2 = ft_atoi(str[1]);
	printf("pid en cliente es %d\n", pid2);
//	act2.sa_handler = sign_handler2;
//	act2.sa_flags = SA_SIGINFO;
//	sigemptyset(&act2.sa_mask);
//	signal(SIGUSR1, sign_handler2);
//	signal(SIGUSR2, sign_handler2);
	position = 0;
	while (*(*(str + 2) + position))
	{
		sign_handler2(pid2, *(*(str + 2) + position));
		printf("c es %c\n", *(*(str + 2) + position));
		position++;
	}
//	kill(pid2, SIGUSR1);
	return (0);
}
