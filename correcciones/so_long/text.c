/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marza-ga <marza-ga-@student.42barcelo      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:59:00 by marza-ga          #+#    #+#             */
/*   Updated: 2022/03/04 22:17:00 by marza-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_centered_text_to_window(t_mlx *mlx, char *str)
{
	static int	time;
	int			str_len;
	int			width;
	int			height;

	str_len = ft_strlen(str) / 3;
	width = (mlx->map_width - str_len) * 26 / 2;
	height = mlx->map_height * 26 / 2;
	if (time <= 3200)
		mlx_string_put(mlx->mlx_ptr, mlx->win, width, height, 0xFFFFFF, str);
	++time;
}

void	place_text_to_window(t_mlx *mlx, char *str)
{
	int			str_len;
	int			width;
	int			height;

	str_len = ft_strlen(str) / 4;
	width = 12;
	height = (mlx->map_height * 26) + 18;
	mlx_string_put(mlx->mlx_ptr, mlx->win, width, height, 0xFFFFFF, str);
}

void	place_text_moves_to_window(t_mlx *mlx, char *str)
{
	int			width;
	int			height;

	width = 100;
	height = (mlx->map_height * 26) + 18;
	mlx_string_put(mlx->mlx_ptr, mlx->win, width, height, 0xFFFFFF, str);
}
