/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:19:48 by irifarac          #+#    #+#             */
/*   Updated: 2022/12/08 20:26:07 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_set_time(t_philo *philo, int nbr)
{
	int	i;

	i = -1;
	gettimeofday(&philo[0].time_start, NULL);
	while (++i < nbr)
		philo[i].time_start = philo[0].time_start;
}

void	*ft_action(void *arg)
{
	t_philo			*philo;

	philo = (t_philo *)arg;
	if ((philo->id % 2) == 0)
		usleep(1000);
	ft_routine(philo);
/*	philo->status = THINKING;
	printf("%d is thinking\n", philo->id);
//	printf("address %p\n", &philo);
	err = pthread_mutex_lock(&philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
	if (err != 0)
		ft_message("Can't lock mutex\n", 1, NULL);
	philo->status = EATING;
	printf("%ld ms %d is eating\n", philo->time_start.tv_usec, philo->id);
	usleep(philo->time_e);
	pthread_mutex_unlock(&philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	printf("%d is sleeping\n", philo->id);
	usleep(philo->time_s);
	if (err != 0)
		ft_message("Can't unlock mutex\n", 1, NULL);*/
	return (NULL);
}

void	ft_start(t_philo *philo, int nbr)
{
	int				i;

	i = -1;
	while (++i < nbr)
	{
		if (pthread_mutex_init(&(philo[i].left_fork), NULL) != 0)
			ft_message("Mutex init error\n", -1, philo);
		if (i == (nbr - 1))
			philo[i].right_fork = &philo[0].left_fork;
		else
			philo[i].right_fork = &philo[(i + 1) % nbr].left_fork;
	}
	i = -1;
	ft_set_time(philo, nbr);
	while (++i < nbr)
	{
		if (pthread_create(&philo[i].tid, NULL, ft_action, &(philo[i])) != 0)
			ft_message("Can't create the thread", -1, philo);
	}
	i = -1;
	while (++i < nbr)
	{
		if (pthread_join(philo[i].tid, NULL) != 0)
			ft_message("Can't join with thread\n", -1, philo);
	}
}
