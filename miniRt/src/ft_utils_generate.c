/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_generate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:21:31 by irifarac          #+#    #+#             */
/*   Updated: 2023/01/27 20:40:15 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"
#include "../mlx/mlx.h"

int	ft_color_value(t_light *light)
{
	return (light->r << 16 | light->g << 8 | light->b);
}

void	ft_my_mlx_pxput(t_window *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->ll + x * (mlx->b / 8));
	*(unsigned int *)dst = color;
}	
