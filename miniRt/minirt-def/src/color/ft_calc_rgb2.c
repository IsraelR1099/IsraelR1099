#include "rgbcolor.h"

t_rgb	ft_rgb_division(t_rgb up, double scalar)
{
	t_rgb	ret;

	ret.r = up.r / scalar;
	ret.g = up.g / scalar;
	ret.b = up.b / scalar;
	return (ret);
}
