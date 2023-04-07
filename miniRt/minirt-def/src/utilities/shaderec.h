/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shaderec.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 09:57:22 by irifarac          #+#    #+#             */
/*   Updated: 2023/04/07 14:05:20 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADEREC_H
# define SHADEREC_H

# include "../world/world.h"
# include "../maths/maths.h"
# include "../parser/parser.h"
# include "../color/rgbcolor.h"
# include "../geometricobj/geometricobj.h"
# include <stdbool.h>
# include <limits.h>

# define K_HUGE_VALUE INT_MAX

typedef struct s_normal
{
	double	x;
	double	y;
	double	z;
}	t_normal;

typedef struct s_shaderec
{
	bool		hit_object;
	bool		in_shadow;
	t_point3d	hit_point;
	t_normal	normal_hit;
	t_world		*world;
	t_ray		ray;
	t_rgb		colour;
	double		ka;
	double		kd;
	double		t;
	int			type;
}	t_shaderec;

t_shaderec	*ft_hit_objects(t_object *obj, t_world *world, t_ray *ray,
				t_shaderec *shade);
t_point3d	ft_hit_point(t_ray *ray, double t);
t_vector3d	ft_normalize(t_vector3d vector);
t_normal	ft_vect_normal_sphere(t_sphere *sphere, t_point3d hit_point);
#endif
