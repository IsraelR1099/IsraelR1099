/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:21:31 by irifarac          #+#    #+#             */
/*   Updated: 2023/01/27 20:40:15 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"
#include "../mlx/mlx.h"


void	ft_generate(t_ambient *amb, t_object *obj, t_window *mlx)
{
	int	i;
	int	j;
	t_light	*light;

	i = 0;
	printf("amb type es %d\n", amb->type);
	light = (t_light *)amb;
	printf("alight->r es %d\n", light->r);
	while (i < 1080)
	{
		j = 0;
		while (j < 1920)
		{
			ft_my_mlx_pxput(mlx, j, i, ft_color_value(light));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
	(void)obj;
}
