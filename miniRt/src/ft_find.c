/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:17:26 by irifarac          #+#    #+#             */
/*   Updated: 2023/02/10 13:35:34 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

static t_object	*ft_util_find(t_object *tmp, int type)
{
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cyl;

	if (type == 3)
	{
		sphere = (t_sphere *)tmp;
		tmp = sphere->obj;
	}
	else if (type == 4)
	{
		plane = (t_plane *)tmp;
		tmp = plane->obj;
	}
	else if (type == 5)
	{
		cyl = (t_cylinder *)tmp;
		tmp = cyl->obj;
	}
	return (tmp);
}

t_object	**ft_find_lst_obj(t_object *obj, int type)
{
	t_object	*tmp;
	t_object	**ret;
	int			i;

	tmp = obj;
	i = 0;
	ret = NULL;
	while (tmp)
	{
		if (tmp->type == type)
			ret[i] = tmp;
		else
		{
			if (tmp->type == 3)
				tmp = ft_util_find(tmp, 3);
			else if (tmp->type == 4)
				tmp = ft_util_find(tmp, 4);
			else if (tmp->type == 5)
				tmp = ft_util_find(tmp, 5);
			else
				break ;
		}
		i++;
	}
	printf("salgo\n");
	return (ret);
}

t_ambient	*ft_find_lst(t_ambient *amb, int type)
{
	t_light		*light;
	t_alight	*alight;
	t_cam		*cam;
	t_ambient	*tmp;

	tmp = amb;
	while (tmp)
	{
		if (tmp->type == type)
			return (tmp);
		else
		{
			if (tmp->type == 0)
			{
				alight = (t_alight *)tmp;
				tmp = alight->amb;
			}
			else if (tmp->type == 1)
			{
				cam = (t_cam *)tmp;
				tmp = cam->amb;
			}
			else if (tmp->type == 2)
			{
				light = (t_light *)tmp;
				tmp = light->amb;
			}
			else
				break ;
		}
	}
	return (0);
}
