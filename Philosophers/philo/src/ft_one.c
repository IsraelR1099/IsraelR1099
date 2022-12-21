/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_one.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 09:38:03 by irifarac          #+#    #+#             */
/*   Updated: 2022/12/21 09:39:10 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*ft_one(t_philo *philo)
{
	struct timeval	now;
	long long int	time;

	if (pthread_mutex_lock(&philo->left_fork) != 0)
		ft_message("Cannot lock mutex\n", 1, philo);
	if (gettimeofday(&now, NULL) != 0)
		ft_message("Gettimeofday failed\n", -1, philo);
	time = ft_mili(now);
	if (philo->info->dead != 0)
		return (NULL);
	else
		ft_print(philo, "has taken a fork", time);
	ft_usleep(philo->time_d);
	philo->info->time_dead = ft_gettime();
	if (printf("%ld ms %d died\n", (philo->info->time_dead
				- philo->info->time_start), philo->id) < 0)
		ft_message("Printf error\n", -1, philo);
	return (NULL);
}
