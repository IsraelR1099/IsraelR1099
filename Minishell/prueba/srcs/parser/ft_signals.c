/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:30:38 by irifarac          #+#    #+#             */
/*   Updated: 2022/09/26 13:54:40 by irifarac         ###   ########.fr       */
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
	int	flag;

	(void)context;
	child = info->si_pid;
	status = info->si_status;
	printf("pid: %d status: %d\n", child, status);
	flag = 1;
	if (signo == SIGCHLD)
	{
		flag = 0;
		printf("child died\n");
	}
	if (signo == SIGINT)
	{
		printf("sigint\n");
	}
}
