/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits_images.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marza-ga <marza-ga-@student.42barcelo      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:59:00 by marza-ga          #+#    #+#             */
/*   Updated: 2022/03/04 22:17:00 by marza-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map_images(t_mlx *mlx)
{
	int	tile_widht;
	int	tile_height;

	create_malloc_map_images(mlx);
	mlx->img[0].img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"img/green-sheet.xpm", &tile_widht, &tile_height);
	mlx->img[0].data = (int *)mlx_get_data_addr(mlx->img[0].img_ptr,
			&mlx->img[0].bpp, &mlx->img[0].size_l, &mlx->img[0].endian);
	mlx->img[1].img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"img/grey-tile.xpm", &tile_widht, &tile_height);
	mlx->img[1].data = (int *)mlx_get_data_addr(mlx->img[1].img_ptr,
			&mlx->img[1].bpp, &mlx->img[1].size_l, &mlx->img[1].endian);
	mlx->img[5].img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"img/clear_score.xpm", &tile_widht, &tile_height);
	mlx->img[5].data = (int *)mlx_get_data_addr(mlx->img[5].img_ptr,
			&mlx->img[5].bpp, &mlx->img[5].size_l, &mlx->img[5].endian);
}

void	init_items_images(t_mlx *mlx)
{
	int	tile_widht;
	int	tile_height;

	mlx->img[2].img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"img/item-bomb.xpm", &tile_widht, &tile_height);
	mlx->img[2].data = (int *)mlx_get_data_addr(mlx->img[2].img_ptr,
			&mlx->img[2].bpp, &mlx->img[2].size_l, &mlx->img[2].endian);
	mlx->img[4].img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"img/exit-5.xpm", &tile_widht, &tile_height);
	mlx->img[4].data = (int *)mlx_get_data_addr(mlx->img[4].img_ptr,
			&mlx->img[4].bpp, &mlx->img[4].size_l, &mlx->img[4].endian);
}

void	init_enemy_images(t_mlx *mlx)
{
	int	tile_widht;
	int	tile_height;

	mlx->img[3].img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"img/ennemy-down-0.xpm", &tile_widht, &tile_height);
	mlx->img[3].data = (int *)mlx_get_data_addr(mlx->img[3].img_ptr,
			&mlx->img[3].bpp, &mlx->img[3].size_l, &mlx->img[3].endian);
}
