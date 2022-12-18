/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:23:24 by irifarac          #+#    #+#             */
/*   Updated: 2022/12/18 20:27:47 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	ft_think(t_philo *philo)
{
	long int		time;
	struct timeval	now;

	gettimeofday(&now, NULL);
	time = ft_mili(now);
	philo->status = THINKING;
	if (ft_timeout(philo) != 0)
		return (-1);
	if (philo->info->dead != 0)
		return (-1);
	else
		printf("%ld ms %d is thinking\n", time - philo->info->time_start, philo->id);
	if (philo->info->dead != 0)
		return (-1);
	return (0);
}

static int	ft_take_fork(t_philo *philo)
{
	long int		time;
	struct timeval	now;

	if (philo->info->dead != 0)
		return (-1);
	if (pthread_mutex_lock(&(philo->left_fork)) != 0)
		ft_message("Can't lock mutex left\n", 1, philo);
	gettimeofday(&now, NULL);
	time = ft_mili(now);
	if (ft_timeout(philo) != 0 || philo->info->dead != 0)
		return (-1);
	else
	{
		printf("%ld ms %d has taken a fork\n",
			time - philo->info->time_start, philo->id);
	}
	if (ft_timeout(philo) != 0 || philo->info->dead != 0)
		return (-1);
	else
	{
		printf("%ld ms %d has taken a fork\n",
			time - philo->info->time_start, philo->id);
	}
	if (pthread_mutex_lock(philo->right_fork) != 0)
		ft_message("Can't lock mutex right\n", 1, philo);
	philo->last_eat = time;
	if (ft_timeout(philo) != 0 || philo->info->dead != 0)
		return (-1);
	return (0);
}

static int	ft_eat(t_philo *philo)
{
	int				err;
	long int		time;
	struct timeval	now;

	if (philo->info->dead != 0 || ft_timeout(philo) != 0)
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(&philo->left_fork);
		return (-1);
	}
	gettimeofday(&now, NULL);
	time = ft_mili(now);
	philo->status = EATING;
	philo->nb_e++;
	if (ft_timeout(philo) != 0 || philo->info->dead != 0)
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(&philo->left_fork);
		return (-1);
	}
	printf("%ld ms %d is eating\n", time - philo->info->time_start, philo->id);
	ft_usleep(philo->time_e);
	err = pthread_mutex_unlock(philo->right_fork);
	if (ft_timeout(philo) != 0 || philo->info->dead != 0)
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(&philo->left_fork);
		return (-1);
	}
	if (err != 0)
		ft_message("Can't unlock mutex\n", 1, philo);
	err = pthread_mutex_unlock(&philo->left_fork);
	if (err != 0)
		ft_message("Can't unlock mutex\n", 1, philo);
	return (0);
}

static int	ft_sleep(t_philo *philo)
{
	long int		time;
	struct timeval	now;

	if (philo->info->dead != 0)
		return (-1);
	gettimeofday(&now, NULL);
	time = ft_mili(now);
	philo->status = SLEEPING;
	if (ft_timeout(philo) != 0 || philo->info->dead != 0)
		return (-1);
	else
		printf("%ld ms %d is sleeping\n", time - philo->info->time_start, philo->id);
	ft_usleep(philo->time_s);
	return (0);
}

void	ft_routine(t_philo *philo)
{
	static int	i = 0;

	while (philo->status != DEAD && philo->info->dead == 0)
	{
		if (ft_take_fork(philo) != 0)
			break ;
		if (ft_eat(philo) != 0)
			break ;
		if (ft_sleep(philo) != 0)
			break ;
		if (ft_think(philo) != 0)
			break ;
		if (philo->info->nb_e != -1 && philo->nb_e >= philo->info->nb_e)
			break ;
	}
	usleep(1000);
	i++;
	if (i == 1 && philo->info->dead != 0)
		printf("%ld ms %d died\n", philo->info->time_dead - philo->info->time_start, philo->id);
	pthread_mutex_unlock(&philo->info->is_dead);
}
