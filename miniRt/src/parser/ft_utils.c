/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:53:28 by irifarac          #+#    #+#             */
/*   Updated: 2023/01/27 20:38:09 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

static int	ft_search(char **str, char *estr, char *tokens)
{
	char	*tmp;

	tmp = *str;
	while (tmp < estr)
	{
		if (ft_strchr(tokens, *tmp))
			return (-1);
		tmp++;
	}
	return (0);
}

int	ft_find(char **str, char *estr, char *tokens)
{
	char	*tmp;

	tmp = *str;
	while (tmp < estr && ft_strchr("\t\r\n\v ", *tmp))
		tmp++;
	*str = tmp;
	return (ft_search(str, estr, tokens));
}

size_t	ft_strlen(const char *str)
{
	int	position;

	if (!str)
		return (0);
	position = 0;
	while (str[position] != '\0')
		position++;
	return (position);
}

int	ft_strncmp(const char *str1, const char *str2, size_t number)
{
	size_t	position;

	position = 0;
	if (!number)
		return (0);
	while (str1[position] && (str1[position] == str2[position])
		&& position < (number - 1))
		position++;
	return ((unsigned char)str1[position] - (unsigned char)str2[position]);
}

int	ft_strcmp(const char *str1, const char *str2)
{
	size_t	position;

	position = 0;
	while (str1[position] && (str1[position] == str2[position]))
		position++;
	return ((unsigned char)str1[position] - (unsigned char)str2[position]);
}
