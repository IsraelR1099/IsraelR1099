/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shaderec.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 09:57:22 by irifarac          #+#    #+#             */
/*   Updated: 2023/03/20 13:08:38 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADEREC_H
# define SHADEREC_H

# include "../world/world.h"
# include "../maths/maths.h"
# include "../parser/parser.h"
# include "rgbcolor.h"
# include "../geometricobj/geometricobj.h"
# include <stdbool.h>
# include <limits.h>

# define k_huge_value INT_MAX

typedef struct s_normal
{
	double	x;
	double	y;
	double	z;
}	t_normal;

typedef struct s_sharerec
{
	bool		hit_object;
	t_point3d	hit_point;
	t_normal	normal_hit;
	t_world		*world;
	t_ray		ray;
	t_rgb		colour;
	double		t;
}	t_shaderec;

t_shaderec	*ft_hit_objects(t_object *obj, t_world *world, t_ray *ray, t_shaderec *shade);
t_point3d	ft_hit_point(t_ray *ray, double t);
#endif
