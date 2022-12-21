/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:51:13 by irifarac          #+#    #+#             */
/*   Updated: 2022/12/21 09:39:34 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_print(t_philo *philo, const char *str, long int time)
{
	if (printf("%ld ms %d %s\n", time - philo->info->time_start,
			philo->id, str) < 0)
		ft_message("Prinf error\n", -1, philo);
}
