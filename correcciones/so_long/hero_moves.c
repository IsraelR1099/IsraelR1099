/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hero_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marza-ga <marza-ga-@student.42barcelo      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:59:00 by marza-ga          #+#    #+#             */
/*   Updated: 2022/03/04 22:17:00 by marza-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_hero(t_mlx *mlx)
{
	if (mlx->hero->direction == UP_DIR)
		move_hero_up(mlx);
	else if (mlx->hero->direction == DOWN_DIR)
		move_hero_down(mlx);
	else if (mlx->hero->direction == LEFT_DIR)
		move_hero_left(mlx);
	else if (mlx->hero->direction == RIGHT_DIR)
		move_hero_right(mlx);
}

void	move_hero_right(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->hero->img[3].img_ptr,
		mlx->hero->pos_x, mlx->hero->pos_y);
	if (can_move_to(mlx->hero->pos_x + 26, mlx->hero->pos_y, mlx)
		&& can_move_to(mlx->hero->pos_x + 26, mlx->hero->pos_y +25, mlx))
	{
		mlx->hero->pos_x++;
		move_hero_sprites_right(mlx);
	}
}

void	move_hero_left(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->hero->img[2].img_ptr,
		mlx->hero->pos_x, mlx->hero->pos_y);
	if (can_move_to(mlx->hero->pos_x - 1, mlx->hero->pos_y, mlx)
		&& can_move_to(mlx->hero->pos_x - 1, mlx->hero->pos_y +25, mlx))
	{
		mlx->hero->pos_x--;
		move_hero_sprites_left(mlx);
	}
}

void	move_hero_down(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->hero->img[1].img_ptr,
		mlx->hero->pos_x, mlx->hero->pos_y);
	if (can_move_to(mlx->hero->pos_x, mlx->hero->pos_y +26, mlx)
		&& can_move_to(mlx->hero->pos_x + 25, mlx->hero->pos_y +26, mlx))
	{
		mlx->hero->pos_y++;
		move_hero_sprites_down(mlx);
	}
}

void	move_hero_up(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->hero->img[0].img_ptr,
		mlx->hero->pos_x, mlx->hero->pos_y);
	if (can_move_to(mlx->hero->pos_x, mlx->hero->pos_y - 1, mlx)
		&& can_move_to(mlx->hero->pos_x + 25, mlx->hero->pos_y - 1, mlx))
	{
		mlx->hero->pos_y--;
		move_hero_sprites_up(mlx);
	}		
}
