/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:25:01 by irifarac          #+#    #+#             */
/*   Updated: 2023/01/27 20:36:56 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

static int	ft_format(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (ft_strcmp(str + (len - 3), ".rt"))
		return (-1);
	else if (!ft_strcmp(str + (len - 3), ".rt") && len <= 3)
		return (-1);
	return (0);
}

static int	ft_grammar(char *str)
{
	int		fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (ft_error("File does not exist", -1));
	if (ft_check_grammar(fd) < 0)
		return (-1);
	close(fd);
	return (0);
}

int	ft_error(const char *str, int ret)
{
	printf("%s\n", str);
	return (ret);
}

int	ft_check_error(char **str)
{
	if (ft_format(str[1]) < 0)
		return (ft_error("Wrong format", -1));
	else if (ft_grammar(str[1]) < 0)
		return (-1);
	return (0);
}
