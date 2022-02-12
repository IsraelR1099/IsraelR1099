/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:02:20 by irifarac          #+#    #+#             */
/*   Updated: 2022/02/12 14:06:36 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	position;

	position = 0;
	while (str[position] != '\0')
		position++;
	return (position);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}
