/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:48:20 by irifarac          #+#    #+#             */
/*   Updated: 2022/04/25 14:28:51 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "mlx/mlx.h"

#define Rojo		0xff0000
#define	Amarillo	0xffff00
#define	Verde		0x008000
#define	Azul		0x0000ff
#define	Negro		0x000000
#define	Blanco		0xffffff

typedef struct	s_program
{
	void	*mlx;
	void	*mlx_win;
}	window;

int	key_event(int button, window *param)
{
	if (button == 53)
		mlx_destroy_window(param->mlx, param->mlx_win);
	return (1);
}

double	ft_calcx(double a, double b, double x)
{
	double	result;

	result = pow(a, 2) - pow(b, 2) + x;
	return (result);
}

double	ft_calcy(double a, double b, double y)
{
	double	result;

	result = (2 * a * b) + y;
	return (result);
}

int	main(void)
{
	window	*new;
	double	x;
	double	y;
	double	a;
	double	b;
	double	a_temp;
	double	b_temp;
	int		new_a;
	int		new_b;
	int		i;
	int		iter;

	//Inicializar
	new = (window *)malloc(sizeof(window));
	if (!new)
		return (0);
	new->mlx = mlx_init();
	//Crear ventana
	new->mlx_win = mlx_new_window(new->mlx, 1920, 1080, "Mandelbrot set");
	//Capturar evento del teclado
	mlx_key_hook(new->mlx_win, key_event, new);

	//Crear lineas
	//Eje de las abscisas	
	x = 0;
	y = 540;
	while (x <= 1920)
		mlx_pixel_put(new->mlx, new->mlx_win, x++, y, Blanco);
	x = 960;
	while (x >= 0)
	{
		y = 535;
		while (y <= 545)
			mlx_pixel_put(new->mlx, new->mlx_win, x, y++, Blanco);
		x -= 180;
	}
	x = 960;
	while (x <= 1740)
	{
		y = 535;
		while (y <= 545)
			mlx_pixel_put(new->mlx, new->mlx_win, x, y++, Blanco);
		x += 180;
	}
	//Eje de las ordenadas
	x = 960;
	y = 0;

	while (y <= 1080)
		mlx_pixel_put(new->mlx, new->mlx_win, x, y++, Blanco);
	y = 180;
	while (y <= 900)
	{
		x = 955;
		while (x <= 965)
			mlx_pixel_put(new->mlx, new->mlx_win, x++, y, Blanco);
		y += 180;
	}

	//Centro
	mlx_pixel_put(new->mlx, new->mlx_win, 960, 540, Rojo);

	//Crear una circunferencia
	double	angulo;
	double	radio;
	double	ejex;
	double	ejey;

	radio = 36;
	angulo = 1;
	while (angulo < 360)
	{
		ejex = cos(angulo) * radio;
		ejey = sin(angulo) * radio;
		mlx_pixel_put(new->mlx, new->mlx_win, (ejex * 10) + 960, (ejey * 10) + 540, Blanco);
	   angulo++;
	}
	//Puntos
	
	a_temp = 0;
	b_temp = 0;
	x = 0;
	y = 0;
	i = 1;
	iter = 0;

	while (y <= 2)
	{
		new_a = x;
		new_b = y;
		new_a = 960 + (x * 360);
		new_b = 540 - (y * 360);
		while (iter < 3)
		{
			printf("x es %f y es %f\n", x, y);
			a = ft_calcx(a_temp, b_temp, x);
			b = ft_calcy(a_temp, b_temp, y);
			a_temp = a;
			b_temp = b;
			printf("a es %f y b es %f\n", a, b);
			iter++;
		}
		if (sqrt((pow(a, 2) + pow(b, 2))) > 2)
			mlx_pixel_put(new->mlx, new->mlx_win, new_a, new_b, Azul);
		else
			mlx_pixel_put(new->mlx, new->mlx_win, new_a, new_b, Rojo);
		if (i == 200 || x == 2)
		{
			y += 0.125;
			x = 0;
			i = 0;
		}
		x += 0.125;
		i++;
		iter = 0;
		a_temp = 0;
		b_temp = 0;
	}
	mlx_loop(new->mlx);
	return (0);
}
