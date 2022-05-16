/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:22:53 by irifarac          #+#    #+#             */
/*   Updated: 2022/05/16 14:12:31 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	sign_handler2(int sign2)
{
	(void)sign2;
	write(1, "1", 1);
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
	struct sigaction	act2;
	int					pid2;

	(void)counter;
	printf("hola\n");
	pid2 = ft_atoi(str[1]);
	printf("pid en cliente es %d\n", pid2);
	act2.sa_handler = sign_handler2;
	act2.sa_flags = SA_SIGINFO;
	sigemptyset(&act2.sa_mask);
	sigaction(SIGUSR1, &act2, NULL);
	kill(pid2, SIGUSR1);
	return (0);
}
