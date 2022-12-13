/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:36:40 by irifarac          #+#    #+#             */
/*   Updated: 2022/12/12 20:39:23 by irifarac         ###   ########.fr       */
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
		info->philo[i].id = i + 1;
		info->philo[i].time_d = ft_atoi(str[2]);
		info->philo[i].time_e = ft_atoi(str[3]);
		info->philo[i].time_s = ft_atoi(str[4]);
		info->philo[i].right_fork = NULL;
		info->philo[i].status = 0;
		info->philo[i].info = info;
		if (nbr == 5)
			info->philo[i].nb_e = ft_atoi(str[5]);
		else
			info->philo[i].nb_e = -1;
		i++;
	}
	return (0);
}
