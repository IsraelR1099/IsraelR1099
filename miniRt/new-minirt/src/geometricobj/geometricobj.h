#ifndef GEOMETRICOBJ_H
# define GEOMETRICOBJ_H

# include <math.h>
# include "../parser/parser.h"
# include "../maths/maths.h"
# include "../cameras/cameras.h"

double	ft_check_sphere(t_cameras *camera, t_sphere *sphere, t_ray ray);
double	ft_check_plane(t_cameras *camera, t_plane *plnae, t_ray ray);

#endif
