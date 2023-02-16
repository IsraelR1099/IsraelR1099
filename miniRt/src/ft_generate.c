/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:21:31 by irifarac          #+#    #+#             */
/*   Updated: 2023/02/13 12:04:24 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"
#include "../mlx/mlx.h"

void	ft_generate(t_ambient *amb, t_object *obj, t_window *mlx)
{
	int			i;
	int			j;
//	int			t;
//	float		len;
	t_vector	ray_dir;
	int			type;
	t_colours	colours;
	t_frustrum	frustrum;

	i = 0;
//	t = 400;
//	len = 0;
	ft_set_colour(amb, obj, &colours, 6);
	int k = 0;
	ft_set_frustrum(WIDTH / HEIGHT, 80, &frustrum);
	printf("frustrum near %f, left %f, right %f, top %f, bottom %f\n",
	frustrum.near, frustrum.left, frustrum.right, frustrum.top, frustrum.bottom);
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			ft_ortographic_view(frustrum, &ray_dir, j, i, -1);
			//calculate ray direction
		//	ray_dir.x = j - (WIDTH / 2);
		//	ray_dir.y = i - (HEIGHT / 2);
		//	ray_dir.z = (-1 * t);
		//	ray_dir.z = -WIDTH / 2 * tan(80/2);
			//normalize direction vector
	/*		len = sqrt(ray_dir.x * ray_dir.x + ray_dir.y * ray_dir.y + ray_dir.z * ray_dir.z);
			ray_dir.x /= len;
			ray_dir.y /= len;
			ray_dir.z /= len;*/
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
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
}
