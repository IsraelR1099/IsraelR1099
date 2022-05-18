/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:06:14 by irifarac          #+#    #+#             */
/*   Updated: 2022/05/18 21:06:25 by irifarac         ###   ########.fr       */
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
void	message(int null);

#endif
