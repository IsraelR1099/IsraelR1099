#include "../../include/miniRT.h"
#include "../../mlx/mlx.h"

void	ft_render(t_ambient *amb, t_object *obj, t_window *mlx)
{
	int	x;
	int	y;
	int	colour;
	t_ray	ray;

	y = 0;
	colour = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			colour = ft_samplers(&ray,(float)x, (float)y);
			ft_my_mlx_pxput(mlx, x, y, colour);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
}
