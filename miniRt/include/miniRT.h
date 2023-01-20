/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:22:35 by irifarac          #+#    #+#             */
/*   Updated: 2023/01/20 14:01:31 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

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
	int		type;
	int		r;
	int		g;
	int		b;
	float	ratio;
}	t_alight;

typedef struct s_light
{
	int		type;
	float	x;
	float	y;
	float	z;
	int		r;
	int		g;
	int		b;
	float	ratio;
}	t_light;

typedef struct s_cam
{
	int		type;
	float	x;
	float	y;
	float	z;
	int		x_normal;
	int		y_normal;
	int		z_normal;
	int		fov;
}	t_cam;

typedef struct s_win
{
	void	*mlx;
	void	*mlx_win;
}	t_window;

//Parser ambient
t_ambient	*ft_parseamb(char *str);

//Errors
int		ft_check_error(char **str);
int		ft_error(const char *str, int ret);
int		ft_check_grammar(int fd);
//Utils
char	*ft_lines(char *str, int fd);
int		ft_find(char **str, char *estr, char *tokens);
size_t	ft_strlen(const char *str);
int		ft_strcmp(const char *str1, const char *str2);
int		ft_strncmp(const char *str1, const char *str2, size_t number);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t count);
char	*ft_strchr(const char *str, int ch);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_get_next_line(int fd);
int		ft_getident(char **str, char *estr, char **ftoken, char **eftoken);

#endif
