/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:30:38 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/16 20:12:32 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_handler(int signo)
{
	printf("chield died with signo:%d\n", signo);
}

void	ft_info_handler(int signo, siginfo_t *info, void *context)
{
	int	child;
	int	state;
	int	status;
	int	signo2;
	pid_t	pid;

	(void)context;
	state = 0;
	child = info->si_pid;
	status = info->si_status;
	signo2 = info->si_signo;
	pid = info->si_pid;
	printf("pid: %d status: %d y signo: %d, pid info: %d\n", child, status,
	signo2, pid);
	if (signo == SIGCHLD)
	{
		printf("child died\n");
		state = 1;
	printf("state %d\n", state);
	}
	else
		printf("child alive\n");
	printf("state2 %d\n", state);
	if (state == 0 && pid != 0)
	{
		if (signo == SIGINT)
		{
			printf("\n");
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
		}
	}
}
