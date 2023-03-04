#include "../../include/miniRT.h"
#include "../../mlx/mlx.h"

void	ft_my_mlx_pxput(t_window *mlx, int x, int y, int colour)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->ll + x *(mlx->b / 8));
	*(unsigned int *)dst = colour;
}
