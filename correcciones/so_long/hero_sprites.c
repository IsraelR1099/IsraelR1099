/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hero_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marza-ga <marza-ga-@student.42barcelo      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:59:00 by marza-ga          #+#    #+#             */
/*   Updated: 2022/03/04 22:17:00 by marza-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_hero_sprites_right(t_mlx *mlx)
{
	if (mlx->hero->sp_num <= 7 && mlx->hero->sp_num > 4)
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win,
			mlx->hero->img[mlx->hero->sp_num].img_ptr,
			mlx->hero->pos_x, mlx->hero->pos_y);
	}
	else
	{
		mlx->hero->sp_num = 5;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win,
			mlx->hero->img[mlx->hero->sp_num].img_ptr,
			mlx->hero->pos_x, mlx->hero->pos_y);
	}
	mlx->hero->sp_time++;
	if (mlx->hero->sp_time == 10)
	{
		mlx->hero->sp_num++;
		mlx->hero->sp_time = 0;
	}
}

void	move_hero_sprites_left(t_mlx *mlx)
{
	if (mlx->hero->sp_num <= 10 && mlx->hero->sp_num > 7)
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win,
			mlx->hero->img[mlx->hero->sp_num].img_ptr,
			mlx->hero->pos_x, mlx->hero->pos_y);
	}
	else
	{
		mlx->hero->sp_num = 8;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win,
			mlx->hero->img[mlx->hero->sp_num].img_ptr,
			mlx->hero->pos_x, mlx->hero->pos_y);
	}
	mlx->hero->sp_time++;
	if (mlx->hero->sp_time == 10)
	{
		mlx->hero->sp_num++;
		mlx->hero->sp_time = 0;
	}
}

void	move_hero_sprites_up(t_mlx *mlx)
{
	if (mlx->hero->sp_num <= 13 && mlx->hero->sp_num > 10)
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win,
			mlx->hero->img[mlx->hero->sp_num].img_ptr,
			mlx->hero->pos_x, mlx->hero->pos_y);
	}
	else
	{
		mlx->hero->sp_num = 11;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win,
			mlx->hero->img[mlx->hero->sp_num].img_ptr,
			mlx->hero->pos_x, mlx->hero->pos_y);
	}
	mlx->hero->sp_time++;
	if (mlx->hero->sp_time == 10)
	{
		mlx->hero->sp_num++;
		mlx->hero->sp_time = 0;
	}
}

void	move_hero_sprites_down(t_mlx *mlx)
{
	if (mlx->hero->sp_num <= 16 && mlx->hero->sp_num > 13)
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win,
			mlx->hero->img[mlx->hero->sp_num].img_ptr,
			mlx->hero->pos_x, mlx->hero->pos_y);
	}
	else
	{
		mlx->hero->sp_num = 14;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win,
			mlx->hero->img[mlx->hero->sp_num].img_ptr,
			mlx->hero->pos_x, mlx->hero->pos_y);
	}
	mlx->hero->sp_time++;
	if (mlx->hero->sp_time == 10)
	{
		mlx->hero->sp_num++;
		mlx->hero->sp_time = 0;
	}
}
