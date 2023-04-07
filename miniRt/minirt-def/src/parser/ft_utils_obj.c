/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:02:00 by irifarac          #+#    #+#             */
/*   Updated: 2023/04/07 11:15:36 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	ft_compare(char *str, char *tokens)
{
	int	i;

	i = 0;
	while (str[i] && *tokens)
	{
		if (str[i] != *tokens)
			return (0);
		i++;
		tokens++;
	}
	return (*tokens == '\0');
}

static int	ft_search(char **str, char *estr, char *tokens)
{
	char	*tmp;

	tmp = *str;
	while (tmp < estr)
	{
		if ((*tmp == *tokens) && ft_compare(tmp, tokens))
			return (1);
		tmp++;
	}
	return (0);
}

int	ft_find_obj(char **str, char *estr, char *tokens)
{
	char	*tmp;

	tmp = *str;
	while (tmp < estr && ft_strchr("\t\r\n\v ", *tmp))
		tmp++;
	*str = tmp;
	return (ft_search(str, estr, tokens));
}

float	ft_diameter(char **ftoken, char *eftoken)
{
	char	*tmp;
	float	ret;

	tmp = *ftoken;
	if (ft_compare(tmp, "sp") || ft_compare(tmp, "pl")
		|| ft_compare(tmp, "cy"))
		tmp += 2;
	while (tmp < eftoken && ft_strchr("\t\r\n\v ", *tmp))
		tmp++;
	ret = ft_fatoi(&tmp);
	*ftoken = tmp;
	return (ret);
}
