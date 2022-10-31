/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:30:38 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/31 09:50:54 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../Libft/libft.h"

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
//	int	child;
	static int	state = 0;
//	char	stat;
//	int	status;
//	int	signo2;
//	pid_t	pid;

	(void)context;
	(void)info;
	//printf("entro en info handler\n");
//	child = info->si_pid;
//	status = info->si_status;
//	signo2 = info->si_signo;
//	pid = info->si_pid;
//	printf("pid: %d status: %d y signo: %d, pid info: %d\n", child, status,	signo2, pid);
//	printf("signo %d\n", signo2);
	if (signo == SIGUSR1)
	{
//		printf("estoy en child\n");
		state = 1;
			//	printf("state es %d\n", state);
	}
//	printf("child %d\n", child);
//	printf("state despues es %d\n", state);
	if (signo == SIGUSR2)
	{
//		write(1, "hola signals\n", ft_strlen("hola signals\n"));
		state = 0;
	}
//	stat = state + 48;
//	write(1, "state is:", ft_strlen("state is:"));
//	write(1, &stat, 1);
//	printf("antes state %d child %d\n", state, child);
	if (state == 0)
	{
		if (signo == SIGINT)
		{
			write(2, "\n", 1);
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
		}
		else if (signo == SIGQUIT)
		{
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();

		}

	}
	if (state == 1)
	{
		if (signo == SIGQUIT)
		{
			write(2, "Quit: 3\n", 8);
			kill(0, SIGINT);
		}
	/*	else if (signo == SIGINT)
		{
			state = 0;
			write(1, "\n", 1);
			rl_on_new_line();
			rl_replace_line("", 0);
		}*/

	}

}
