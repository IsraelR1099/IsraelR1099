/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_fractal.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:09:43 by irifarac          #+#    #+#             */
/*   Updated: 2022/04/30 13:33:45 by irifarac         ###   ########.fr       */
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
int		ft_strcmp(char *str1, char *str2);
void	generateImage(points *values, window *init, char *str);
void	ft_Mandelbrot(points *values, window *init);
void	ft_Julia(points *values, window *init, char *str);
void	my_mlx_pixel_put(window *init, int x, int y, int color);
void	ft_showOptions(void);

#endif
