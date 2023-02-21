#include "../../include/miniRT.h"

void	ft_pixel_to_world(t_vector *ray_dir, int x, int y)
{
	double	ndc_x;
	double	ndc_y;
	double	aspect_ratio;

	aspect_ratio = WIDTH / HEIGHT;
	ndc_x = (x + 0.5) / WIDTH;
	ndc_y = (y + 0.5) / HEIGHT;
	ray_dir->x = (2 * ndc_x - 1) * aspect_ratio * tan(80 /(2 * PI / 180));
	ray_dir->y = 1 - 2 * ndc_y * tan(80/(2 * PI / 180));
}
