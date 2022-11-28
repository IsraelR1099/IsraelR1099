/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:07:42 by irifarac          #+#    #+#             */
/*   Updated: 2022/11/23 14:01:27 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

pthread_t	ntid;

void	printids(const char *str)
{
	pid_t	pid;
	pthread_t	tid;

	pid = getpid();
	tid = pthread_self();
	printf("%s pid %lu tid %lu (0x%lx)\n", str, (unsigned long)pid, (unsigned long)tid, (unsigned long)tid);
}

void	*thr_fn(void *arg)
{
	printids("new thread: ");
	return ((void *)0);
}

int	main(void)
{
	int	err;

	err = pthread_create(&ntid, NULL, thr_fn, NULL);
	if (err != 0)
	{
		printf("can't create thread\n");
		exit(err);
	}
	printids("main thread:");
	sleep(1);
	return (0);
}
