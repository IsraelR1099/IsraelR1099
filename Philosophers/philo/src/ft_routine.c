/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:23:24 by irifarac          #+#    #+#             */
/*   Updated: 2022/12/10 20:12:33 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	ft_think(t_philo *philo)
{
	long int		time;
	struct timeval	now;

	gettimeofday(&now, NULL);
	time = ft_mili(now);
	philo->status = THINKING;
	printf("%ld ms %d is thinking\n", time - philo->time_start, philo->id);
}

static void	ft_take_fork(t_philo *philo)
{
	int				err;
	long int		time;
	struct timeval	now;

	gettimeofday(&now, NULL);
	time = ft_mili(now);
	err = pthread_mutex_lock(&philo->left_fork);
	printf("%ld ms %d has taken a fork\n", time - philo->time_start, philo->id);
	if (err != 0)
		ft_message("Can't lock mutex\n", 1, philo);
	err = pthread_mutex_lock(philo->right_fork);
	printf("%ld ms %d has taken a fork\n", time - philo->time_start, philo->id);
	if (err != 0)
		ft_message("Can't lock mutex\n", 1, philo);
	philo->last_eat = time;
}

static void	ft_eat(t_philo *philo)
{
	int				err;
	long int		time;
	struct timeval	now;

	gettimeofday(&now, NULL);
	time = ft_mili(now);
	philo->status = EATING;
	printf("%ld ms %d is eating\n", time - philo->time_start, philo->id);
	err = pthread_mutex_unlock(&philo->left_fork);
	if (err != 0)
		ft_message("Can't unlock mutex\n", 1, philo);
	err = pthread_mutex_unlock(philo->right_fork);
	if (err != 0)
		ft_message("Can't unlock mutex\n", 1, philo);
	if (usleep(philo->time_e * 1000) != 0)
		ft_message("Usleep error\n", 1, philo);
}

static void	ft_sleep(t_philo *philo)
{
	long int		time;
	struct timeval	now;

	gettimeofday(&now, NULL);
	time = ft_mili(now);
	printf("%ld ms %d is sleeping\n", time - philo->time_start, philo->id);
	if (usleep(philo->time_s * 1000) != 0)
		ft_message("Usleep error\n", 1, philo);
}

void	ft_routine(t_philo *philo)
{
//	int	i;

	//i = -1;
//	printids("philo ");
	while (ft_check_death(philo) >= 0)
	{
		ft_take_fork(philo);
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
}
