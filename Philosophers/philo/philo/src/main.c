/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 09:31:55 by irifarac          #+#    #+#             */
/*   Updated: 2022/11/30 14:27:23 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_init(char **str, int counter)
{
	t_philo	*philo;
	t_fork	*forks;
	int		i;

	philo = (t_philo *)malloc(sizeof(*philo) * counter);
	forks = (t_fork *)malloc(sizeof(*forks) * counter);
	if (!philo || !forks)
		return (ft_message("Malloc error", -1, philo));
	ft_set_param(philo, str, counter);
	ft_set_fork(forks, counter);
	i = 0;
	while (i < counter)
	{
		printf("philo %d es: td %d, te %d, ts %d, ne %d\n",i + 1 , philo[i].time_d, philo[i].time_e, philo[i].time_s, philo[i].nb_e);
		i++;
	}
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
