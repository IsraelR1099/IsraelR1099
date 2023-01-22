/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_ambient.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:13:00 by irifarac          #+#    #+#             */
/*   Updated: 2023/01/22 14:10:59 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

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
		if (token == 'A')
			amb = ft_build_alight(ftoken, eftoken);
		else if (token == 'C')
			amb = ft_build_cam(ftoken, eftoken);
		else if (token == 'L')
			amb = ft_build_light(ftoken, eftoken);
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
	char		*estr;

	estr = str + ft_strlen(str);
	amb = ft_parseline(&str, estr);
	return (amb);
}
