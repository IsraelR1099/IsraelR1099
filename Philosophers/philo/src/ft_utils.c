/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:16:32 by irifarac          #+#    #+#             */
/*   Updated: 2022/12/18 20:41:14 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long int	ft_mili(struct timeval time)
{
	long int	time_conv;

	time_conv = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (time_conv);
}

int	ft_message(char *str, int ret, void *arg)
{
	t_info	*info;

	info = (t_info *)arg;
	printf("%s", str);
	if (ret == -1)
	{
		free(info->philo);
	}
	return (ret);
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

int	ft_timeout(t_philo *philo)
{
	long int		time;
	static int		i = 0;
	struct timeval	now;

	pthread_mutex_lock(&philo->info->is_dead);
	gettimeofday(&now, NULL);
	time = ft_mili(now);
	printf("time %ld and last eat es %ld, philo %d\n", time, philo->last_eat,
	philo->id);
	if ((time - philo->last_eat) > philo->time_d)
	{
		philo->status = DEAD;
		philo->info->dead = 1;
		i++;
		if (philo->info->dead == 1 && i == 1)
		{
			philo->info->time_dead = time;
			return (-1);
		}
		//	printf("%ld ms %d died\n", time - philo->info->time_start, philo->id);
	}
	pthread_mutex_unlock(&philo->info->is_dead);
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
