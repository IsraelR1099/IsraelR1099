/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 09:39:50 by irifarac          #+#    #+#             */
/*   Updated: 2023/04/07 14:07:46 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"
#include "../../mlx/mlx.h"
#include "../world/world.h"
#include "../samplers/samplers.h"

void	ft_render(t_world *world)
{
	int		colour;
	int		row;
	int		column;
	t_ray	ray;

	row = 0;
	colour = 0;
	while (row < VRES)
	{
		column = 0;
		while (column < HRES)
		{
			colour = ft_samplers(world, &ray, (float)column, (float)row);
			ft_my_mlx_pxput(world->mlx, column, row, colour);
			column++;
		}
		row++;
	}
	mlx_put_image_to_window(world->mlx->mlx, world->mlx->mlx_win,
		world->mlx->img, 0, 0);
	printf("salgo de bucle\n");
}
