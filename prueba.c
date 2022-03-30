/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 13:26:48 by irifarac          #+#    #+#             */
/*   Updated: 2022/03/30 14:31:33 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_program
{
	void	*mlx;
	void	*mlx_win;
}	window;

int	mouse_event(int button, window *param)
{

	if (!param)
		write(1, "null aqui", 6);
	if (button == 4 || button == 5)
	{
		printf("soy %d\n", button);
		if (!param && param->mlx != NULL && param->mlx_win != NULL)
			mlx_string_put(param->mlx, param->mlx_win, 200, 200, 0xFF0000, "holaaa!!!");
	}
	write(1, &button, 1);	
	return (1);
}

int	key_event(int button, void *param)
{
	window	*key = param;

	printf("%d\n", button);
	if (button == 53)
		mlx_destroy_window(key->mlx, key->mlx_win);
	return (1);
}

int	main(void)
{
	int		put_pix;
	int		x;
	int		y;
	void	*image;
	int		bit_per_pixel;
	int		size_line;
	int		endian;
	char	*data_img;
	window	*new;

	//Inicializar
	new = (window *)malloc(sizeof(window));
	if (!new)
		return (0);
	new->mlx = mlx_init();
	//Crear ventana
	new->mlx_win = mlx_new_window(new->mlx, 500, 500, "Hello world!");
	x = 0;
	y = 0;
	//Crear lineas
	while (x <= 500 && y <= 500)
		put_pix = mlx_pixel_put(new->mlx, new->mlx_win, x++, y++, 0xABCDEF);
	x = 0;
	y = 250;
	while (x <= 500)
		put_pix = mlx_pixel_put(new->mlx, new->mlx_win, x++, y, 0xABCDEF);
	x = 0;
	y = 500;
	while (x <= 500 && y >= 0)
		put_pix = mlx_pixel_put(new->mlx, new->mlx_win, x++, y--, 0xABCDEF);
	while (x <= 250 && y <= 250)
		put_pix = mlx_pixel_put(new->mlx, new->mlx_win, x++, y--, 0xABCDEF);
	x = 250;
	y = 0;
	while (y <= 500 && x == 250)
		put_pix = mlx_pixel_put(new->mlx, new->mlx_win, x, y++, 0xABCDEF);

	//Crear una imagen
	image = mlx_new_image(new->mlx, 100, 100);
	//Informacion de la imagen
	data_img = mlx_get_data_addr(image, &bit_per_pixel, &size_line, &endian);
	size_line /= 4;
	int color = 0xABCDEF;
	for (int y = 0; y < 250; ++y)
		for (int x = 0; x <= 250; ++x)
		{
			data_img[(y * size_line) + x] = color;
		}
	mlx_put_image_to_window(new->mlx, new->mlx_win, image, 250, 250);
	//Capturar un evento del mouse
	mlx_mouse_hook(new->mlx_win, &mouse_event, new);
	//Capturar un evento del teclado
	mlx_key_hook(new->mlx_win, &key_event, new);
	mlx_string_put(new->mlx, new->mlx_win, 250, 250, 0xFF0000, "hola");
	mlx_loop(new->mlx);
}
