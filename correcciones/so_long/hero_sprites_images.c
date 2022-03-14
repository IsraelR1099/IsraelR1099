/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hero_sprites_images.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marza-ga <marza-ga-@student.42barcelo      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:59:00 by marza-ga          #+#    #+#             */
/*   Updated: 2022/03/04 22:17:00 by marza-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_sprites_images_right(t_mlx *m)
{
	int	hero_widht;
	int	hero_height;

	m->hero->img[5].img_ptr = mlx_xpm_file_to_image(m->mlx_ptr,
			"img/white-right-0.xpm", &hero_widht, &hero_height);
	m->hero->img[5].data = (int *)mlx_get_data_addr(m->hero->img[5].img_ptr,
			&m->hero->img[5].bpp, &m->hero->img[5].size_l,
			&m->hero->img[5].endian);
	m->hero->img[6].img_ptr = mlx_xpm_file_to_image(m->mlx_ptr,
			"img/white-right-l.xpm", &hero_widht, &hero_height);
	m->hero->img[6].data = (int *)mlx_get_data_addr(m->hero->img[6].img_ptr,
			&m->hero->img[6].bpp, &m->hero->img[6].size_l,
			&m->hero->img[6].endian);
	m->hero->img[7].img_ptr = mlx_xpm_file_to_image(m->mlx_ptr,
			"img/white-right-r.xpm", &hero_widht, &hero_height);
	m->hero->img[7].data = (int *)mlx_get_data_addr(m->hero->img[7].img_ptr,
			&m->hero->img[7].bpp, &m->hero->img[7].size_l,
			&m->hero->img[7].endian);
}

void	load_sprites_images_left(t_mlx *m)
{
	int	hero_widht;
	int	hero_height;

	m->hero->img[8].img_ptr = mlx_xpm_file_to_image(m->mlx_ptr,
			"img/white-left-0.xpm", &hero_widht, &hero_height);
	m->hero->img[8].data = (int *)mlx_get_data_addr(m->hero->img[8].img_ptr,
			&m->hero->img[8].bpp, &m->hero->img[8].size_l,
			&m->hero->img[8].endian);
	m->hero->img[9].img_ptr = mlx_xpm_file_to_image(m->mlx_ptr,
			"img/white-left-l.xpm", &hero_widht, &hero_height);
	m->hero->img[9].data = (int *)mlx_get_data_addr(m->hero->img[9].img_ptr,
			&m->hero->img[9].bpp, &m->hero->img[9].size_l,
			&m->hero->img[9].endian);
	m->hero->img[10].img_ptr = mlx_xpm_file_to_image(m->mlx_ptr,
			"img/white-left-r.xpm", &hero_widht, &hero_height);
	m->hero->img[10].data = (int *)mlx_get_data_addr(m->hero->img[10].img_ptr,
			&m->hero->img[10].bpp, &m->hero->img[10].size_l,
			&m->hero->img[10].endian);
}

void	load_sprites_images_up(t_mlx *m)
{
	int	hero_widht;
	int	hero_height;

	m->hero->img[11].img_ptr = mlx_xpm_file_to_image(m->mlx_ptr,
			"img/white-up-0.xpm", &hero_widht, &hero_height);
	m->hero->img[11].data = (int *)mlx_get_data_addr(m->hero->img[11].img_ptr,
			&m->hero->img[11].bpp, &m->hero->img[11].size_l,
			&m->hero->img[11].endian);
	m->hero->img[12].img_ptr = mlx_xpm_file_to_image(m->mlx_ptr,
			"img/white-up-l.xpm", &hero_widht, &hero_height);
	m->hero->img[12].data = (int *)mlx_get_data_addr(m->hero->img[12].img_ptr,
			&m->hero->img[12].bpp, &m->hero->img[12].size_l,
			&m->hero->img[12].endian);
	m->hero->img[13].img_ptr = mlx_xpm_file_to_image(m->mlx_ptr,
			"img/white-up-r.xpm", &hero_widht, &hero_height);
	m->hero->img[13].data = (int *)mlx_get_data_addr(m->hero->img[13].img_ptr,
			&m->hero->img[13].bpp, &m->hero->img[13].size_l,
			&m->hero->img[13].endian);
}

void	load_sprites_images_down(t_mlx *m)
{
	int	hero_widht;
	int	hero_height;

	m->hero->img[14].img_ptr = mlx_xpm_file_to_image(m->mlx_ptr,
			"img/white-down-0.xpm", &hero_widht, &hero_height);
	m->hero->img[14].data = (int *)mlx_get_data_addr(m->hero->img[14].img_ptr,
			&m->hero->img[14].bpp, &m->hero->img[14].size_l,
			&m->hero->img[14].endian);
	m->hero->img[15].img_ptr = mlx_xpm_file_to_image(m->mlx_ptr,
			"img/white-down-l.xpm", &hero_widht, &hero_height);
	m->hero->img[15].data = (int *)mlx_get_data_addr(m->hero->img[15].img_ptr,
			&m->hero->img[15].bpp, &m->hero->img[15].size_l,
			&m->hero->img[15].endian);
	m->hero->img[16].img_ptr = mlx_xpm_file_to_image(m->mlx_ptr,
			"img/white-down-r.xpm", &hero_widht, &hero_height);
	m->hero->img[16].data = (int *)mlx_get_data_addr(m->hero->img[16].img_ptr,
			&m->hero->img[16].bpp, &m->hero->img[16].size_l,
			&m->hero->img[16].endian);
}
