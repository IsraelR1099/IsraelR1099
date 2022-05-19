/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 11:35:58 by irifarac          #+#    #+#             */
/*   Updated: 2022/05/19 11:33:32 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	struct sigaction	act;
	int					pid;
	char				*server_pid;

	pid = getpid();
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_RESTART;
	act.sa_sigaction = action;
	server_pid = ft_itoa(pid);
	write(1, "PID:", 4);
	write(1, server_pid, ft_strlen(server_pid));
	write(1, "\n", 1);
	free(server_pid);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
}

void	sign_handler_server_bonus(int sign, int client_pid)
{
	static unsigned char	bits;
	static int				byte;

	bits = bits << 1;
	if (sign == SIGUSR1)
		bits = bits | 1;
	byte++;
	if (byte == 8)
	{
		write(1, &bits, 1);
		byte = 0;
		bits = 0;
		kill(client_pid, SIGUSR1);
	}
}

void	action(int sig, siginfo_t *info, void *context)
{
	int	client_pid;

	(void)context;
	client_pid = info->si_pid;
	sign_handler_server_bonus(sig, client_pid);
}
