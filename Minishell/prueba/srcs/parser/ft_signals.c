/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:30:38 by irifarac          #+#    #+#             */
/*   Updated: 2022/09/28 14:11:40 by irifarac         ###   ########.fr       */
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
	int	status;

	(void)context;
	child = info->si_pid;
	status = info->si_status;
	printf("pid: %d status: %d\n", child, status);
	if (signo == SIGCHLD)
	{
		//printf("child died\n");
	}
	if (signo == SIGINT)
	{
		//printf("sigint %s\n", rl_line_buffer);
		//if (ioctl(STDIN_FILENO, TIOCSTI, "\n") < 0)
		//	ft_error("ioctl erro", 130);
		//printf("state %lu\n", rl_readline_state);
		write(2, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		//if (RL_STATE_REDISPLAYING)
		//	printf("true\n");
	}
}
