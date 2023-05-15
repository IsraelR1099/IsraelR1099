/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:23:21 by irifarac          #+#    #+#             */
/*   Updated: 2023/05/03 13:33:35 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

static t_object	*ft_free_sph(t_sphere *sphere)
{
	t_object	*ret;

	ret = sphere->obj;
	free(sphere);
	return (ret);
}

static t_object	*ft_free_pl(t_plane *plane)
{
	t_object	*ret;

	ret = plane->obj;
	free(plane);
	return (ret);
}

static t_ambient	*ft_free_alight(t_alight *alight)
{
	t_ambient	*ret;

	ret = alight->amb;
	free(alight);
	return (ret);
}

t_object	*ft_free_advance(t_object *tmp)
{
	t_cylinder	*cyl;
	t_disk		*disk;
	t_object	*tmp2;

	tmp2 = tmp;
	if (tmp->type == sp)
		tmp2 = ft_free_sph((t_sphere *)tmp2);
	else if (tmp->type == pl)
		tmp2 = ft_free_pl((t_plane *)tmp2);
	else if (tmp->type == cy)
	{
		cyl = (t_cylinder *)tmp2;
		tmp2 = cyl->obj;
		free(cyl);
	}
	else if (tmp->type == di)
	{
		disk = (t_disk *)tmp2;
		tmp2 = disk->obj;
		free(disk);
	}
	return (tmp2);
}

t_ambient	*ft_free_advance_amb(t_ambient *tmp)
{
	t_ambient	*ret;
	t_cam		*camera;
	t_light		*light;

	ret = tmp;
	if (tmp->type == A)
		ret = ft_free_alight((t_alight *)ret);
	else if (tmp->type == C)
	{
		camera = (t_cam *)ret;
		ret = camera->amb;
		free(camera);
	}
	else if (tmp->type == L)
	{
		light = (t_light *)ret;
		ret = light->amb;
		free(light);
	}
	return (ret);
}
