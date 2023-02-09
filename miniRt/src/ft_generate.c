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
	t_colours	colours;

	i = 0;
	t = 100;
	len = 0;
	ft_set_colour(amb, obj, &colours, 6);
	int k = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
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
			if (type == sp)
			{
				ft_my_mlx_pxput(mlx, j, i, colours.c_sphere);
				k++;
			}
			else if (type == pl)
				ft_my_mlx_pxput(mlx, j, i, colours.c_plane);
			else if (type == cy)
				ft_my_mlx_pxput(mlx, j, i, colours.c_cylinder);
			else
				ft_my_mlx_pxput(mlx, j, i, colours.c_ambient);
		//	ft_my_mlx_pxput(mlx, j, i, ft_colour_value(amb, A));
			j++;
		}
		i++;
	}
	printf("k es %d\n", k);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
}
