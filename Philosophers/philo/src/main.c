/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 09:31:55 by irifarac          #+#    #+#             */
/*   Updated: 2022/12/12 13:43:40 by irifarac         ###   ########.fr       */
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
	t_info	info;
	int		nbr_phi;

	ft_set_param(&info, str, counter);
	ft_start(&info, ft_atoi(str[1]));
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
