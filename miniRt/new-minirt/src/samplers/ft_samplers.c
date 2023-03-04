#include "../../include/miniRT.h"

void	ft_samplers(t_ray *ray, double x, double y)
{
	int			p;
	int			q;
	int			num_samples;
	int			colour;
	t_point2d	points;

	p = 0;
	q = 0;
	num_samples = (int)sqrt(9);
	while (p < n)
	{
		colour = 255;
		while (q < n)
		{
			points.x = 1 * (x - 0.5 * HEIGHT + (q + 0.5) / n);
			points.y = 1 * (y - 0.5 * WITHOUT + (p + 0.5) / n);
			ray->direction = ft_ray_direction(points);




