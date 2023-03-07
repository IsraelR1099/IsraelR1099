/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 09:39:50 by irifarac          #+#    #+#             */
/*   Updated: 2023/03/06 13:59:50 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"
#include "../../mlx/mlx.h"
#include "../world/world.h"

void	ft_render(t_ambient *amb, t_object *obj,t_world *world)
{
	int	x;
	int	y;
	int	colour;
	t_ray	ray;
	t_cam	*cam;

	y = 0;
	colour = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			colour = ft_samplers(&ray,(float)x, (float)y);
			ft_my_mlx_pxput(mlx, x, y, colour);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
}
