/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:18:19 by irifarac          #+#    #+#             */
/*   Updated: 2022/05/26 13:04:01 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_fractal.h"

void	ft_zoom_plus(t_window *init)
{
	if (init->z_x <= 0.02 && init->z_y <= 0.02)
	{
		init->z_x -= 0.0005;
		init->z_y -= 0.0005;
	}
	else
	{
		init->z_x -= 0.02;
		init->z_y -= 0.02;
	}
}

void	ft_zoom_less(int x, int y, t_window *init)
{
	if (init->z_x <= 0.02 && init->z_y <= 0.02)
	{
		init->trl_x -= (int)((x - 640) * init->z_x);
		init->trl_y -= (int)((y - 360) * init->z_y);
		init->z_x += 0.005;
		init->z_y += 0.005;
	}
	else
	{
		init->z_x += 0.02;
		init->z_y += 0.02;
	}
}
