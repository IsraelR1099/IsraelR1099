/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:22:53 by irifarac          #+#    #+#             */
/*   Updated: 2022/05/18 14:02:46 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int counter, char **str)
{
	int	pid_server;
	int	position;

	(void)counter;
	pid_server = ft_atoi(str[1]);
	position = 0;
	while (*(*(str + 2) + position))
	{
		sign_handler(pid_server, *(*(str + 2) + position));
		position++;
	}
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
