/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 13:26:48 by irifarac          #+#    #+#             */
/*   Updated: 2022/04/05 14:07:43 by irifarac         ###   ########.fr       */
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


typedef struct	s_program
{
	void	*mlx;
	void	*mlx_win;
}	window;

int	mouse_event(int button, int x, int y, window *param)
{
	(void)x;
	(void)y;
	printf("button es %d\n", button);
	if (button == 4)
			mlx_pixel_put(param->mlx, param->mlx_win, 151, 146, 0xFF0000);
	if (button == 5)
			mlx_string_put(param->mlx, param->mlx_win, 250, 250, 0xABCDEF, "hola");
	return (1);
}

int	key_event(int button, window *param)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (button == 0)
		while (x <= 100 && y <= 100)
			mlx_pixel_put(param->mlx, param->mlx_win, x++, y++, 0xFF0000);
	if (button == 53)
		mlx_destroy_window(param->mlx, param->mlx_win);
	return (1);
}

double	ft_calcx(double a, double b, double x)
{
	double	result;

//	printf("!!!!en calcx a es %f y b es %f y x es %f\n", a, b, x);
	result = pow(a, 2) - pow(b, 2) + x;
//	printf("resultado sin alterar en x es %f\n", result);
//	printf("result es %f\n", result);
	return (result);
}

double	ft_calcy(double a, double b, double y)
{
	double	result;

//	printf("@@@en calcy a es %f y b es %f y y es %f\n", a, b, y);
	result = (2 * a * b) + y;
//	printf("resultado sin alterar en y es %f\n", result);
//	printf("result y es %f\n", result);
	return (result);
}

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
//	void	*image;
//	int		bit_per_pixel;
//	int		size_line;
//	int		endian;
//	char	*data_img;
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
	
	//punto z sub 0 = 0,5 + 0,7i y c = -0.25 + 0.25i
	mlx_pixel_put(new->mlx, new->mlx_win, 255, 243, Rojo);

	//Calculo de puntos de julia
	//Punto z sub 1
/*	x = ft_calcx(0.5, 0.7, -0.25);
	y = ft_calcy(0.5, 0.7, 0.25);
	x_temp = x;
	y_temp = y;
	new_x = 250 + (x * 10);
	new_y = 250 - (y * 10);
	mlx_pixel_put(new->mlx, new->mlx_win, new_x, new_y, Rojo);
	//Punt z sub2
	x = ft_calcx(x_temp, y_temp, -0.25);
	y = ft_calcy(x_temp, y_temp, 0.25);
	new_x = 250 + (x * 10);
	new_y = 250 - (y * 10);
	mlx_pixel_put(new->mlx, new->mlx_win, new_x, new_y, Rojo);
*/

	// valores de z
	a_temp = 0.5;
	b_temp = 0.7;
	//valores de c
	x = -0.25;
	y = 0.25;
	i = 0;
	while (i < 6)
	{
		a = ft_calcx(a_temp, b_temp, x);
		b = ft_calcy(a_temp, b_temp, y);
		a_temp = a;
		b_temp = b;
		new_a = 250 + (a * 10);
		new_b = 250 - (b * 10);
		mlx_pixel_put(new->mlx, new->mlx_win, new_a, new_b, Rojo);
		i++;
	}
	a_temp = 0.6;
	b_temp = 0.8;
	x = -0.5;
	y = 0.5;
	i = 0;
	while (i < 8)
	{
		a = ft_calcx(a_temp, b_temp, x);
		b = ft_calcy(a_temp, b_temp, y);
		a_temp = a;
		b_temp = b;
		new_a = 250 + (a * 10);
		new_b = 250 - (b * 10);
		mlx_pixel_put(new->mlx, new->mlx_win, new_a, new_b, Azul);
		i++;
	}
	//Mandelbrot set
	


	//Crear una circunferencia
	double	angulo;
	double	radio;
	double	ejex;
	double	ejey;

	radio = 2,0;
	angulo = 1;
	while (angulo < 360)
	{
		ejex = cos(angulo) * radio;
		ejey = sin(angulo) * radio;
		put_pix = mlx_pixel_put(new->mlx, new->mlx_win, (ejex * 10) + 250, (ejey * 10) + 250, 0xABCDEF);
		angulo++;
	}
	printf("put pix es %d\n", put_pix);
	//Crear una imagen
/*	image = mlx_new_image(new->mlx, 100, 100);
	//Informacion de la imagen
	data_img = mlx_get_data_addr(image, &bit_per_pixel, &size_line, &endian);
	size_line /= 4;
	int color = 0xABCDEF;
	for (int y = 0; y < 250; ++y)
		for (int x = 0; x <= 250; ++x)
		{
			data_img[(y * size_line) + x] = color;
		}
	mlx_put_image_to_window(new->mlx, new->mlx_win, image, 250, 250);*/
	//Capturar un evento del mouse
	mlx_hook(new->mlx_win, 4, 1L << 4, mouse_event, new);
	mlx_hook(new->mlx_win, 5, 1L << 3, mouse_event, new);
	//Capturar un evento del teclado
	mlx_key_hook(new->mlx_win, key_event, new);
	mlx_loop(new->mlx);
}
