/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_grammar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:43:00 by irifarac          #+#    #+#             */
/*   Updated: 2023/01/15 14:57:01 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

static int	ft_check_ident(char *str)
{
	while (str && ft_strchr("\t ", *str))
		str++;
	if (ft_strchr("ACL\n", *str))
		return (0);
	else if (!ft_strncmp("pl", str, 2))
		return (0);
	else if (!ft_strncmp("sp", str, 2))
		return (0);
	else if (!ft_strncmp("cy", str, 2))
		return (0);
	else
		return (ft_error("No valid identifier", -1));
	return (0);
}

static int	ft_check_param(char *str)
{
	printf("check line %s\n", str);
	printf("first char es %d\n", (int)*str);
	while (str && ft_strchr("\t ", *str))
		str++;
	if (*str == 'A')
		return (0);
	else if (*str == 'C')
		return (0);
	else if (*str == 'L')
		return (0);
	else if (*str == 'p' && *(str + 1) == 'l')
		return (0);
	else if (*str == 's' && *(str + 1) == 'p')
		return (0);
	else if (*str == 'c' && *(str + 1) == 'y')
		return (0);
	else if (*str == 10)
		return (0);
	return (-1);
}

static int	ft_check_line(char *str)
{
	if (ft_check_ident(str) < 0)
		return (-1);
	if (ft_check_param(str) < 0)
		return (-1);
	return (0);
}

int	ft_check_grammar(int fd)
{
	char	*line;

	line = ft_get_next_line(fd);
	if (line == NULL)
		return (ft_error("Empty file", -1));
	while (line != NULL)
	{
		if (ft_check_line(line) < 0)
			return (-1);
		line = ft_get_next_line(fd);
	}
	return (0);
}
