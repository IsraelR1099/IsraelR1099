/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:19:48 by irifarac          #+#    #+#             */
/*   Updated: 2022/12/04 17:45:04 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*ft_action(void *arg)
{
	int		err;
	t_philo	*philo;

	philo = (t_philo *)arg;
	printf("philo en action %d, address %p\n", philo->id,
	&philo->left_fork);
	if ((philo->id % 2) == 0)
		usleep(1000);
	err = pthread_mutex_lock(&philo->left_fork);
	if (err != 0)
		ft_message("Can't lock mutex\n", 1, NULL);
//	printf("hola soy %d y fork address %p\n", philo->id,
//	&philo->forks->left_fork);
	pthread_mutex_unlock(&philo->left_fork);
	if (err != 0)
		ft_message("Can't unlock mutex\n", 1, NULL);
	return (NULL);
}

void	ft_start(t_philo *philo, int nbr)
{
	int		i;
	int		err;
	void	*tret;

	i = 0;
	printf("nbr es %d\n", nbr);
	while (i < nbr)
	{
		err = pthread_create(&philo[i].tid, NULL, ft_action, &(philo[i]));
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
