/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:36:40 by irifarac          #+#    #+#             */
/*   Updated: 2022/12/16 18:51:31 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_set_param(t_info *info, char **str, int nbr)
{
	int	i;
	int	counter;

	i = 0;
	counter = ft_atoi(str[1]);
	info->philo = malloc(sizeof(t_philo) * counter);
	if (!info->philo)
		ft_message("Malloc error\n", 0, NULL);
	while (i < counter)
	{
		info->nb_phi = ft_atoi(str[1]);
		info->philo[i].id = i + 1;
		info->philo[i].time_d = ft_atoi(str[2]);
		info->philo[i].time_e = ft_atoi(str[3]);
		info->philo[i].time_s = ft_atoi(str[4]);
		info->philo[i].right_fork = NULL;
		info->philo[i].status = 0;
		info->dead = 0;
		info->philo[i].info = info;
		info->philo[i].nb_e = 0;
		i++;
	}
	if (nbr == 5)
		info->nb_e = ft_atoi(str[5]);
	else
		info->nb_e = -1;
	return (0);
}

int	ft_unlock(pthread_mutex_t *mutex, t_philo *philo, int ret)
{
	if (pthread_mutex_unlock(mutex) != 0)
		return (ft_message("Cannot unlock mutex\n", -1, philo));
	return (ret);
}
