/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_object.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:36:06 by irifarac          #+#    #+#             */
/*   Updated: 2023/01/25 13:08:56 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

static t_object	*ft_parse(char **str, char *estr)
{
	t_object	*obj;
	int			token;
	char		*ftoken;
	char		*eftoken;

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
	printf("obj type es %d\n", obj->type);
	return (obj);
}

t_object	*ft_parseobj(char *str)
{
	t_object	*obj;
	t_plane		*plane;
	t_cylinder	*cyl;
	char		*estr;

	estr = str + ft_strlen(str);
	obj = ft_parse(&str, estr);
	return (obj);
}
