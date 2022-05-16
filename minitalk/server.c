/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 11:35:58 by irifarac          #+#    #+#             */
/*   Updated: 2022/05/16 20:38:52 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
//#include "ft_printf/includes/ft_printf.h"

void	sign_handler(int sign)
{
	if (sign == SIGUSR1)
		write(1, "h", 1);
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
	kill(pid, SIGUSR1);
	while (1)
	{
		pause();
	}
	return (0);
}
