#ifndef BRDF_H
# define BRDF_H

# include "../color/rgbcolor.h"

typedef struct s_lambertian
{
	float	kd;
	t_rgb	color;
}	t_lambertian;

#endif
