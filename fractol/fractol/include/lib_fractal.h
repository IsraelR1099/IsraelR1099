/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_fractal.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:09:43 by irifarac          #+#    #+#             */
/*   Updated: 2022/05/03 12:50:54 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	LIB_FRACTAL_H
# define LIB_FRACTAL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <limits.h>

# define HEIGHT	1280
# define WIDTH	720	

typedef struct	s_fractal
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		red;
	int		green;
	int		blue;
}	window;

typedef struct	s_points
{
	int		new_a;
	int		new_b;
	int		iter;
	int		i;
	double	x;
	double	y;
	double	a;
	double	b;
	double	a_temp;
	double	b_temp;
}	points;


double	ft_calcx(double a, double b, double x);
double	ft_calcy(double a, double b, double y);
int		key_event(int button, window *param);
int		ft_iterationMandelbrot(points *values, double x, double y);
int		ft_iterationJulia(points *values, double a_temp, double b_temp);
int		ft_strcmp(char *str1, char *str2);
int		create_rgb(int red, int green, int blue);
int		color_value(int iter, window *init);
void	generateImage(points *values, window *init, char *str);
void	ft_Mandelbrot(points *values, window *init);
void	ft_Julia(points *values, window *init);
void	my_mlx_pixel_put(window *init, int x, int y, int color);
void	ft_showOptions(void);

#endif
