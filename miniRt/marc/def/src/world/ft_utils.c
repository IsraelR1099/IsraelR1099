/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 09:51:56 by irifarac          #+#    #+#             */
/*   Updated: 2023/05/01 09:55:10 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

void	ft_set_init(t_light **lights, t_ambient *amb)
{
	int	i;
	int	count;

	i = 0;
	count = ft_count_light(amb);
	while (i <= count)
	{
		lights[i] = NULL;
		i++;
	}
}
