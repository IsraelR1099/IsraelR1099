/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:19:48 by irifarac          #+#    #+#             */
/*   Updated: 2022/12/19 11:39:34 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	ft_mutex_init(t_info *info, int nbr)
{
	int	i;

	i = -1;
	if (pthread_mutex_init(&(info->is_dead), NULL) != 0)
		return (ft_message("Mutex init error\n", -1, info));
	while (++i < nbr)
	{
		if (pthread_mutex_init(&(info->philo[i].left_fork), NULL) != 0)
			return (ft_message("Mutex init error\n", -1, info));
		if (i == (nbr - 1))
			info->philo[i].right_fork = &(info->philo[0].left_fork);
		else
			info->philo[i].right_fork = &(info->philo[(i + 1) % nbr].left_fork);
	}
	return (0);
}

static void	ft_set_time(t_info *info, int nbr)
{
	int				i;
	struct timeval	time;

	i = -1;
	gettimeofday(&time, NULL);
	while (++i < nbr)
	{
		info->time_start = ft_mili(time);
		info->philo[i].last_eat = ft_mili(time);
	}
}

static void	*ft_action(void *arg)
{
	t_philo			*philo;

	philo = (t_philo *)arg;
	if ((philo->id % 2) == 0)
		ft_usleep(philo->time_e);
	ft_routine(philo);
	return (NULL);
}

static void	ft_control_main(t_info *info)
{
	while (1)
	{
		if (ft_timeout(info) < 0)
			break ;
	}
}

void	ft_start(t_info *info, int nbr)
{
	int	i;

	i = -1;
	if (ft_mutex_init(info, nbr) != 0)
		return ;
	ft_set_time(info, nbr);
	while (++i < nbr)
	{
		if (pthread_create(&info->philo[i].tid, NULL,
				ft_action, &(info->philo[i])) != 0)
			ft_message("Can't create the thread", -1, info);
	}
	ft_control_main(info);
	i = -1;
	while (++i < nbr)
	{
		if (pthread_mutex_unlock(&info->philo[i].left_fork) != 0)
			return ;
	}
	i = -1;
	while (++i < nbr)
	{
		if (pthread_join(info->philo[i].tid, NULL) != 0)
			ft_message("Can't join with thread\n", -1, info);
	}
}
