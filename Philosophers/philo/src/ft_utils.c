/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:16:32 by irifarac          #+#    #+#             */
/*   Updated: 2022/12/14 13:24:53 by irifarac         ###   ########.fr       */
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
	struct timeval	now;

	gettimeofday(&now, NULL);
	time = ft_mili(now);
	if ((time - philo->last_eat) >= philo->time_d)
	{
		printf("%ld ms %d died\n", time - philo->info->time_start, philo->id);
		if (pthread_detach(philo->tid) != 0)
			ft_message("Thread could not set to detach mode\n", -1, philo);
		else
			exit (1);
		return (-1);
	}
	return (0);
}

int	ft_usleep(unsigned long long microsec)
{
	struct timeval	now;
	unsigned long long int	wait;
	int	i = 0;

	gettimeofday(&now, NULL);
	wait = ft_mili(now);
	printf("micro es %llu y wait %llu\n", microsec, wait);
	while (wait <= (wait + microsec) && ++i < 5)
	{
		gettimeofday(&now, NULL);
		wait = ft_mili(now);
		printf("wait ahora %llu\n", wait);
		usleep(50);
	}
	return (0);
}
