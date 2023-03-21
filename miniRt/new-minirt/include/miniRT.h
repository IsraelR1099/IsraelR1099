/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:56:32 by irifarac          #+#    #+#             */
/*   Updated: 2023/03/10 13:09:01 by irifarac         ###   ########.fr       */
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
# include "../src/window/window.h"
# include "../src/world/world.h"
# include "../src/cameras/cameras.h"

# define WIDTH 1080
# define HEIGHT 720
# define PI 3.14

/*typedef struct	s_point2d
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
}	t_ray;*/

void		ft_init(t_ambient *amb, t_object *obj);
void		ft_render(t_ambient *amb, t_object *obj, t_world *world);
t_ambient	*ft_find_amb(t_ambient *amb, int type);
#endif
