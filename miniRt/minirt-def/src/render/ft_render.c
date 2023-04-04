/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 09:39:50 by irifarac          #+#    #+#             */
/*   Updated: 2023/03/24 13:44:39 by irifarac         ###   ########.fr       */
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
	while (row < vres)
	{
		column = 0;
		while (column < hres)
		{
			colour = ft_samplers(world, &ray, (float)column, (float)row);
			ft_my_mlx_pxput(world->mlx, column, row, colour);
			column++;
		}
		row++;
		//printf("r %d, c %d, colour %d\n", row, column, colour);
	}
	printf("salgo render\n");
	mlx_put_image_to_window(world->mlx->mlx, world->mlx->mlx_win, world->mlx->img, 0, 0);
//	printf("salgo de bucle\n");
}
