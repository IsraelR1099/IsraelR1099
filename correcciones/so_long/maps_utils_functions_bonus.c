/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_utils_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marza-ga <marza-ga-@student.42barcelo      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:59:00 by marza-ga          #+#    #+#             */
/*   Updated: 2022/03/04 22:17:00 by marza-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_map(char *map_name)
{
	int	fd;

	fd = open(map_name, O_RDONLY);
	return (fd);
}

int	map_lines_width(char *map_info)
{
	int	count;	

	count = 0;
	while (map_info[count] && map_info[count] != '\n')
		count++;
	return (count);
}

char	*get_initial_map_info(char *map_name)
{
	char	*map_info;
	char	*line;
	int		fd;
	int		end_read;

	end_read = 0;
	map_info = NULL;
	fd = open_map(map_name);
	if (fd < 0)
		return (NULL);
	while (!end_read)
	{
		line = get_next_line(fd);
		if (!line)
			end_read = 1;
		else
			map_info = ft_strjoin(map_info, line);
	}
	close(fd);
	return (map_info);
}

int	map_lines_height(char *map_info)
{
	int	linecount;
	int	count;	

	linecount = 0;
	count = 0;
	while (map_info[count])
	{
		if (map_info[count] == '\n')
			linecount++;
		count++;
	}
	if (map_info[count] == '\0' && count > 0 && map_info[count] != '\n')
		linecount++;
	return (linecount);
}
