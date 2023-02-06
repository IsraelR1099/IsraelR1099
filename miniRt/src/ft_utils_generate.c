/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_generate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:21:31 by irifarac          #+#    #+#             */
/*   Updated: 2023/02/06 12:59:40 by irifarac         ###   ########.fr       */
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
