/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 10:08:24 by irifarac          #+#    #+#             */
/*   Updated: 2023/04/07 10:20:59 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mlx/mlx.h"
#include "../../include/miniRT.h"

int	key_event(int button, t_world *world)
{
	if (button == 53)
		ft_destroy(world->mlx);
	return (0);
}
