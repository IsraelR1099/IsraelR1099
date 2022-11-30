/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:36:40 by irifarac          #+#    #+#             */
/*   Updated: 2022/11/30 14:27:25 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_set_param(t_philo *philo, char **str, int counter)
{
	int	i;

	i = 0;
	while (i < counter)
	{
		philo[i].time_d = ft_atoi(str[2]);
		philo[i].time_e = ft_atoi(str[3]);
		philo[i].time_s = ft_atoi(str[4]);
		if (counter == 5)
			philo[i].nb_e = ft_atoi(str[5]);
		else
			philo[i].nb_e = -1;
		i++;
	}
	printf("i es %d\n", i);
	return (0);
}

int	ft_set_fork(t_fork *forks, int counter)
{
	int	i;
	int	err;

	i = 0;
	while (i < counter)
	{
		err = pthread_mutex_init(&forks[i].left_fork, NULL);
		if (err != 0)
			return (ft_message("mutex init error\n", -1, forks));
		err = pthread_mutex_init(&forks[i].right_fork, NULL);
		if (err != 0)
			return (ft_message("mutex init error\n", -1, forks));
		i++;
	}
	return (0);
}

