/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marza-ga <marza-ga-@student.42barcelo      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:59:00 by marza-ga          #+#    #+#             */
/*   Updated: 2022/03/04 22:17:00 by marza-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	input(int key, t_mlx *mlx)
{	
	if (key == ESC)
		exit_game(mlx);
	else if (key == KEY_UP)
		input_is_key_up(mlx);
	else if (key == KEY_DOWN)
		input_is_key_down(mlx);
	else if (key == KEY_LEFT)
		input_is_key_left(mlx);
	else if (key == KEY_RIGHT)
		input_is_key_right(mlx);
	return (1);
}

void	input_is_key_up(t_mlx *mlx)
{
	if (mlx->hero->direction != UP_DIR)
		count_another_move(mlx);
	mlx->hero->direction = UP_DIR;
}

void	input_is_key_down(t_mlx *mlx)
{
	if (mlx->hero->direction != DOWN_DIR)
		count_another_move(mlx);
	mlx->hero->direction = DOWN_DIR;
}

void	input_is_key_left(t_mlx *mlx)
{
	if (mlx->hero->direction != LEFT_DIR)
		count_another_move(mlx);
	mlx->hero->direction = LEFT_DIR;
}

void	input_is_key_right(t_mlx *mlx)
{
	if (mlx->hero->direction != RIGHT_DIR)
		count_another_move(mlx);
	mlx->hero->direction = RIGHT_DIR;
}
