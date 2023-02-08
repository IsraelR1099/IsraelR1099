/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_generate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:21:31 by irifarac          #+#    #+#             */
/*   Updated: 2023/02/08 13:49:22 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"
#include "../mlx/mlx.h"

static t_ambient *ft_search(t_ambient *amb, int type)
{
	t_light		*light;
	t_alight	*alight;
	t_cam		*camera;
	t_ambient	*tmp;

	tmp = amb;
	while (tmp)
	{
		if (tmp->type == type)
			return (tmp);
		else
		{
			if (tmp->type == 0)
			{
				alight = (t_alight *)tmp;
				tmp = alight->amb;
			}
			else if (tmp->type == 1)
			{
				camera = (t_cam *)tmp;
				tmp = camera->amb;
			}
			else if (tmp->type == 2)
			{
				light = (t_light *)tmp;
				tmp = light->amb;
			}
			else
				break ;
		}
	}
	return (0);
}

int	ft_color_value(t_ambient *amb, int type)
{
	t_light		*light;
	t_alight	*alight;

	if (type == A)
	{
		alight = (t_alight *)ft_search(amb, type);
		return ((alight->r << 16 | alight->g << 8 | alight->b) * alight->ratio);
	}
	else if (type == L)
	{
		light = (t_light *)ft_search(amb, type);
		return (light->r << 16 | light->g << 8 | light->b);
	}
	return (0);
}

void	ft_my_mlx_pxput(t_window *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->ll + x * (mlx->b / 8));
	*(unsigned int *)dst = color;
}

t_object	*ft_find_lst_obj(t_object *obj, int type)
{
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cyl;
	t_object	*tmp;

	tmp = obj;
	while (tmp)
	{
		if (tmp->type == type)
			return (tmp);
		else
		{
			if (tmp->type == 3)
			{
				sphere = (t_sphere *)tmp;
				tmp = sphere->obj;
			}
			else if (tmp->type == 4)
			{
				plane = (t_plane *)tmp;
				tmp = plane->obj;
			}
			else if (tmp->type == 5)
			{
				cyl = (t_cylinder *)tmp;
				tmp = cyl->obj;
			}
			else
				break ;
		}
	}
	return (0);
}

t_ambient	*ft_find_lst(t_ambient *amb, int type)
{
	t_light		*light;
	t_alight	*alight;
	t_cam		*cam;
	t_ambient	*tmp;

	tmp = amb;
	while (tmp)
	{
		if (tmp->type == type)
			return (tmp);
		else
		{
			if (tmp->type == 0)
			{
				alight = (t_alight *)tmp;
				tmp = alight->amb;
			}
			else if (tmp->type == 1)
			{
				cam = (t_cam *)tmp;
				tmp = cam->amb;
			}
			else if (tmp->type == 2)
			{
				light = (t_light *)tmp;
				tmp = light->amb;
			}
			else
				break ;
		}
	}
	return (0);
}


