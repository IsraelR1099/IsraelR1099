/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:21:31 by irifarac          #+#    #+#             */
/*   Updated: 2023/02/08 13:54:46 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"
#include "../mlx/mlx.h"

void	ft_generate(t_ambient *amb, t_object *obj, t_window *mlx)
{
	int			i;
	int			j;
	int			t;
	float		len;
	t_vector	ray_dir;
	int			type;

	i = 0;
	t = 100;
	len = 0;
	while (i < 1080)
	{
		j = 0;
		while (j < 1920)
		{
			//calculate ray direction
			ray_dir.x = j;
			ray_dir.y = i;
			ray_dir.z = -1 * t;
			//normalize direction vector
			len = sqrt(ray_dir.x * ray_dir.x + ray_dir.y * ray_dir.y + ray_dir.z * ray_dir.z);
			ray_dir.x /= len;
			ray_dir.y /= len;
			ray_dir.z /= len;
			type = ft_intersects(amb, obj, ray_dir);
			printf("type es %d\n", type);
		/*	if (type == sp)
				color = sphere color;
			else if (type == pl)
				color = plane color;
			else if (type == cy)
				color = cylinder color;
			else
				color = ambient color;*/
		//	ft_my_mlx_pxput(mlx, j, i, color);
			ft_my_mlx_pxput(mlx, j, i, ft_color_value(amb, A));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
}
