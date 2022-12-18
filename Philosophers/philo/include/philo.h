/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 09:35:52 by irifarac          #+#    #+#             */
/*   Updated: 2022/12/17 20:52:10 by irifarac         ###   ########.fr       */
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

# define EATING 1
# define SLEEPING 2
# define THINKING 3
# define DEAD 4

typedef struct s_philo
{
	int				id;
	int				time_d;
	int				time_e;
	int				time_s;
	long int		last_eat;
	int				nb_e;
	int				status;
	struct s_info	*info;
	pthread_t		tid;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	*right_fork;
}	t_philo;

typedef struct s_info
{
	long int		time_start;
	int				nb_e;
	int				nb_phi;
	int				dead;
	long int		time_dead;
	pthread_mutex_t	is_dead;
	t_philo			*philo;
}	t_info;

int			ft_control(char **str, int counter);
int			ft_set_param(t_info *info, char **str, int counter);
void		ft_start(t_info *info, int nbr);
void		ft_routine(t_philo *philo);
int	ft_timeout(t_philo *philo);
//Utils
int			ft_message(char *str, int ret, void *arg);
int			ft_atoi(const char *str);
long int	ft_mili(struct timeval time);
void		printids(const char *s);
void		ft_usleep(int milisec);
int			ft_unlock(pthread_mutex_t *mutex, t_philo *philo, int ret);

#endif
