/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:21:31 by irifarac          #+#    #+#             */
/*   Updated: 2023/04/07 14:07:24 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"
#include "../parser/parser.h"
#include "../world/world.h"
#include "../../mlx/mlx.h"

int	ft_destroy(t_window *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	exit(0);
	return (1);
}

void	ft_init(t_ambient *amb, t_object *obj)
{
	t_window	*mlx;
	t_world		*world;

	world = (t_world *)malloc(sizeof(*world));
	if (!world)
		exit(ft_error("Malloc error", 0));
	ft_set_world(amb, obj, world);
	mlx = (t_window *)malloc(sizeof(*mlx));
	if (!mlx)
		exit(ft_error("Malloc error", 0));
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, HRES, VRES, "miniRT");
	mlx->img = mlx_new_image(mlx->mlx, HRES, VRES);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->b, &mlx->ll, &mlx->end);
	world->mlx = mlx;
	ft_render(world);
	mlx_key_hook(world->mlx->mlx_win, key_event, world);
	mlx_hook(mlx->mlx_win, 17, 0, ft_destroy, mlx);
	mlx_loop(mlx->mlx);
}
