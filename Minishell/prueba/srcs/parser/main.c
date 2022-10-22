/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:17:47 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/22 12:08:08 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../Libft/libft.h"

static int	getcmd(char **buf, int size)
{
	ft_memset(*buf, 0, size);
	*buf = readline("$ ");
	if (*buf && **buf)
		add_history(*buf);
	if (ft_strncmp(*buf, "exit", ft_strlen(*buf)) == 0)
	{
		free(*buf);
		return (-1);
	}
	return (0);
}

static void	ft_termios(void)
{
	struct termios	term;

	if (isatty(STDIN_FILENO) == 0)
		ft_error("this fd is not a tty", 130);
	if (tcgetattr(STDIN_FILENO, &term) < 0)
		ft_error("get attributes error", 130);
	term.c_lflag &= ~(ECHOCTL);
	if (tcsetattr(STDIN_FILENO, TCSADRAIN, &term) < 0)
		ft_error("set attributes error", 130);
	if (term.c_lflag & (ECHOCTL))
		ft_error("attributes wrongly set", 130);
}

static void	ft_signals(void)
{
	struct sigaction	act;
	struct sigaction	oact;

	act.sa_handler = SIG_DFL;
//	act.sa_mask = 0;
//	ft_memset(&act, 0, sizeof(act));
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_RESTART | SA_SIGINFO; //| SA_NOCLDWAIT;
	act.sa_sigaction = ft_info_handler;
//	if (sigaction(SIGCHLD, &act, &oact) < 0)
//		ft_error("sigaction error", 130);
	if (sigaction(SIGINT, &act, &oact) < 0)
		ft_error("sigaction error", 130);
//	if (sigaction(SIGQUIT, &act, &oact) < 0)
//		ft_error("sigaction error", 130);
	if (sigaction(SIGUSR1, &act, &oact) < 0)
		ft_error("sigaction error", 130);
	if (sigaction(SIGUSR2, &act, &oact) < 0)
		ft_error("sigaction error", 130);
	if (sigaction(SIGTTIN, &act, &oact) < 0)
		ft_error("sigaction error", 130);
	if (sigaction(SIGTTOU, &act, &oact) < 0)
		ft_error("sigaction error", 130);
}

int	main(void)
{
	static char	*buf;
	int			pid;

	buf = (char *)malloc(sizeof(char) * 100);
	if (!buf)
		exit (-1);
	ft_termios();
	ft_signals();
	while (getcmd(&buf, sizeof(buf)) >= 0)
	{
		if (buf[0] == 'c' && buf[1] == 'd' && buf[2] == ' ')
		{
			buf[ft_strlen(buf)] = 0;
			if (chdir(buf + 3) < 0)
				printf("cd: no such file or directory: %s\n", buf + 3);
			continue ;
		}
		if ((pid = fork1()) == 0)
		{
			if (kill(0, SIGUSR1) < 0)
				ft_error("kill error\n", 1);
			ft_runcmd(parsecmd(buf));
		}
		wait(0);
		if (kill(0, SIGUSR2) < 0)
			ft_error("kill error\n", 1);
	}
	return (0);
}
