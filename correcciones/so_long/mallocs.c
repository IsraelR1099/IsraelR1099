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

void	create_map_x_malloc(t_mlx *mlx)
{
	mlx->map = (char **)malloc(sizeof(char *) * (mlx->map_width + 1));
	if (!mlx->map)
	{
		free(mlx);
		write(2, "Error\nNot enought memory for malloc", 35);
		exit(0);
	}
}

char	*create_map_y_malloc(t_mlx *mlx, int count)
{
	char	*temp;

	temp = (char *)malloc(sizeof(char) * (mlx->map_height + 1));
	if (!temp)
	{
		count--;
		while (count >= 0)
		{
			free(mlx->map[count]);
			count--;
		}
		free(mlx->map);
		free(mlx);
		write(2, "Error\nNot enought memory for malloc", 35);
		exit(0);
	}
	return (temp);
}

void	create_malloc_map_images(t_mlx *mlx)
{
	mlx->img = malloc(sizeof(t_img) * 6);
	if (!mlx->img)
	{
		free_map_memory(mlx);
		free(mlx);
		write(2, "Error\nNot enought memory for malloc", 35);
		exit(0);
	}
}

t_hero	*create_hero_malloc(t_mlx *mlx)
{
	t_hero	*temp;

	temp = (t_hero *)malloc(sizeof(t_hero));
	if (!temp)
	{
		free_map_memory(mlx);
		free(mlx->img);
		free(mlx);
		write(2, "Error\nNot enought memory for malloc", 35);
		exit(0);
	}
	return (temp);
}

t_img	*create_hero_images_malloc(t_mlx *mlx)
{
	t_img	*temp;

	temp = malloc(sizeof(t_img) * 20);
	if (!temp)
	{
		free_map_memory(mlx);
		free(mlx->img);
		free(mlx->hero);
		free(mlx);
		write(2, "Error\nNot enought memory for malloc", 35);
		exit(0);
	}
	return (temp);
}
