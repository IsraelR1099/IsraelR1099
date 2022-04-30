/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 13:26:48 by irifarac          #+#    #+#             */
/*   Updated: 2022/04/29 14:30:22 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>


#define	Rojo		0xff0000
#define	Amarillo	0xffff00
#define	Verde		0x008000
#define	Azul		0x0000ff
#define Negro		0x000000


int	main(void)
{
	int		put_pix;
	double	x;
	double	y;
	double	a;
	double	b;
	double	a_temp;
	double	b_temp;
	int		new_a;
	int		new_b;
	int		i;
	window	*new;

	//Inicializar
	new = (window *)malloc(sizeof(window));
	if (!new)
		return (0);
	new->mlx = mlx_init();
	//Crear ventana
	new->mlx_win = mlx_new_window(new->mlx, 500, 500, "Hello world!");
	//Crear lineas
	x = 0;
	y = 250;
	while (x <= 500)
		put_pix = mlx_pixel_put(new->mlx, new->mlx_win, x++, y, 0xABCDEF);
	x = 250;
	y = 0;
	while (y <= 500 && x == 250)
		put_pix = mlx_pixel_put(new->mlx, new->mlx_win, x, y++, 0xABCDEF);
	//linea de las abscisas
	x = 10;
	while (x <= 490)
	{
		y = 245;
		while (y <= 255)
		{
			put_pix = mlx_pixel_put(new->mlx, new->mlx_win, x, y, 0xABCDEF);
			y++;
		}
		x += 10;
	}
	//linea de las ordenadas
	y = 10;
	while (y <= 490)
	{
		x = 245;
		while (x <= 255)
		{
			put_pix = mlx_pixel_put(new->mlx, new->mlx_win, x, y, 0xABCDEF);
			x++;
		}
		y += 10;
	}
	printf("put pix es %d\n", put_pix);
	


	mlx_put_image_to_window(new->mlx, new->mlx_win, image, 250, 250);
	//Capturar un evento del mouse
	mlx_hook(new->mlx_win, 4, 1L << 4, mouse_event, new);
	mlx_hook(new->mlx_win, 5, 1L << 3, mouse_event, new);
	//Capturar un evento del teclado
	mlx_key_hook(new->mlx_win, key_event, new);
	mlx_loop(new->mlx);
}
