/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:23:24 by irifarac          #+#    #+#             */
/*   Updated: 2022/12/20 20:29:47 by irifarac         ###   ########.fr       */
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
	if (philo->info->dead != 0)
		return (-1);
	else
		ft_print(philo, "is thinking", time);
	if (philo->info->dead != 0)
		return (-1);
	return (0);
}

int	ft_take_fork(t_philo *philo)
{
	long int		time;
	struct timeval	now;

	if (philo->info->dead != 0)
		return (-1);
	if (pthread_mutex_lock(&(philo->left_fork)) != 0)
		ft_message("Can't lock mutex left\n", 1, philo);
	gettimeofday(&now, NULL);
	time = ft_mili(now);
	if (philo->info->dead != 0)
		return (-1);
	else
		ft_print(philo, "has taken a fork", time);
	if (philo->info->dead != 0)
		return (-1);
	else
		ft_print(philo, "has taken a fork", time);
	if (pthread_mutex_lock(philo->right_fork) != 0)
		ft_message("Can't lock mutex right\n", 1, philo);
	philo->last_eat = time;
	if (philo->info->dead != 0)
		return (-1);
	return (0);
}

static int	ft_eat(t_philo *philo)
{
	int				err;
	long int		time;
	struct timeval	now;

	if (philo->info->dead != 0)
		return (ft_unlock(philo));
	gettimeofday(&now, NULL);
	time = ft_mili(now);
	philo->status = EATING;
	philo->nb_e++;
	if (philo->info->dead != 0)
		return (ft_unlock(philo));
	ft_print(philo, "is eating", time);
	ft_usleep(philo->time_e);
	err = pthread_mutex_unlock(philo->right_fork);
	if (philo->info->dead != 0)
		return (ft_unlock(philo));
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
	if (philo->info->dead != 0)
		return (-1);
	else
		ft_print(philo, "is sleeping", time);
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
	if (usleep(1000) < 0)
		ft_message("Usleep failed\n", -1, philo);
	i++;
	if (i == 1 && philo->info->dead != 0)
	{
		printf("%ld ms %d died\n",
			philo->info->time_dead - philo->info->time_start, philo->id);
	}
	if (pthread_mutex_unlock(&philo->info->is_dead) != 0)
		ft_message("Cannot unlock mutex\n", -1, philo);
}
