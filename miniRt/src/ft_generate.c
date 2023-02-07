/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:21:31 by irifarac          #+#    #+#             */
/*   Updated: 2023/02/06 12:57:43 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"
#include "../mlx/mlx.h"


int	ft_intersects(t_ambient *amb, t_object *obj, float x, float y, float z)
{


void	ft_generate(t_ambient *amb, t_object *obj, t_window *mlx)
{
	int	i;
	int	j;
	int	t;
	float	ray_z;
	float	len;
	float	ray_x;
	float	ray_y;
	t_light	*light;

	i = 0;
	t = 100;
	len = 0;
	printf("amb type es %d\n", amb->type);
	light = (t_light *)amb;
	printf("alight->r es %d\n", light->r);
	while (i < 1080)
	{
		j = 0;
		while (j < 1920)
		{
			ray_x = x;
			ray_y = y;
			ray_z = -1 * t;
			len = sqrt(ray_x * ray_xx + ray_y * ray_y + ray_z * ray_z);
			ray_x /= len;
			ray_y /= len;
			ray_z /= len;
			color = ft_intersects(amb, obj, ray_x, ray_y, ray_z);
		//	ft_my_mlx_pxput(mlx, j, i, color);
			ft_my_mlx_pxput(mlx, j, i, ft_color_value(amb, A));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
	(void)obj;
}
