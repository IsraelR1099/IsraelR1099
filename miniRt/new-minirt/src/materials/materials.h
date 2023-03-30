#ifndef MATERIALS_H
# define MATERIALS_H

# include "../brdf/brdf.h"
# include "../maths/maths.h"
# include "../world/world.h"
# include "../utilities/shaderec.h"
# include "../lights/lights.h"
# include "../color/rgbcolor.h"

typedef struct s_matte
{
	t_lambertian	*ambient_brdf;
	t_lambertian	*diffuse_brdf;
	t_rgb			(* ft_shade)(t_world *world, t_shaderec *shade);
}	t_matte;

t_rgb	ft_shade(t_world *world, t_shaderec *shade);
#endif
