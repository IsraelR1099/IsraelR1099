/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemys.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marza-ga <marza-ga-@student.42barcelo      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:59:00 by marza-ga          #+#    #+#             */
/*   Updated: 2022/03/04 22:17:00 by marza-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_n_tile(t_mlx *mlx, int x, int y)
{
	mlx->num_enemys++;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win,
		mlx->img[3].img_ptr, x * 26, y * 26);
}

int	check_enemy_collition(t_mlx *mlx, int enemy_nbr)
{
	if (mlx->hero->pos_x + 26 >= mlx->enemys[enemy_nbr].pos_x
		&& mlx->hero->pos_x <= mlx->enemys[enemy_nbr].pos_x + 26
		&& mlx->hero->pos_y + 26 >= mlx->enemys[enemy_nbr].pos_y
		&& mlx->hero->pos_y <= mlx->enemys[enemy_nbr].pos_y + 26)
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win,
			mlx->hero->img[4].img_ptr, mlx->hero->pos_x, mlx->hero->pos_y);
		mlx->hero->alive = 0;
		place_centered_text_to_window(mlx, "MINILIBX HAS KILLED YOU!!!");
		return (1);
	}
	return (0);
}

int	enemy_can_move_to(int x, int y, t_mlx *mlx)
{
	if (mlx->map[x / 26][y / 26] == '0'
		|| mlx->map[x / 26][y / 26] == 'P'
		|| mlx->map[x / 26][y / 26] == 'N')
		return (1);
	return (0);
}

void	switch_enemy_dir(t_mlx *mlx, int count)
{
	if (mlx->enemys[count].direction != RIGHT_DIR)
		mlx->enemys[count].direction = RIGHT_DIR;
	else if (mlx->enemys[count].direction != LEFT_DIR)
		mlx->enemys[count].direction = LEFT_DIR;
	else if (mlx->enemys[count].direction != UP_DIR)
		mlx->enemys[count].direction = UP_DIR;
	else if (mlx->enemys[count].direction != DOWN_DIR)
		mlx->enemys[count].direction = DOWN_DIR;
}

void	move_enemys(t_mlx *mlx)
{
	int	count;

	count = 0;
	while (count < mlx->num_enemys)
	{
		if (mlx->enemys[count].direction == RIGHT_DIR)
		{
			move_enemy_right(mlx, count);
		}
		else if (mlx->enemys[count].direction == LEFT_DIR)
		{
			move_enemy_left(mlx, count);
		}
		else if (mlx->enemys[count].direction == DOWN_DIR)
		{
			move_enemy_down(mlx, count);
		}
		else if (mlx->enemys[count].direction == UP_DIR)
		{
			move_enemy_up(mlx, count);
		}
		else
			switch_enemy_dir(mlx, count);
		count++;
	}
}
