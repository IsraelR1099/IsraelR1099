#include "geometricobj.h"

void	ft_set_limits(t_cylinder *cyl, double limit[2])
{
	limit[0] = cyl->y - (cyl->height / 2);
	limit[1] = cyl->y + (cyl->height / 2);
}
