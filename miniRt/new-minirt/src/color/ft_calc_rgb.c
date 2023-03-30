#include "rgbcolor.h"

t_rgb	ft_rgb_scalar_product(t_rgb color, double scalar)
{
	t_rgb	ret;

	ret.r = color.r * scalar;
	ret.g = color.g * scalar;
	ret.b = color.b * scalar;
	return (ret);
}
