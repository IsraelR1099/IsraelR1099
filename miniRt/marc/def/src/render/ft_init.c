/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:21:31 by irifarac          #+#    #+#             */
/*   Updated: 2023/05/08 10:55:53 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"
#include "../parser/parser.h"
#include "../world/world.h"
#include "../../mlx/mlx.h"

static void	ft_free_obj(t_world *world)
{
	t_object	*tmp;

	tmp = world->obj;
	while (tmp)
	{
		if (tmp->type == sp)
			tmp = ft_free_advance(tmp);
		else if (tmp->type == pl)
			tmp = ft_free_advance(tmp);
		else if (tmp->type == cy)
			tmp = ft_free_advance(tmp);
		else if (tmp->type == di)
			tmp = ft_free_advance(tmp);
		else
			break ;
	}
	free(tmp);
}

static void	ft_free_amb(t_world *world)
{
	t_ambient	*tmp;

	tmp = world->amb;
	while (tmp)
	{
		if (tmp->type == A)
			tmp = ft_free_advance_amb(tmp);
		else if (tmp->type == C)
			tmp = ft_free_advance_amb(tmp);
		else if (tmp->type == L)
			tmp = ft_free_advance_amb(tmp);
		else
			break ;
	}
	free(tmp);
}

int	ft_destroy(t_world *world)
{
	mlx_destroy_image(world->mlx->mlx, world->mlx->img);
	mlx_destroy_window(world->mlx->mlx, world->mlx->mlx_win);
	free(world->mlx);
	free(world->camera);
	ft_free_obj(world);
	ft_free_amb(world);
	free(world->lights);
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
	mlx_hook(mlx->mlx_win, 17, 0, ft_destroy, world);
	mlx_loop(mlx->mlx);
}
