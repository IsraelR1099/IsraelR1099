/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_fractal.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:09:43 by irifarac          #+#    #+#             */
/*   Updated: 2022/05/12 13:59:49 by irifarac         ###   ########.fr       */
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

typedef struct	s_points
{
	int		new_a;
	int		new_b;
	int		iter;
	int		i;
	double	x;
	double	y;
	double	x_julia;
	double	y_julia;
	double	a;
	double	b;
	double	a_temp;
	double	b_temp;
	char	*fract_type;
}	points;

typedef struct	s_fractal
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		b;
	int		ll;
	int		end;
	int		tr;
	int		red;
	int		green;
	int		blue;
	double	zoom_x;
	double	zoom_y;
	int		trl_x;
	int		trl_y;
	int		max_iter;
	points	*values;
}	window;



double	ft_calcx(double a, double b, double x);
double	ft_calcy(double a, double b, double y);
double	ft_calcx_3(double a, double b, double x);
double	ft_calcy_3(double a, double b, double y);
int		key_event(int button, window *param);
int		ft_iteration_mandelbrot(window *init, double x, double y);
int		ft_iteration_julia(window *init, double a_temp, double b_temp);
int		ft_strcmp(char *str1, char *str2);
int		create_rgb(int tr, int red, int green, int blue);
int		color_value(int iter, window *init);
int		init_variables(window *init, char *str);
int		ft_mouse_event(int button, int x, int y, window *init);
float	ft_atoi(char *str);
void	generate_image(window *init, char *str);
void	ft_mandelbrot(window *init);
void	ft_julia(window *init);
void	my_mlx_pixel_put(window *init, int x, int y, int color);
void	ft_show_options(char *str);

#endif
