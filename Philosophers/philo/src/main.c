/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 09:31:55 by irifarac          #+#    #+#             */
/*   Updated: 2022/12/08 20:20:57 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_free_mutex(t_philo *philo, int counter)
{
	int	i;
	int	err;

	i = 0;
	while (i <= counter)
	{
		err = pthread_mutex_destroy(&philo[i].left_fork);
		if (err != 0)
			return (ft_message("mutex destroy error\n", -1, philo));
		i++;
	}
	free(philo);
	return (0);
}

int	ft_init(char **str, int counter)
{
	t_philo	*philo;
	int		nbr_phi;
//	int		i;

	nbr_phi = ft_atoi(str[1]);
	philo = (t_philo *)malloc(sizeof(*philo) * nbr_phi);
	if (!philo)
		return (ft_message("Malloc error", -1, philo));
	memset(philo, 0, (sizeof(*philo)));
	ft_set_param(philo, str, counter);
//	ft_set_fork(philo, str);
	ft_start(philo, ft_atoi(str[1]));
/*	i = 0;
	counter = ft_atoi(str[1]);
	while (i < counter)
	{
		printf("philo %d es: td %d, te %d, ts %d, ne %d\n", philo[i].id , philo[i].time_d, philo[i]			.time_e, philo[i].time_s, philo[i].nb_e);
		i++;
	}*/
//	ft_free_mutex(forks, ft_atoi(str[1]));
	free(philo);
	return (0);
}

int	main(int counter, char **str)
{
	int	ret;

	ret = 0;
	if (counter == 5 || counter == 6)
	{
		if (ft_control(str, counter))
			if (ft_init(str, counter - 1) < 0)
				ret = ft_message("Initialization error", 1, NULL);
	}
	else
		ret = ft_message("Wrong number of arguments\n", 1, NULL);
	return (ret);
}
