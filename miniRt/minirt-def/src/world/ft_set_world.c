/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_world.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:26:19 by irifarac          #+#    #+#             */
/*   Updated: 2023/04/03 11:41:01 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

static t_vp	ft_set_vp(void)
{
	t_vp	vp;

	vp.num_samples = 16;
	vp.color.r = 0;
	vp.color.g = 0;
	vp.color.b = 0;
	return (vp);
}

static t_ambient	*ft_util_find_amb(t_ambient *tmp, int type)
{
	t_light		*light;
	t_alight	*alight;
	t_cam		*cam;

	if (!tmp)
		return (NULL);
	if (type == A)
	{
		alight = (t_alight *)tmp;
		tmp = alight->amb;
	}
	else if (type == L)
	{
		light = (t_light *)tmp;
		tmp = light->amb;
	}
	else if (type == C)
	{
		cam = (t_cam *)tmp;
		tmp = cam->amb;
	}
	return (tmp);
}

static int	ft_count_light(t_ambient *amb)
{
	t_ambient	*tmp;
	int			ret;

	tmp = amb;
	ret = 0;
	while (tmp)
	{
		if (tmp->type == L)
		{
			ret++;
			tmp = ft_util_find_amb(tmp, L);
		}
		else
		{
			if (tmp->type == A)
				tmp = ft_util_find_amb(tmp, A);
			else if (tmp->type == C)
				tmp = ft_util_find_amb(tmp, C);
			else
				break ;
		}
	}
	return (ret);
}

static t_light	**ft_set_lights(t_ambient *amb)
{
	t_light		**lights;
	t_ambient	*tmp;
	int			i;

	lights = malloc(sizeof(t_light) * ft_count_light(amb));
	if (!lights)
		return (0);
	tmp = amb;
	i = 0;
	while (tmp)
	{
		if (tmp->type == A)
			tmp = ft_util_find_amb(tmp, A);
		else if (tmp->type == L)
		{
			lights[i] = (t_light *)ft_find_amb(tmp, L);
			tmp = ft_util_find_amb(tmp, L);
		}
		else if (tmp->type == C)
			tmp = ft_util_find_amb(tmp, C);
		else
			break ;
		i++;
	}
	return (lights);
}

void	ft_set_world(t_ambient *amb, t_object *obj, t_world *world)
{
	world->camera = ft_build_camera(amb);
	world->amb = amb;
	world->obj = obj;
	world->vp = ft_set_vp();
	world->lights = ft_set_lights(amb);
}
