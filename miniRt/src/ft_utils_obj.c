/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:02:00 by irifarac          #+#    #+#             */
/*   Updated: 2023/01/24 17:09:50 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

static int	ft_compare(char *str, char *tokens)
{
	while (*str && *tokens)
	{
		if (*str != *tokens)
			return (0);
		str++;
		tokens++;
	}
	return (*tokens == '\0')
}

static int	ft_search(char **str, char *estr, char *tokens)
{
	char	*tmp;
	int		len2;

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

int	ft_getobj(char **str, char *estr, char **ftoken, char **eftoken)
{
	char	*tmp;
	int		ret;

	tmp = *str;
	while (tmp < estr && ft_strchr("\t\r\n\v ", *tmp))
			tmp++;
	if (ftoken)
		*ftoken = tmp;
	ret = *tmp;
	if (*tmp == 0)
		return (0);
	else if (*tmp == 's' && (*tmp + 1) == 'p')
		tmp += 2;
	else if (*tmp == 'p' && (*tmp + 1) == 'l')
		tmp +=2;
	else if (*tmp == 'c' && (*tmp + 1) == 'y')
		tmp +=2;
	else
	{
		ret = 0;
		while ((tmp < estr && !ft_compare(tmp, "sp"))
			&& !ft_compare(tmp, "pl") && !ft_compare(tmp, "cy"))
			tmp++;
		printf("no object case\n");
	}
	while ((tmp < estr && !ft_compare(tmp, "sp"))
		&& !ft_compare(tmp, "pl") && !ft_compare(tmp, "cy"))
	if (eftoken)
		*eftoken = tmp;
	*str = tmp;
	return (ret);
}
