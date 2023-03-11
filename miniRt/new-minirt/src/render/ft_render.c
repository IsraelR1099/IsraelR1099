/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 09:39:50 by irifarac          #+#    #+#             */
/*   Updated: 2023/03/11 11:01:37 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"
#include "../../mlx/mlx.h"
#include "../world/world.h"
#include "../samplers/samplers.h"

void	ft_render(t_ambient *amb, t_object *obj,t_world *world)
{
	int		x;
	int		y;
	int		colour;
	t_ray	ray;

	y = 0;
	colour = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			colour = ft_samplers(world, &ray,(float)x, (float)y);
			ft_my_mlx_pxput(world->mlx, x, y, colour);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(world->mlx->mlx, world->mlx->mlx_win, world->mlx->img, 0, 0);
	(void)amb;
	(void)obj;
}
