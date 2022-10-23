/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:30:38 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/23 21:29:33 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <signal.h>
#include <termios.h>

extern int g_exit;

void	ft_termios(void)
{
	struct termios	term;
	struct termios	save_termios;

	if (isatty(STDIN_FILENO) == 0)
		ft_error("this fd is not a tty", 130);
	if (tcgetattr(STDIN_FILENO, &term) < 0)
		ft_error("get attributes error", 130);
	save_termios = term;
	term.c_lflag &= ~(ECHOCTL);
	if (tcsetattr(STDIN_FILENO, TCSADRAIN, &term) < 0)
		ft_error("set attributes error", 130);
	if (term.c_lflag & (ECHOCTL))
	{
		tcsetattr(STDIN_FILENO, TCSAFLUSH, &save_termios);
		ft_error("attributes wrongly set", 130);
	}
}

void	ft_signals(void)
{

	struct sigaction	act;
	struct sigaction	oact;

	act.sa_handler = SIG_DFL;
//	act.sa_mask = 0;
	ft_memset(&act, 0, sizeof(act));
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_RESTART | SA_SIGINFO; //| SA_NOCLDWAIT;
	act.sa_sigaction = ft_info_handler;
	if (sigaction(SIGINT, &act, &oact) < 0)
		ft_error("sigaction error", 130);
	if (sigaction(SIGQUIT, &act, &oact) < 0)
		ft_error("sigaction error", 130);
	if (sigaction(SIGUSR1, &act, &oact) < 0)
		ft_error("sigaction error", 130);
	if (sigaction(SIGUSR2, &act, &oact) < 0)
		ft_error("sigaction error", 130);
	signal(SIGSEGV, ft_ssh);
}

void	ft_handler(int signo)
{
	printf("chield died with signo:%d\n", signo);
}

void	ft_info_handler(int signo, siginfo_t *info, void *context)
{
	int			status;
 //	int			child;
	static int	state;

	(void)context;
	status = info->si_status;
//	child = info->si_pid;
//	printf("child: %d\n", child);
//	printf("si_pid: %d\n", info->si_pid);
	// if (info->si_status)
//	printf("status of %d: %d\n", child, info->si_status);
	if (g_exit < 256)
		g_exit = status;
	// printf("status: %d\n", info->si_status);
	// printf("signo: %d AND SIGCHLD: %d\n", signo, SIGCHLD);
	if (signo == SIGUSR1)
		state = 1;
	if (signo == SIGUSR2)
		state = 0;
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
	}
}
