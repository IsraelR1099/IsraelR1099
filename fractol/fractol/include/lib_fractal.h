/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_fractal.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:09:43 by irifarac          #+#    #+#             */
/*   Updated: 2022/06/01 10:46:03 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_FRACTAL_H
# define LIB_FRACTAL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <limits.h>

# define HEIGHT	1280
# define WIDTH	720	
# define TC_NRM  "\x1B[0m"
# define TC_RED  "\x1B[1;31m"
# define TC_GRN  "\x1B[1;32m"
# define TC_YEL  "\x1B[1;33m"
# define TC_BLU  "\x1B[1;34m"
# define TC_MAG  "\x1B[1;35m"
# define TC_CYN  "\x1B[1;36m"
# define TC_WHT  "\x1B[1;37m"

typedef struct s_points
{
	int		nwa;
	int		nwb;
	int		iter;
	int		i;
	double	x;
	double	y;
	double	x_julia;
	double	y_julia;
	double	a;
	double	b;
	double	atmp;
	double	btmp;
	char	*fract_type;
}	t_points;

typedef struct s_fractal
{
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*addr;
	int			b;
	int			ll;
	int			end;
	int			tr;
	int			red;
	int			green;
	int			blue;
	double		z_x;
	double		z_y;
	int			trl_x;
	int			trl_y;
	int			max_iter;
	double		fr;
	double		fg;
	double		fb;
	int			sr;
	int			sg;
	int			sb;
	t_points	*inf;
}	t_window;

double			ft_calcx(double a, double b, double x);
double			ft_calcy(double a, double b, double y);
double			ft_calcx_3(double a, double b, double x);
double			ft_calcy_3(double a, double b, double y);
double			ft_calsinx(double a, double b, double x);
double			ft_calsiny(double a, double b, double y);
double			ft_calinx(double a, double b, double x, double y);
double			ft_caliny(double a, double b, double x, double y);
double			ft_calin3x(double a, double b, double x, double y);
double			ft_calin3y(double a, double b, double x, double y);
double			ft_glnx(double a, double b, double x);
double			ft_glny(double a, double b, double y);
int				key_event(int button, t_window *param);
int				ft_iter_mandel(t_window *init, double x, double y);
int				ft_ijulia(t_window *init, double a_temp, double b_temp);
int				ft_julg(t_window *init, double a_temp, double b_temp);
int				ft_ijul3(t_window *init, double atmp, double btmp);
int				ft_strcmp(char *str1, char *str2);
int				create_rgb(int tr, int red, int green, int blue);
int				color_value(int iter, t_window *init, char *str);
unsigned char	ft_color(double cnt_color, double fr, int shift);
int				init_variables(t_window *init, char *str);
int				ft_mouse_event(int button, int x, int y, t_window *init);
int				destroy_window(t_window *init);
float			ft_atoi(char *str, char c);
void			generate_image(t_window *init, char *str);
void			ft_mandelbrot(t_window *init);
void			ft_mandelbrot3(t_window *init);
void			ft_mandelbrot_inv(t_window *init);
void			ft_mandelbrot_inv3(t_window *init);
int				ft_iter_mandel3(t_window *init, double x, double y);
int				ft_iter_mandeli(t_window *init, double x, double y);
int				ft_iter_mandi3(t_window *init, double x, double y);
void			ft_julia3(t_window *init);
void			ft_julia(t_window *init);
void			ft_ijuliag(t_window *init);
void			my_mlx_pxput(t_window *init, int x, int y, int color);
void			all_hook(t_window *init);
void			ft_free(t_window *init);
void			ft_show_options(void);
void			reset_variables(t_window *init);
void			change_values(t_window *init);
void			ft_zoom_plus(t_window *init);
void			ft_zoom_less(int x, int y, t_window *init);
int				checker(char *str);

#endif
