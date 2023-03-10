/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_ambient.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:13:00 by irifarac          #+#    #+#             */
/*   Updated: 2023/03/08 10:57:17 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
//#include "../../include/miniRT.h"

static t_ambient	*ft_parse(char **str, char *estr)
{
	t_ambient		*amb;
	int				token;
	char			*ftoken;
	char			*eftoken;

	amb = malloc(sizeof(*amb));
	amb->type = 10;
	if (!amb)
		return (NULL);
	while (ft_find(str, estr, "ACL"))
	{
		token = ft_getident(str, estr, &ftoken, &eftoken);
		printf("token es %c\n", (char)token);
		if (token == 'A')
			amb = ft_build_alight(amb, ftoken, eftoken);
		else if (token == 'C')
			amb = ft_build_cam(amb, ftoken, eftoken);
		else if (token == 'L')
			amb = ft_build_light(amb, ftoken, eftoken);
	}
	return (amb);
}

static t_ambient	*ft_parseline(char **str, char *estr)
{
	t_ambient	*amb;

	amb = ft_parse(str, estr);
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
