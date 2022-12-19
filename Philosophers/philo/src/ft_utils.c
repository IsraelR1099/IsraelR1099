/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:16:32 by irifarac          #+#    #+#             */
/*   Updated: 2022/12/19 11:41:35 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long int	ft_mili(struct timeval time)
{
	long int	time_conv;

	time_conv = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (time_conv);
}

int	ft_atoi(const char *str)
{
	int	position;
	int	number;
	int	sign;

	position = 0;
	number = 0;
	sign = 1;
	while (((str[position] >= 9) && (str[position] <= 13))
		|| (str[position] == 32))
		position++;
	if ((str[position] == '-') || (str[position] == '+'))
	{
		if (str[position] == '-')
			sign = -1;
		position++;
	}
	while ((str[position] >= 48) && (str[position] <= 57))
	{
		number = number * 10 + str[position] - 48;
		position++;
	}
	return (sign * number);
}

long long int	ft_gettime(void)
{
	struct timeval	now;
	long int		time;

	gettimeofday(&now, NULL);
	time = (now.tv_sec * 1000) + (now.tv_usec / 1000);
	return (time);
}

int	ft_timeout(t_info *info)
{
	static int		i = 0;
	int				j;

	pthread_mutex_lock(&info->is_dead);
	j = 0;
	if ((ft_gettime() - info->philo[i].last_eat) > info->philo->time_d)
	{
		info->philo[i].status = DEAD;
		info->dead = 1;
		i++;
		if (info->dead != 0 && i == 1)
		{
			info->time_dead = ft_gettime();
			return (-1);
		}
		j++;
	}
	pthread_mutex_unlock(&info->is_dead);
	return (0);
}

void	ft_usleep(int milisec)
{
	long int		time;
	struct timeval	now;

	gettimeofday(&now, NULL);
	time = ft_mili(now);
	while ((ft_mili(now) - time) < milisec)
	{
		usleep(50);
		gettimeofday(&now, NULL);
	}
}
