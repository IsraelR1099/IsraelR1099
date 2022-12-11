/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:16:32 by irifarac          #+#    #+#             */
/*   Updated: 2022/12/10 20:15:14 by irifarac         ###   ########.fr       */
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
	printf("%s", str);
	if (ret == -1)
	{
		free(arg);
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

int	ft_check_death(t_philo *philo)
{
	long int		time;
	struct timeval	now;

	gettimeofday(&now, NULL);
	time = ft_mili(now);
//	printf("tim es %ld y last eat %ld\n", time, philo->last_eat);
	if (time - philo->last_eat >= philo->time_d)
	{
		printf("%ld %d died\n", time - philo->time_start, philo->id);
		return (-1);
	}
	return (0);
}
