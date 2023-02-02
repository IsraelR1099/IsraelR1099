/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_object.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:36:06 by irifarac          #+#    #+#             */
/*   Updated: 2023/02/01 12:47:52 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

static t_object	*ft_parse(char **str, char *estr)
{
	t_object	*obj;
	int			token;
	char		*ftoken;
	char		*eftoken;

	obj = malloc(sizeof(*obj));
	if (!obj)
		return (NULL);
	while (ft_find_obj(str, estr, "sp")
		|| ft_find_obj(str, estr, "pl")
		|| ft_find_obj(str, estr, "cy"))
	{
		token = ft_getobj(str, estr, &ftoken, &eftoken);
		if (token == 's')
			obj = ft_build_sphere(obj, ftoken, eftoken);
		else if (token == 'p')
			obj = ft_build_plane(obj, ftoken, eftoken);
		else if (token == 'c')
			obj = ft_build_cylinder(obj, ftoken, eftoken);
	}
	return (obj);
}

t_object	*ft_parseobj(char *str)
{
	t_object	*obj;
	t_plane		*plane;
	t_cylinder	*cyl;
	t_sphere	*sph;
	char		*estr;

	estr = str + ft_strlen(str);
	obj = ft_parse(&str, estr);
	int i = 0;
	while (obj && i++ < 3)
	{
		if (obj->type == 3)
		{
			sph = (t_sphere *)obj;
			printf("diameter sphere is %f\n", sph->diameter);
			printf("color spehre r %d, g %d, b%d\n", sph->r, sph->g, sph->b);
			printf("coord sphere x %f, y %f, z %f\n", sph->x, sph->y, sph->z);
			obj = sph->obj;
		}
		else if (obj->type == 4)
		{
			plane = (t_plane *)obj;
			printf("plane x normal %d\n", plane->x_normal);
			printf("plane color r %d, g %d, b %d\n", plane->r, plane->g, plane->b);
			printf("coord plane x %f, y %f, z %f\n", plane->x, plane->y, plane->z);
			obj = plane->obj;
		}
		else if (obj->type == 5)
		{
			cyl = (t_cylinder *)obj;
			printf("diameter cylinder %f\n", cyl->diameter);
			printf("coord cylinder x %f, y %f, z %f\n", cyl->x, cyl->y, cyl->z);
			obj = cyl->obj;
		}
	}
	return (obj);
}
