/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perspective.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 09:58:14 by irifarac          #+#    #+#             */
/*   Updated: 2023/02/20 13:19:43 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

void	ft_set_perspectivex(t_frustrum frustrum, t_vector *ray_dir, int x)
{
	ray_dir->x = frustrum.near * x;
}

void	ft_set_perspectivey(t_frustrum frustrum, t_vector *ray_dir, int y)
{
	ray_dir->y = frustrum.near * y;
}

void	ft_set_perspectivez(t_frustrum frustrum, t_vector *ray_dir, int z)
{
	ray_dir->z = (frustrum.near + frustrum.near) * z - (frustrum.far * frustrum.near);
}

void	ft_perspective(t_frustrum frustrum, t_vector *ray_dir, double x, double y, double z)
{
	ft_set_perspectivex(frustrum, ray_dir, x);
	ft_set_perspectivey(frustrum, ray_dir, y);
	ft_set_perspectivez(frustrum, ray_dir, z);
}
