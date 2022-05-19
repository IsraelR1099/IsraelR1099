/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:06:14 by irifarac          #+#    #+#             */
/*   Updated: 2022/05/19 10:39:06 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int		ft_atoi(char *str);
int		ft_len(int n);
size_t	ft_strlen(char *str);
char	*ft_itoa(int n);
void	sign_handler(int pid_server, char c);
void	sign_handler_server(int n);
void	ft_putstr(char *str);
void	action(int sig, siginfo_t *info, void *context);
void	sign_handler_server_bonus(int n, int client_pid);
void	sign(int sig);

#endif
