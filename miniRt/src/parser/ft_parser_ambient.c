/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_ambient.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:13:00 by irifarac          #+#    #+#             */
/*   Updated: 2023/01/27 20:37:44 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

static t_ambient	*ft_parse(char **str, char *estr)
{
	t_ambient		*amb;
	int				token;
	char			*ftoken;
	char			*eftoken;

	while (ft_find(str, estr, "ACL"))
	{
//		printf("str es %s, caracter %c\n", *str, **str);
		token = ft_getident(str, estr, &ftoken, &eftoken);
//		printf("str despues getident %s\n", *str);
		if (token == 'A')
			amb = ft_build_alight(amb, ftoken, eftoken);
		else if (token == 'C')
			amb = ft_build_cam(amb, ftoken, eftoken);
		else if (token == 'L')
			amb = ft_build_light(amb, ftoken, eftoken);
//		printf("token es %d, ftoken %s y final |%s|\n", token, ftoken, eftoken);
	}
	return (amb);
}

static t_ambient	*ft_parseline(char **str, char *estr)
{
	t_ambient	*amb;

	amb = ft_parse(str, estr);
/*	if (ft_find(str, estr, )
	{
		ft_getparam(str, estr);
		amb = ft_buildamb(amb, ft_parseline(str, estr));
	}*/
	return (amb);
}

t_ambient	*ft_parseamb(char *str)
{
	t_ambient	*amb;
	t_light		*light;
	t_alight	*alight;
	t_cam		*cam;
	char		*estr;

	estr = str + ft_strlen(str);
	amb = ft_parseline(&str, estr);
	int i = 0;
	while (amb && i++ < 4)
	{
		if (amb->type == 0)
		{
			alight = (t_alight *)amb;
			printf("alight r %d\n", alight->r);
			amb = alight->amb;
		}
		else if (amb->type == 1)
		{
			cam = (t_cam *)amb;
			printf("cam fov es %d\n", cam->fov);
			amb = cam->amb;
		}
		else if (amb->type == 2)
		{
			light = (t_light *)amb;
			amb = light->amb;
			printf("cood x light es %f\n", light->x);
			printf("light ratio es %f\n", light->ratio);
		}
		else
			printf("no type\n");
	}
	return (amb);
}
