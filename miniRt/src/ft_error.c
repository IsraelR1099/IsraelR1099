
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:40:31 by irifarac          #+#    #+#             */
/*   Updated: 2023/01/11 20:43:50 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

static int	ft_format(char **str)
{
	int	len;

	len = ft_strlen(*str);
	if (ft_strcmp(*str + (len - 2), "rt"))
		return (-1);
	return (0);
}

int	ft_error(char **str)
{
	if (ft_format(str) < 0)
		return (-1);
	return (0);
}
