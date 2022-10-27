/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:17:47 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/27 20:43:55 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../Libft/libft.h"

static void	ft_signals(void)
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
	if (sigaction(SIGTTOU, &act, &oact) < 0)
		ft_error("sigaction error", 130);
	if (sigaction(SIGTTIN, &act, &oact) < 0)
		ft_error("sigaction error", 130);
}

static void	ft_termios(void)
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

static int	getcmd(char **buf, int size)
{
	ft_signals();
	ft_termios();
	(void)size;
	*buf = readline("$ ");
	printf("*buf %s\n", *buf);
	if (*buf && **buf)
		add_history(*buf);
	if ((ft_strncmp(*buf, "exit", ft_strlen(*buf)) == 0)
		|| !*buf)
	{
		printf("hola\n");
		rl_clear_history();
		free(*buf);
		return (-1);
	}
	return (0);
}

static void	ft_termios_child(void)
{
	struct termios	term;
	struct termios	save_termios;

	if (isatty(STDIN_FILENO) == 0)
		ft_error("this fd is not a tty", 130);
	if (tcgetattr(STDIN_FILENO, &term) < 0)
		ft_error("get attributes error", 130);
	save_termios = term;
	term.c_lflag |= (ECHOCTL);
	//backlash number is 92
	if (tcsetattr(STDIN_FILENO, TCSADRAIN, &term) < 0)
		ft_error("set attributes error", 130);
	if (term.c_lflag == (ECHOCTL))
	{
		tcsetattr(STDIN_FILENO, TCSAFLUSH, &save_termios);
		ft_error("attributes wrongly set", 130);
	}
}

int	main(void)
{
	static char	*buf;
	int			status;

//	buf = (char *)malloc(sizeof(char) * 100);
//	if (!buf)
//		exit (-1);
	while (getcmd(&buf, sizeof(buf)) >= 0)
	{
		if (buf[0] == 'c' && buf[1] == 'd' && buf[2] == ' ')
		{
			buf[ft_strlen(buf)] = 0;
			if (chdir(buf + 3) < 0)
				printf("cd: no such file or directory: %s\n", buf + 3);
			continue ;
		}
		if (fork1() == 0)
		{
			kill(0, SIGUSR1);
			ft_termios_child();
			ft_runcmd(parsecmd(buf));
			if (ft_strncmp("./minishell", buf, ft_strlen("./minishell") == 0))
				kill(0, SIGUSR2);
		}
		waitpid(0, &status, 0);
		kill(0, SIGUSR2);
	}
	return (0);
}
