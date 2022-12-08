/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:23:24 by irifarac          #+#    #+#             */
/*   Updated: 2022/12/08 20:56:08 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	ft_think(t_philo *philo)
{
	philo->status = THINKING;
	printf("%d is thinking\n", philo->id);
}

static void	ft_take_fork(t_philo *philo)
{
	int	err;

	err = pthread_mutex_lock(&philo->left_fork);
	printf("%d has taken a fork\n", philo->id);
	if (err != 0)
		ft_message("Can't lock mutex\n", 1, philo);
	err = pthread_mutex_lock(philo->right_fork);
	printf("%d has taken a fork\n", philo->id);
	if (err != 0)
		ft_message("Can't lock mutex\n", 1, philo);
}

static void	ft_eat(t_philo *philo)
{
	int	err;

	philo->status = EATING;
	printf("%ld ms %d is eating\n", philo->time_start.tv_usec, philo->id);
	if (usleep(philo->time_e) != 0)
		ft_message("Usleep error\n", 1, philo);
	err = pthread_mutex_unlock(&philo->left_fork);
	if (err != 0)
		ft_message("Can't unlock mutex\n", 1, philo);
	err = pthread_mutex_unlock(philo->right_fork);
	if (err != 0)
		ft_message("Can't unlock mutex\n", 1, philo);
}

static void	ft_sleep(t_philo *philo)
{
	printf("%d is sleeping\n", philo->id);
	if (usleep(philo->time_s) != 0)
		ft_message("Usleep error\n", 1, philo);
}

void	ft_routine(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < 5)
	{
		ft_think(philo);
		ft_take_fork(philo);
		ft_eat(philo);
		ft_sleep(philo);
/*		philo->status = THINKING;
		printf("%d is thinking\n", philo->id);
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
	}
}
