/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:22:35 by irifarac          #+#    #+#             */
/*   Updated: 2023/02/10 13:09:15 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

# define BUFFER_SIZE 1
# define WIDTH 1080
# define HEIGHT 720

enum	e_ident
{
	A,
	C,
	L,
	sp,
	pl,
	cy
};

typedef struct s_ambient
{
	int	type;
}	t_ambient;

typedef struct s_object
{
	int	type;
}	t_object;

typedef struct s_alight
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
	float		z;
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
	t_ambient	*amb;
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

//Intersections
int			ft_intersects(t_ambient *amb, t_object *obj, t_vector ray_dir);
int			ft_inter_sphere(t_ambient *amb, t_object *obj, t_vector ray_dir);
int			ft_inter_plane(t_ambient *amb, t_plane *plane, t_vector ray_dir);
double		ft_distance_sphere(t_ambient *amb, t_sphere *sphere, t_vector
ray_dir);
//mlx functions
void		ft_init(t_ambient *amb, t_object *obj);
void		ft_generate(t_ambient *amb, t_object *obj, t_window *mlx);

//mlx util functions
int			ft_color_value(t_ambient *amb, int type);
void		ft_my_mlx_pxput(t_window *mlx, int x, int y, int color);

//Parser ambient
t_ambient	*ft_parseamb(char *str);
t_ambient	*ft_build_alight(t_ambient *amb, char *ftoken, char *eftoken);
t_ambient	*ft_build_cam(t_ambient *amb, char *ftoken, char *eftoken);
t_ambient	*ft_build_light(t_ambient *amb, char *ftoken, char *eftoken);
//Parser objects
t_object	*ft_parseobj(char *str);
t_object	*ft_build_sphere(t_object *obj, char *ftoken, char *eftoken);
t_object	*ft_build_plane(t_object *obj, char *ftoken, char *eftoken);
t_object	*ft_build_cylinder(t_object *obj, char *ftoken, char *eftoken);
//Errors
int			ft_check_error(char **str);
int			ft_error(const char *str, int ret);
int			ft_check_grammar(int fd);
//Utils
char		*ft_lines(char *str, int fd);
float		ft_fatoi(char **str);
int			ft_compare(char *str, char *tokens);
int			ft_atoi(char **str);
int			ft_find(char **str, char *estr, char *tokens);
int			ft_find_obj(char **str, char *estr, char *tokens);
size_t		ft_strlen(const char *str);
int			ft_strcmp(const char *str1, const char *str2);
int			ft_strncmp(const char *str1, const char *str2, size_t number);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		*ft_memcpy(void *dest, const void *src, size_t count);
char		*ft_strchr(const char *str, int ch);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_get_next_line(int fd);
int			ft_getident(char **str, char *estr, char **ftoken, char **eftoken);
int			ft_getobj(char **str, char *estr, char **ftoken, char **eftoken);
void		*ft_memset(void *dest, int ch, size_t count);
t_ambient	*ft_find_lst(t_ambient *amb, int type);
//Utils parameters
float		ft_ratio(char **ftoken, char *eftoken);
int			ft_color(char **ftoken, char *eftoken);
float		ft_coord(char **ftoken, char *eftoken);
float		ft_normal(char **ftoken, char *eftoken);
int			ft_fov(char **ftoken, char *eftoken);
float		ft_diameter(char **ftoken, char *eftoken);
//Utils list
t_object	*ft_find_lst_obj(t_object *obj, int type);
t_ambient	*ft_find_lst(t_ambient *amb, int type);
t_object	*ft_util_find(t_object *tmp, int type);
t_sphere	*ft_ret_sphere(t_object *obj, int type);
t_plane		*ft_ret_plane(t_object *obj, int type);
//Maths functions
double		ft_dot_product_vect(t_vector vector_left, t_vector vector_right);
t_vector	ft_rest_vect(t_vector origin, t_vector obj);
//Colors
int			ft_set_colour(t_ambient *amb, t_object *obj, t_colours *colours, int type);
#endif
