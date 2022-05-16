/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 11:35:58 by irifarac          #+#    #+#             */
/*   Updated: 2022/05/16 14:12:33 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_printf/includes/ft_printf.h"

void	sign_handler(int sign)
{
	printf("sign is %d\n", sign);
}

int	main(void)
{
//	int	i = 0;
	int	pid = getpid();
	//struct sigaction	act;

	//act.sa_handler = &sign_handler;
	//sigemptyset(&act.sa_mask);
	//act.sa_flags = SA_RESTART;
	printf("PID: %d\n", pid);
	//sigaction(SIGINT, &act, NULL);
	//kill(pid, SIGUSR1);
	while (1)
	{
		pause();
	}
	return (0);
}
