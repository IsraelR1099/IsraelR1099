/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:22:35 by irifarac          #+#    #+#             */
/*   Updated: 2023/01/27 20:55:56 by irifarac         ###   ########.fr       */
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
	int	b;
	int	ll;
	int	end;
}	t_window;

//mlx functions
void		ft_init(t_ambient *amb, t_object *obj);
void		ft_generate(t_ambient *amb, t_object *obj, t_window *mlx);

//mlx util functions
int		ft_color_value(t_light *light);
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
//Utils parameters
float		ft_ratio(char **ftoken, char *eftoken);
int			ft_color(char **ftoken, char *eftoken);
float		ft_coord(char **ftoken, char *eftoken);
float		ft_normal(char **ftoken, char *eftoken);
int			ft_fov(char **ftoken, char *eftoken);
float		ft_diameter(char **ftoken, char *eftoken);

#endif
