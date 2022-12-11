/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:36:40 by irifarac          #+#    #+#             */
/*   Updated: 2022/12/10 20:13:32 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_set_param(t_philo *philo, char **str, int nbr)
{
	int	i;
	int	counter;

	i = 0;
	counter = ft_atoi(str[1]);
	while (i < counter)
	{
		philo[i].id = i + 1;
		philo[i].time_d = ft_atoi(str[2]);
		philo[i].time_e = ft_atoi(str[3]);
		philo[i].time_s = ft_atoi(str[4]);
		philo[i].status = 0;
		if (nbr == 5)
			philo[i].nb_e = ft_atoi(str[5]);
		else
			philo[i].nb_e = -1;
		i++;
	}
	return (0);
}

int	ft_set_fork(t_philo *philo, char **str)
{
	int	i;
	int	err;
	int	counter;

	i = 0;
	counter = ft_atoi(str[1]);
	while (i < counter)
	{
		err = pthread_mutex_init(&(philo[i].left_fork), NULL);
		if (err != 0)
			return (ft_message("mutex init error\n", -1, philo));
		if (i == (counter - 1))
			philo[i].right_fork = &philo[0].left_fork;
		else
		i++;
	}
	return (0);
}
