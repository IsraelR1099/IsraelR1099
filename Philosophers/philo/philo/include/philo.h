/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 09:35:52 by irifarac          #+#    #+#             */
/*   Updated: 2022/12/02 12:59:56 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_fork
{
	pthread_mutex_t	left_fork;
	pthread_mutex_t	right_fork;
}	t_fork;

typedef struct s_info
{
	int			id;
	int			time_d;
	int			time_e;
	int			time_s;
	int			nb_e;
	pthread_t	tid;
	t_fork		*forks;
}	t_philo;

int		ft_control(char **str, int counter);
int		ft_set_param(t_philo *philo, char **str, int counter);
int		ft_set_fork(t_fork *forks, char **str);
void	ft_start(t_philo *philo, int nbr);

//Utils
int		ft_message(char *str, int ret, void *arg);
int		ft_atoi(const char *str);

#endif
