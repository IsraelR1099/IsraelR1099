/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_init_and_print_functions.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marza-ga <marza-ga-@student.42barcelo      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:59:00 by marza-ga          #+#    #+#             */
/*   Updated: 2022/03/04 22:17:00 by marza-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_0_tile(t_mlx *mlx, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win,
		mlx->img[0].img_ptr, x * 26, y * 26);
}

void	parse_1_tile(t_mlx *mlx, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win,
		mlx->img[1].img_ptr, x * 26, y * 26);
}

void	parse_p_tile(t_mlx *mlx, int x, int y)
{
	mlx->hero->pos_x = x * 26;
	mlx->hero->pos_y = y * 26;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win,
		mlx->img[1].img_ptr, x * 26, y * 26);
}

void	parse_c_tile(t_mlx *mlx, int x, int y)
{
	mlx->num_collectables++;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win,
		mlx->img[2].img_ptr, x * 26, y * 26);
}

void	parse_e_tile(t_mlx *mlx, int x, int y)
{
	mlx->exit_x = x * 26;
	mlx->exit_y = y * 26;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win,
		mlx->img[0].img_ptr, x * 26, y * 26);
}
