/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:12:14 by irifarac          #+#    #+#             */
/*   Updated: 2023/04/26 12:32:19 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lights.h"

static t_object	*ft_help(t_object *tmp)
{
	t_disk	*disk;

	disk = (t_disk *)tmp;
	return (disk->obj);
}

t_object	*ft_l_advance(t_object *tmp)
{
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cyl;

	if (!tmp)
		return (NULL);
	if (tmp->type == sp)
	{
		sphere = (t_sphere *)tmp;
		tmp = sphere->obj;
	}
	else if (tmp->type == pl)
	{
		plane = (t_plane *)tmp;
		tmp = plane->obj;
	}
	else if (tmp->type == cy)
	{
		cyl = (t_cylinder *)tmp;
		tmp = cyl->obj;
	}
	else if (tmp->type == di)
		tmp = ft_help(tmp);
	return (tmp);
}

double	ft_check_l_normal(t_cylinder *cyl, t_ray *ray)
{
	t_vector3d	n;
	double		ret;

	n.x = cyl->x_normal;
	n.y = cyl->y_normal;
	n.z = cyl->z_normal;
	ret = 0;
	if (n.x == 0 && n.y == 1 && n.z == 0)
		ret = ft_hit_cyly(cyl, ray);
	else if (n.x == 0 && n.y == 0 && n.z == 0)
		ret = ft_hit_cylz(cyl, ray);
	return (ret);
}
