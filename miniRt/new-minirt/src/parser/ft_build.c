/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:48:21 by irifarac          #+#    #+#             */
/*   Updated: 2023/03/08 10:55:44 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_ambient	*ft_build_alight(t_ambient *amb, char *ftoken, char *eftoken)
{
	t_alight	*alight;

	alight = malloc(sizeof(*alight));
	if (!alight)
		return (NULL);
	ft_memset(alight, 0, sizeof(*alight));
	alight->type = A;
	alight->ratio = ft_ratio(&ftoken, eftoken);
	alight->r = ft_color(&ftoken, eftoken);
	alight->g = ft_color(&ftoken, eftoken);
	alight->b = ft_color(&ftoken, eftoken);
	alight->amb = amb;
	return ((t_ambient *)alight);
}

t_ambient	*ft_build_cam(t_ambient *amb, char *ftoken, char *eftoken)
{
	t_cam	*cam;

	cam = malloc(sizeof(*cam));
	if (!cam)
		return (NULL);
	ft_memset(cam, 0, sizeof(*cam));
	cam->type = C;
	cam->x = ft_coord(&ftoken, eftoken);
	cam->y = ft_coord(&ftoken, eftoken);
	cam->z = ft_coord(&ftoken, eftoken);
	cam->x_normal = ft_normal(&ftoken, eftoken);
	cam->y_normal = ft_normal(&ftoken, eftoken);
	cam->z_normal = ft_normal(&ftoken, eftoken);
	cam->fov = ft_fov(&ftoken, eftoken);
	cam->amb = amb;
	return ((t_ambient *)cam);
}

t_ambient	*ft_build_light(t_ambient *amb, char *ftoken, char *eftoken)
{
	t_light	*light;

	light = malloc(sizeof(*light));
	if (!light)
		return (NULL);
	ft_memset(light, 0, sizeof(*light));
	light->type = L;
	light->x = ft_coord(&ftoken, eftoken);
	light->y = ft_coord(&ftoken, eftoken);
	light->z = ft_coord(&ftoken, eftoken);
	light->ratio = ft_ratio(&ftoken, eftoken);
	light->r = ft_color(&ftoken, eftoken);
	light->g = ft_color(&ftoken, eftoken);
	light->b = ft_color(&ftoken, eftoken);
	light->amb = amb;
	return ((t_ambient *)light);
}
