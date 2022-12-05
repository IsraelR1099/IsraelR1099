/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:19:48 by irifarac          #+#    #+#             */
/*   Updated: 2022/12/05 11:52:37 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_set_time(t_philo *philo, int nbr)
{
	int	i;

	i = 1;
	gettimeofday(&philo[0].time_start, NULL);
	while (i < nbr)
	{
		philo[i].time_start = philo[0].time_start;
		i++;
	}
}

void	*ft_action(void *arg)
{
	int				err;
	t_philo			*philo;

	philo = (t_philo *)arg;
	if ((philo->id % 2) == 0)
		usleep(1000);
	err = pthread_mutex_lock(&philo->left_fork);
	if (err != 0)
		ft_message("Can't lock mutex\n", 1, NULL);
	printf("philo en action %d, address %p, ms %d, secs %ld\n", philo->id,
		&philo->left_fork, philo->time_start.tv_usec, philo->time_start.tv_sec);
	pthread_mutex_unlock(&philo->left_fork);
	if (err != 0)
		ft_message("Can't unlock mutex\n", 1, NULL);
	return (NULL);
}

void	ft_start(t_philo *philo, int nbr)
{
	int				i;
	int				err;
	void			*tret;

	i = 0;
	ft_set_time(philo, nbr);
	while (i < nbr)
	{
		err = pthread_create(&philo[i].tid, NULL, ft_action, &(philo[i]));
		if (err != 0)
			ft_message("Can't create the thread", -1, philo);
		i++;
	}
	i = 0;
	while (i < nbr)
	{
		err = pthread_join(philo[i].tid, &tret);
		if (err != 0)
			ft_message("Can't join with thread\n", -1, philo);
		i++;
	}
}
