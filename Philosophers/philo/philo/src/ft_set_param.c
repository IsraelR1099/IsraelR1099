/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:36:40 by irifarac          #+#    #+#             */
/*   Updated: 2022/12/02 12:59:35 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_set_param(t_philo *philo, char **str, int nbr)
{
	int	i;
	int	counter;

	i = 0;
	counter = ft_atoi(str[1]);
	printf("counter es %d\n", counter);
	while (i <= counter)
	{
		philo[i].id = i + 1;
		philo[i].time_d = ft_atoi(str[2]);
		philo[i].time_e = ft_atoi(str[3]);
		philo[i].time_s = ft_atoi(str[4]);
		if (nbr == 5)
			philo[i].nb_e = ft_atoi(str[5]);
		else
			philo[i].nb_e = -1;
		i++;
	}
	printf("i es %d\n", i);
	return (0);
}

int	ft_set_fork(t_fork *forks, char **str)
{
	int	i;
	int	err;
	int	counter;

	i = 0;
	counter = ft_atoi(str[1]);
	while (i <= counter)
	{
		err = pthread_mutex_init(&forks[i].left_fork, NULL);
		if (err != 0)
			return (ft_message("mutex init error\n", -1, forks));
		err = pthread_mutex_init(&forks[i].right_fork, NULL);
		if (err != 0)
			return (ft_message("mutex init error\n", -1, forks));
		//forks[i].c = 'a' + i;
		printf("philo %d, address left %p, address right %p\n", i, (void *)&forks[i].left_fork, (void *)&forks[i].right_fork);
//		printf("c es %c\n", forks[i].c);
		i++;
	}
	return (0);
}

