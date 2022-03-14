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

int	exit_game(t_mlx *mlx)
{
	free_memory_and_exit(mlx);
	return (0);
}

void	free_map_memory(t_mlx *mlx)
{
	int	count;

	count = 0;
	while (count < mlx->map_width)
	{
		free(mlx->map[count]);
		count++;
	}
	free(mlx->map);
}

void	free_general_images_memory(t_mlx *mlx)
{
	free(mlx->img);
	free(mlx->hero->img);
}

void	free_objects_memory(t_mlx *mlx)
{
	free(mlx->hero);
	free(mlx->enemys);
}

void	free_memory_and_exit(t_mlx *mlx)
{
	free_map_memory(mlx);
	free_general_images_memory(mlx);
	free_objects_memory(mlx);
	free(mlx);
	exit(0);
}
