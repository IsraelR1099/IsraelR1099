/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:41:40 by irifarac          #+#    #+#             */
/*   Updated: 2023/04/26 12:40:41 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shaderec.h"

static t_object	*ft_help(t_object *tmp)
{
	t_disk	*disk;

	disk = (t_disk *)tmp;
	return (disk->obj);
}

t_object	*ft_advance(t_object *tmp)
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
