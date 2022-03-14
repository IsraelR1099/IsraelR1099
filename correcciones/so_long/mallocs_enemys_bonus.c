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

t_enemy	*init_enemies(t_mlx *mlx)
{
	int	count_x;
	int	count_y;
	int	count_enemys;

	count_x = 0;
	count_y = 0;
	count_enemys = 0;
	create_enemys_malloc(mlx);
	while (count_y < mlx->map_height)
	{
		while (count_x < mlx->map_width)
		{
			if (mlx->map[count_x][count_y] == 'N')
			{
				mlx->enemys[count_enemys].pos_x = count_x * 26;
				mlx->enemys[count_enemys].pos_y = count_y * 26;
				count_enemys++;
			}
			count_x++;
		}
		count_y++;
		count_x = 0;
	}
	return (mlx->enemys);
}

void	create_enemys_malloc(t_mlx *mlx)
{
	mlx->enemys = malloc(sizeof(t_enemy) * (mlx->num_enemys));
	if (!mlx->enemys)
	{
		free_map_memory(mlx);
		free(mlx->img);
		free(mlx->hero->img);
		free(mlx->hero);
		free(mlx);
		write(2, "Error\nNot enought memory for malloc", 35);
		exit(0);
	}
}
