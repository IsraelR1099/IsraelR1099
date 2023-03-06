/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:56:32 by irifarac          #+#    #+#             */
/*   Updated: 2023/03/06 13:59:13 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "../src/parser/parser.h"

# define WIDTH 1080
# define HEIGHT 720
# define PI 3.14

/*enum	e_ident
{
	A,
	C,
	L,
	sp,
	pl,
	cy
};

typedef struct	s_ambient
{
	int	type;
}	t_ambient;

typedef struct s_object
{
	int	type;
}	t_object;

ypedef struct s_alight
{
	int			type;
	int			r;
	int			g;
	int			b;
	float		ratio;
	t_ambient	*amb;
}	t_alight;

typedef struct s_light
{
	int			type;
	float		x;
	float		y;
	float		z;parser
	int			r;
	int			g;
	int			b;
	float		ratio;
	t_ambient	*amb;
}	t_light;

typedef struct s_cam
{
	int			type;
	float		x;
	float		y;
	float		z;
	int			x_normal;
	int			y_normal;
	int			z_normal;
	int			fov;
	t_ambient	*amb;parser
}	t_cam;

typedef struct	s_plane
{
	int			type;
	float		x;
	float		y;
	float		z;
	int			x_normal;
	int			y_normal;
	int			z_normal;
	int			r;
	int			g;
	int			b;
	t_object	*obj;
}	t_plane;

typedef struct	s_sphere
{
	int			type;
	float		x;
	float		y;
	float		z;
	float		diameter;
	int			r;
	int			g;
	int			b;
	t_object	*obj;
}	t_sphere;

typedef struct	s_cylinder
{
	int			type;
	float		x;
	float		y;
	float		z;
	int			x_normal;
	int			y_normal;
	int			z_normal;
	float		diameter;
	float		height;
	int			r;
	int			g;
	int			b;
	t_object	*obj;
}	t_cylinder;

typedef struct s_win
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		b;
	int		ll;
	int		end;
}	t_window;

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

typedef struct s_colour
{
	int	c_ambient;
	int	c_light;
	int	c_sphere;
	int	c_plane;
	int	c_cylinder;
}	t_colours;

typedef struct	s_frustum
{
	double	left;
	double	right;
	double	top;
	double	bottom;
	double	far;
	double	near;
}	t_frustrum;

typedef struct	s_4dvector
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_4dvector;*/

typedef struct	s_point2d
{
	double	x;
	double	y;
}	t_point2d;

typedef struct	s_vector3d
{
	double	x;
	double	y;
	double	z;
}	t_vector3d;

typedef struct	s_point3d
{
	double	x;
	double	y;
	double	z;
}	t_point3d;

typedef struct	s_ray
{
	t_point3d	origin;
	t_vector3d	direction;
}	t_ray;

void		ft_init(t_ambient *amb, t_object *obj);
void		ft_render(t_ambient *amb, t_object *obj, t_window *mlx);
void		ft_my_mlx_pxput(t_window *mlx, int x, int y, int colour);
t_ambient	*ft_find_amb(t_ambient *amb, int type);
#endif
