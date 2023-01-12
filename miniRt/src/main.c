/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:21:31 by irifarac          #+#    #+#             */
/*   Updated: 2023/01/12 18:37:19 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"
#include "../mlx/mlx.h"

/*int	destroy(t_window *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	exit(0);
	return (1);
}*/

int	main(int counter, char **str)
{
/*	t_window	*mlx;

	mlx = (t_window *)malloc(sizeof(t_window));
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, 1080, 720, "Ejemplo");
	mlx_hook(mlx->mlx_win, 17,0, destroy, mlx);
	mlx_loop(mlx->mlx);*/
	if (counter == 2)
	{
		if (ft_error(str) >= 0)
			printf("hola\n");
	}
	else
		printf("Wrong number of arguments\n");
	return (0);
}
