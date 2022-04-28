/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 10:52:12 by irifarac          #+#    #+#             */
/*   Updated: 2022/04/28 12:23:57 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib_fractal.h"
#include "mlx/mlx.h"

int	key_event(int button, window *param)
{
	if (button == 53)
		mlx_destroy_window(param->mlx, param->mlx_win);
	return (1);
}
