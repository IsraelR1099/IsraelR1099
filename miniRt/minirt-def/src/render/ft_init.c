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

static void	ft_free_obj(t_world *world)
{
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cyl;
	t_disk		*disk;
	t_object	*tmp;

	tmp = world->obj;
	while (tmp)
	{
		if (tmp->type == sp)
		{
			sphere = (t_sphere *)tmp;
			tmp = sphere->obj;
			free(sphere);
		}
		else if (tmp->type == pl)
		{
			plane = (t_plane *)tmp;
			tmp = plane->obj;
			free(plane);
		}
		else if (tmp->type == cy)
		{
			cyl = (t_cylinder *)tmp;
			tmp = cyl->obj;
			free(cyl);
		}
		else if (tmp->type == di)
		{
			disk = (t_disk *)tmp;
			tmp = disk->obj;
			free(disk);
		}
		else
			break ;
	}
	free(tmp);
}

static void	ft_free_amb(t_world *world)
{
	t_alight	*alight;
	t_light		*light;
	t_cam		*camera;
	t_ambient	*tmp;

	tmp = world->amb;
	while (tmp)
	{
		if (tmp->type == A)
		{
			alight = (t_alight *)tmp;
			tmp = alight->amb;
			free(alight);
		}
		else if (tmp->type == C)
		{
			camera = (t_cam *)tmp;
			tmp = camera->amb;
			free(camera);
		}
		else if (tmp->type == L)
		{
			light = (t_light *)tmp;
			tmp = light->amb;
			free(light);
		}
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
