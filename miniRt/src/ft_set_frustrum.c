#include "../include/miniRT.h"

void	ft_set_frustrum(double aspect_ratio, double fov, t_frustrum *frustrum)
{

	double	fovx;
	double	fovy;

	fovx = fov * PI / 180.0;
	fovy = 2.0 * atan(tan(fovx / 2.0) / aspect_ratio);

	frustrum->near = -1.0;
	frustrum->far = 1.0;

	frustrum->left = -tan(fovx / 2.0) * aspect_ratio;
	frustrum->right = -(frustrum->left);

	frustrum->bottom = -tan(fovy / 2.0);
	frustrum->top = -(frustrum->bottom);
}
