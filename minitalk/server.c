/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 11:35:58 by irifarac          #+#    #+#             */
/*   Updated: 2022/05/18 22:50:34 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	struct sigaction	act;
	int					pid;
	char				*new_pid;

	pid = getpid();
	act.sa_handler = &sign_handler_server;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_RESTART;
	new_pid = ft_itoa(pid);
	write(1, "PID:", 4);
	write(1, new_pid, ft_strlen(new_pid));
	write(1, "\n", 1);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
}

void	sign_handler_server(int sign)
{
	static unsigned char	bits = 0;
	static int				byte = 0;

	bits = bits << 1;
	if (sign == SIGUSR1)
		bits = bits | 1;
	byte++;
	if (byte == 8)
	{
		if (bits == 0x00)
		{
		//	kill(client_pid, SIGUSR1);
			write(1, "final", 5);
			byte = 0;
			bits = 0;
		}
		else
		{
			write(1, &bits, 1);
			byte = 0;
			bits = 0;
		}
	}
}
