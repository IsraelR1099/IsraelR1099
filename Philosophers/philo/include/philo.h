/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 09:35:52 by irifarac          #+#    #+#             */
/*   Updated: 2022/12/05 13:08:05 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>

typedef struct s_info
{
	int				id;
	int				time_d;
	int				time_e;
	int				time_s;
	struct timeval	time_start;
	int				nb_e;
	pthread_t		tid;
	pthread_mutex_t	left_fork;
}	t_philo;

int		ft_control(char **str, int counter);
int		ft_set_param(t_philo *philo, char **str, int counter);
int		ft_set_fork(t_philo *philo, char **str);
void	ft_start(t_philo *philo, int nbr);

//Utils
int		ft_message(char *str, int ret, void *arg);
int		ft_atoi(const char *str);

#endif
