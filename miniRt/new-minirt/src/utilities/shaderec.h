#ifndef SHADEREC_H
# define SHADEREC_H

# include "../world/world.h"
# include "../maths/maths.h"
# include "../parser/parser.h"
# include "../geometricobj.h"
# include <stdbool.h>

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
	double		t;
}	t_shaderec;

t_shaderec	ft_hit_objects(t_object *obj, t_world *world, t_ray ray);
#endif
