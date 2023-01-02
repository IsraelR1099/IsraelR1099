/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:21:31 by irifarac          #+#    #+#             */
/*   Updated: 2023/01/02 13:05:08 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"
#include "../mlx/mlx.h"

#define ejeY 720
#define ejeX 1080

int	destroy(t_window *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	exit(0);
	return (1);
}

int	main(void)
{
	t_window	*mlx;

	mlx = (t_window *)malloc(sizeof(t_window));
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, 1080, 720, "Ejemplo");
	mlx_pixel_put(mlx->mlx, mlx->mlx_win, 1080 /2, 720 /2, 0xFF);
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ejeY / 2)
		mlx_pixel_put(mlx->mlx, mlx->mlx_win, ejeX / 2 , i++, 0xFF);
	i = ejeX / 2;
	while (i < ejeX)
		mlx_pixel_put(mlx->mlx, mlx->mlx_win, i++ , ejeY / 2, 0xFF);
	mlx_hook(mlx->mlx_win, 17,0, destroy, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
