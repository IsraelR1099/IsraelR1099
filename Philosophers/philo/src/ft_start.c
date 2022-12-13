/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:19:48 by irifarac          #+#    #+#             */
/*   Updated: 2022/12/13 17:41:07 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	printids(const char *s)
{
	pid_t		pid;
	pthread_t	tid;

	pid = getpid();
	tid = pthread_self();
	printf("%s pid %lu tid %lu (0x%lx)\n", s, (unsigned long)pid, (unsigned long)tid, (unsigned long)tid);
}

void	ft_set_time(t_info *info, int nbr)
{
	int				i;
	struct timeval	time;

	i = -1;
	gettimeofday(&time, NULL);
	while (++i < nbr)
	{
		info->time_start = ft_mili(time);
		info->philo[i].last_eat = ft_mili(time);
	}
}

void	*ft_action(void *arg)
{
	t_philo			*philo;

	philo = (t_philo *)arg;
	if ((philo->id % 2) == 0)
		usleep(15000);
	ft_routine(philo);
	return (NULL);
}

void	ft_start(t_info *info, int nbr)
{
	int	i;

	i = -1;
	//printids("main thread: ");
	while (++i < nbr)
	{
		if (pthread_mutex_init(&(info->philo[i].left_fork), NULL) != 0)
			ft_message("Mutex init error\n", -1, info);
		if (i == (nbr - 1))
			info->philo[i].right_fork = &(info->philo[0].left_fork);
		else
			info->philo[i].right_fork = &(info->philo[(i + 1)].left_fork);
//			info->philo[i].right_fork = &(info->philo[(i + 1) % nbr].left_fork);
	}
	i = -1;
	ft_set_time(info, nbr);
	while (++i < nbr)
	{
		if (pthread_create(&info->philo[i].tid, NULL, ft_action, &(info->philo[i])) != 0)
			ft_message("Can't create the thread", -1, info);
	}
	i = -1;
	while (++i < nbr)
	{
		if (pthread_join(info->philo[i].tid, NULL) != 0)
			ft_message("Can't join with thread\n", -1, info);
	}
//	printids("thread: ");
}
