/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:35:12 by irifarac          #+#    #+#             */
/*   Updated: 2023/05/03 11:54:15 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

static t_ambient	*ft_util_find_amb(t_ambient *tmp, int type)
{
	t_light		*light;
	t_alight	*alight;
	t_cam		*cam;

	if (!tmp)
		return (NULL);
	if (type == A)
	{
		light = (t_light *)tmp;
		tmp = light->amb;
	}
	else if (type == L)
	{
		alight = (t_alight *)tmp;
		tmp = alight->amb;
	}
	else if (type == C)
	{
		cam = (t_cam *)tmp;
		tmp = cam->amb;
	}
	return (tmp);
}

t_ambient	*ft_find_amb(t_ambient *amb, int type)
{
	t_ambient	*tmp;

	tmp = amb;
	while (tmp)
	{
		if (tmp->type == type)
			return (tmp);
		else
		{
			if (tmp->type == A)
				tmp = ft_util_find_amb(tmp, A);
			else if (tmp->type == L)
				tmp = ft_util_find_amb(tmp, L);
			else if (tmp->type == C)
				tmp = ft_util_find_amb(tmp, C);
			else
				break ;
		}
	}
	return (NULL);
}
