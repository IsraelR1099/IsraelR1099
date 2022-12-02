/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:19:48 by irifarac          #+#    #+#             */
/*   Updated: 2022/12/02 12:51:43 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*ft_action(void *arg)
{
	t_philo	*philo;
	int		err;

	philo = (t_philo *)arg;
	if ((philo->id % 2) == 0)
		usleep(1000);
	err = pthread_mutex_lock(&philo->forks->left_fork);
	if (err != 0)
		ft_message("Can't lock mutex\n", 1, NULL);
	printf("hola soy %d\n", philo->id);
	pthread_mutex_unlock(&philo->forks->left_fork);
	if (err != 0)
		ft_message("Can't unlock mutex\n", 1, NULL);
	return (0);
}

void	ft_start(t_philo *philo, int nbr)
{
	int		i;
	int		err;
	void	*tret;

	i = 0;
	exit(0);
	while (i < nbr)
	{
		err = pthread_create(&philo[i].tid, NULL, ft_action, (void *)&philo[i]);
		if (err != 0)
			ft_message("Can't create the thread", -1, philo);
		i++;
		printf("i en start es %d\n", i);
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
