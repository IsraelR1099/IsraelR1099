/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:30:38 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/22 12:03:24 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_handler(int signo, siginfo_t *info, void *context)
{
	printf("entro en handler\n");
	if (signo == SIGINT)
	{
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	(void)context;
	(void)info;
	printf("chield died with signo:%d\n", signo);
}

void	ft_info_handler(int signo, siginfo_t *info, void *context)
{
	int	child;
	static int	state;
	int	status;
	int	signo2;
	pid_t	pid;

	(void)context;
	//printf("entro en info handler\n");
	child = info->si_pid;
	status = info->si_status;
	signo2 = info->si_signo;
	pid = info->si_pid;
//	printf("pid: %d status: %d y signo: %d, pid info: %d\n", child, status,	signo2, pid);
	if (signo == SIGTTIN)
	{
		exit(1);
		printf("hola\n");
	}
	if (signo == SIGTTOU)
	{
		exit(1);
		printf("hola2\n");
	}

	if (signo == SIGUSR1)
	{
//		printf("estoy en child\n");
		state = 1;
		if (signo == SIGQUIT)
		{
			rl_replace_line("", 0);
			rl_redisplay();
			write(2, "Quit\n", 5);
		}
		//	printf("state es %d\n", state);
	}
//	printf("state despues es %d\n", state);
	if (signo == SIGUSR2)
	{
		state = 0;
	}
//	printf("antes state %d\n", state);
	if (state == 0)
	{
	//	write(1, "entro\n", 6);
		if (signo == SIGINT)
		{
			printf("\n");
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
		}

	}
}
