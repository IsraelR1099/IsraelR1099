/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hero_basic_images.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marza-ga <marza-ga-@student.42barcelo      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:59:00 by marza-ga          #+#    #+#             */
/*   Updated: 2022/03/04 22:17:00 by marza-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_basic_hero_images(t_mlx *mlx)
{
	int	hero_widht;
	int	hero_height;

	mlx->hero->img[0].img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"img/white-up-0.xpm", &hero_widht, &hero_height);
	mlx->hero->img[0].data = (int *)mlx_get_data_addr(mlx->hero->img[0].img_ptr,
			&mlx->hero->img[0].bpp, &mlx->hero->img[0].size_l,
			&mlx->hero->img[0].endian);
	mlx->hero->img[1].img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"img/white-down-0.xpm", &hero_widht, &hero_height);
	mlx->hero->img[1].data = (int *)mlx_get_data_addr(mlx->hero->img[1].img_ptr,
			&mlx->hero->img[1].bpp, &mlx->hero->img[1].size_l,
			&mlx->hero->img[1].endian);
	mlx->hero->img[2].img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"img/white-left-0.xpm", &hero_widht, &hero_height);
	mlx->hero->img[2].data = (int *)mlx_get_data_addr(mlx->hero->img[2].img_ptr,
			&mlx->hero->img[2].bpp, &mlx->hero->img[2].size_l,
			&mlx->hero->img[2].endian);
	mlx->hero->img[3].img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"img/white-right-0.xpm", &hero_widht, &hero_height);
	mlx->hero->img[3].data = (int *)mlx_get_data_addr(mlx->hero->img[3].img_ptr,
			&mlx->hero->img[3].bpp, &mlx->hero->img[3].size_l,
			&mlx->hero->img[3].endian);
}

void	load_basic_hero_images2(t_mlx *mlx)
{
	int	hero_widht;
	int	hero_height;

	mlx->hero->img[4].img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"img/white-dead-0.xpm", &hero_widht, &hero_height);
	mlx->hero->img[4].data = (int *)mlx_get_data_addr(mlx->hero->img[4].img_ptr,
			&mlx->hero->img[4].bpp, &mlx->hero->img[4].size_l,
			&mlx->hero->img[4].endian);
}
