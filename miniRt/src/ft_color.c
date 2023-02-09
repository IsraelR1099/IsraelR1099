/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colour.c		                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 09:36:31 by irifarac          #+#    #+#             */
/*   Updated: 2023/02/08 13:55:18 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

static int	ft_ambient_colour(t_ambient *amb, int type)
{
	t_alight	*alight;
	t_light		*light;

	if (type == A)
	{
		alight = (t_alight *)ft_find_lst(amb, A);
		return (alight->r << 16 | alight->g << 8 | alight->b);
	}
	else if (type == L)
	{
		light = (t_light *)ft_find_lst(amb, L);
		return (light->r << 16 | light->g << 8 | light->b);
	}
	return (0);
}

static int	ft_object_colour(t_object *obj, int type)
{
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cyl;

	if (type == sp)
	{
		sphere = (t_sphere *)ft_find_lst_obj(obj, sp);
		return (sphere->r << 16 | sphere->g << 8 | sphere->b);
	}
	else if (type == pl)
	{
		plane = (t_plane *)ft_find_lst_obj(obj, pl);
		printf("plane r %d, g %d, b %d\n", plane->r, plane->g, plane->b);
		return (plane->r << 16 | plane->g << 8 | plane->b);
	}
	else if (type == cy)
	{
		cyl = (t_cylinder *)ft_find_lst_obj(obj, cy);
		return (cyl->r << 16 | cyl->g << 8 | cyl->b);
	}
	return (0);
}

int	ft_set_colour(t_ambient *amb, t_object *obj, t_colours *colours, int type)
{
	int	colour;

	colour = 0;
	if (type >= 0 && type <= 2)
		colour = ft_ambient_colour(amb, type);
	else if (type >= 3 && type <= 5)
		colour = ft_object_colour(obj, type);
	else if (type == 6)
	{
		colours->c_ambient = ft_ambient_colour(amb, A);
		colours->c_light = ft_ambient_colour(amb, L);
		colours->c_sphere = ft_object_colour(obj, sp);
		colours->c_plane = ft_object_colour(obj, pl);
		colours->c_cylinder = ft_object_colour(obj, cy);
	}
	return (colour);
}
