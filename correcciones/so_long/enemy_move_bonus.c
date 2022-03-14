/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marza-ga <marza-ga-@student.42barcelo      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:59:00 by marza-ga          #+#    #+#             */
/*   Updated: 2022/03/04 22:17:00 by marza-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_enemy_right(t_mlx *mlx, int count)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img[3].img_ptr,
		mlx->enemys[count].pos_x, mlx->enemys[count].pos_y);
	if (enemy_can_move_to(mlx->enemys[count].pos_x + 26,
			mlx->enemys[count].pos_y, mlx))
	{
		mlx->enemys[count].pos_x++;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img[3].img_ptr,
			mlx->enemys[count].pos_x, mlx->enemys[count].pos_y);
	}
	else
		switch_enemy_dir(mlx, count);
}

void	move_enemy_left(t_mlx *mlx, int count)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img[3].img_ptr,
		mlx->enemys[count].pos_x, mlx->enemys[count].pos_y);
	if (enemy_can_move_to(mlx->enemys[count].pos_x - 1,
			mlx->enemys[count].pos_y, mlx))
	{
		mlx->enemys[count].pos_x--;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img[3].img_ptr,
			mlx->enemys[count].pos_x, mlx->enemys[count].pos_y);
	}
	else
		switch_enemy_dir(mlx, count);
}

void	move_enemy_down(t_mlx *mlx, int count)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img[3].img_ptr,
		mlx->enemys[count].pos_x, mlx->enemys[count].pos_y);
	if (enemy_can_move_to(mlx->enemys[count].pos_x,
			mlx->enemys[count].pos_y - 1, mlx))
	{
		mlx->enemys[count].pos_y--;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img[3].img_ptr,
			mlx->enemys[count].pos_x, mlx->enemys[count].pos_y);
	}
	else
		switch_enemy_dir(mlx, count);
}

void	move_enemy_up(t_mlx *mlx, int count)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img[3].img_ptr,
		mlx->enemys[count].pos_x, mlx->enemys[count].pos_y);
	if (enemy_can_move_to(mlx->enemys[count].pos_x,
			mlx->enemys[count].pos_y + 26, mlx))
	{
		mlx->enemys[count].pos_y++;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img[3].img_ptr,
			mlx->enemys[count].pos_x, mlx->enemys[count].pos_y);
	}
	else
		switch_enemy_dir(mlx, count);
}
