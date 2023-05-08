/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 09:40:54 by irifarac          #+#    #+#             */
/*   Updated: 2023/05/08 10:09:09 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <limits.h>

# define BUFFER_SIZE 1

enum	e_ident
{
	A,
	C,
	L,
	sp,
	pl,
	cy,
	di
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
	double		r;
	double		g;
	double		b;
	float		ratio;
	t_ambient	*amb;
}	t_alight;

typedef struct s_light
{
	int			type;
	float		x;
	float		y;
	float		z;
	double		r;
	double		g;
	double		b;
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

typedef struct s_plane
{
	int			type;
	float		x;
	float		y;
	float		z;
	int			x_normal;
	int			y_normal;
	int			z_normal;
	double		r;
	double		g;
	double		b;
	t_object	*obj;
}	t_plane;

typedef struct s_sphere
{
	int			type;
	float		x;
	float		y;
	float		z;
	float		diameter;
	double		r;
	double		g;
	double		b;
	t_object	*obj;
}	t_sphere;

typedef struct s_cylinder
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
	double		r;
	double		g;
	double		b;
	t_object	*obj;
}	t_cylinder;

typedef struct s_disk
{
	int			type;
	float		x;
	float		y;
	float		z;
	int			x_normal;
	int			y_normal;
	int			z_normal;
	float		radius;
	double		r;
	double		g;
	double		b;
	t_object	*obj;
}	t_disk;

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

typedef struct s_frustum
{
	double	left;
	double	right;
	double	top;
	double	bottom;
	double	far;
	double	near;
}	t_frustrum;

typedef struct s_4dvector
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_4dvector;

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
t_object	*ft_build_disk(t_object *obj, char *ftoken, char *eftoken);
//Errors
int			ft_check_error(char **str);
int			ft_error(const char *str, int ret);
int			ft_check_grammar(int fd);
int			ft_check_id(char *str);
int			ft_leftovers(char *ftoken, char *eftoken);
//Utils
int			ft_strcmp(const char *str1, const char *str2);
int			ft_strncmp(const char *str1, const char *str2, size_t number);
int			ft_find(char **str, char *estr, char *tokens);
int			ft_find_obj(char **str, char *estr, char *tokens);
int			ft_getident(char **str, char *estr, char **ftoken, char **eftoken);
int			ft_getobj(char **str, char *estr, char **ftoken, char **eftoken);
int			ft_atoi(char **str);
int			ft_compare(char *str, char *tokens);
float		ft_fatoi(char **str);
size_t		ft_strlen(const char *str);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strchr(const char *str, int ch);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_get_next_line(int fd);
void		*ft_memcpy(void *dest, const void *src, size_t count);
void		*ft_memset(void *dest, int ch, size_t count);
//Utils parameters
int			ft_color(char **ftoken, char *eftoken);
int			ft_fov(char **ftoken, char *eftoken);
float		ft_ratio(char **ftoken, char *eftoken);
float		ft_coord(char **ftoken, char *eftoken);
float		ft_normal(char **ftoken, char *eftoken);
float		ft_diameter(char **ftoken, char *eftoken);

#endif
