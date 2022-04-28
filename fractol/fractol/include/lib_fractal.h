/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_fractal.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:09:43 by irifarac          #+#    #+#             */
/*   Updated: 2022/04/28 12:57:47 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	LIB_FRACTAL_H
# define LIB_FRACTAL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>

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
void	generatePoints(points *values, window *init);
void	my_mlx_pixel_put(window *init, int x, int y, int color);

#endif
