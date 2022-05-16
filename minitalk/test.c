/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 12:44:18 by irifarac          #+#    #+#             */
/*   Updated: 2022/05/16 13:18:31 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>

int volatile	count;

void	handler(int sig)
{
	printf("signal %d y count %d\n", sig, count);
	count++;
}

int	main(void)
{
	struct sigaction	sa;
	int					pid = getpid();

	printf("kill me %d, if you can\n", pid);
	sa.sa_handler = handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	
	if (sigaction(SIGINT, &sa, NULL) != 0)
		return (1);
	while (count != 4)
	{
		printf("i have had enough\n");
		sleep(1);
	}
	return (0);
}
