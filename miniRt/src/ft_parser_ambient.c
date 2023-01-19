/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_ambient.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:13:00 by irifarac          #+#    #+#             */
/*   Updated: 2023/01/19 14:55:52 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

static t_ambient	*ft_parse(char **str, char *estr)
{
	t_ambient		*ret;
	struct doamb	*amb;

	while (ft_find(str, estr, "ACL"))
	{
		
}

static t_ambient	*parseline(char **str, char *estr)
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
