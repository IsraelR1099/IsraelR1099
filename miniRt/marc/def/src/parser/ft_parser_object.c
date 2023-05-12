/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_object.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:36:06 by irifarac          #+#    #+#             */
/*   Updated: 2023/04/26 11:40:37 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_object	*ft_parse(char **str, char *estr)
{
	t_object	*obj;
	int			token;
	char		*ftoken;
	char		*eftoken;

	obj = malloc(sizeof(*obj));
	ft_memset(obj, 0, sizeof(*obj));
	if (!obj)
		return (NULL);
	while (ft_find_obj(str, estr, "sp")
		|| ft_find_obj(str, estr, "pl")
		|| ft_find_obj(str, estr, "cy")
		|| ft_find_obj(str, estr, "di"))
	{
		token = ft_getobj(str, estr, &ftoken, &eftoken);
		if (token == 's')
			obj = ft_build_sphere(obj, ftoken, eftoken);
		else if (token == 'p')
			obj = ft_build_plane(obj, ftoken, eftoken);
		else if (token == 'c')
			obj = ft_build_cylinder(obj, ftoken, eftoken);
		else if (token == 'd')
			obj = ft_build_disk(obj, ftoken, eftoken);
	}
	return (obj);
}

t_object	*ft_parseobj(char *str)
{
	t_object	*obj;
	char		*estr;
	char		*tmp;

	tmp = str;
	estr = str + ft_strlen(str);
	obj = ft_parse(&str, estr);
	free(tmp);
	return (obj);
}
