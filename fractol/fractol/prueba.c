/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 13:26:48 by irifarac          #+#    #+#             */
/*   Updated: 2022/03/29 13:43:38 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	int		put_pix;
	int		x;
	int		y;
	void	*image;
	int		bit_per_pixel;
	int		size_line;
	int		endian;
	char	*data_img;

	//Inicializar
	mlx = mlx_init();
	//Crear ventana
	mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");
	x = 0;
	y = 0;
	//Crear lineas
	while (x <= 500 && y <= 500)
		put_pix = mlx_pixel_put(mlx, mlx_win, x++, y++, 0xABCDEF);
	x = 0;
	y = 250;
	while (x <= 500)
		put_pix = mlx_pixel_put(mlx, mlx_win, x++, y, 0xABCDEF);
	x = 0;
	y = 500;
	while (x <= 500 && y >= 0)
		put_pix = mlx_pixel_put(mlx, mlx_win, x++, y--, 0xABCDEF);
	while (x <= 250 && y <= 250)
		put_pix = mlx_pixel_put(mlx, mlx_win, x++, y--, 0xABCDEF);
	x = 250;
	y = 0;
	while (y <= 500 && x == 250)
		put_pix = mlx_pixel_put(mlx, mlx_win, x, y++, 0xABCDEF);

	//Crear una imagen
	image = mlx_new_image(mlx, 100, 100);
	//Informacion de la imagen
	data_img = mlx_get_data_addr(image, &bit_per_pixel, &size_line, &endian);
	mlx_loop(mlx);
}
