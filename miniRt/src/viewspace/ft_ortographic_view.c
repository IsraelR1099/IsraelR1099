/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ortographic_view.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 09:30:12 by irifarac          #+#    #+#             */
/*   Updated: 2023/02/20 13:19:32 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

static void	ft_set_px(t_frustrum frustrum, t_vector *ray_dir, int x)
{
	double	a;
	double	b;
	double	r_l;

	r_l = (frustrum.right - frustrum.left);
	a = 2 * ray_dir->x / r_l;
	b = frustrum.right + frustrum.left / r_l ;
	(void)x;
	ray_dir->x = a - b;
}

static void	ft_set_py(t_frustrum frustrum, t_vector *ray_dir, int y)
{
	double	a;
	double	b;
	double	t_b;

	t_b = (frustrum.top - frustrum.bottom);
	a = 2 * ray_dir->y / t_b;
	b = frustrum.top + frustrum.bottom / t_b;
	(void)y;
	ray_dir->y = a - b;
}

static void	ft_set_pz(t_frustrum frustrum, t_vector *ray_dir, int z)
{
	double	a;
	double	b;
	double	f_n;

	f_n = (frustrum.far - frustrum.near);
	a = 2 * ray_dir->z / f_n;
	b = frustrum.far + frustrum.near / f_n;
	(void)z;
	ray_dir->z = a - b;
}

void	ft_ortographic_view(t_frustrum frustrum, t_vector *ray_dir, int x, int y, int z)
{
	ft_set_px(frustrum, ray_dir, x);
	ft_set_py(frustrum, ray_dir, y);
	ft_set_pz(frustrum, ray_dir, z);
}
