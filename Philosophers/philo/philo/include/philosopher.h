/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 09:35:52 by irifarac          #+#    #+#             */
/*   Updated: 2022/11/28 13:33:36 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_control(char **str, int counter);

//Utils
int	ft_message(char *str, int ret);

#endif
