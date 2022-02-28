/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmela- <aalmela-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:36:40 by aalmela-          #+#    #+#             */
/*   Updated: 2022/02/15 12:27:42 by aalmela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*get_return_line(char *buff_file)
{
	char	*ret;
	char	*tmp;

	tmp = ft_strchr(buff_file, NL);
	if (tmp)
	{
		ret = ft_substr(buff_file, 0, tmp - buff_file + 1);
		if (!ret)
		{
			free (buff_file);
			return (NULL);
		}
	}
	else if (ft_strlen(buff_file) == 0)
		return (NULL);
	else
		return (buff_file);
	return (ret);
}

static char	*clear_buffer(char *buff_file)
{
	char	*ret;
	int		sizebuffer;
	int		sizeline;

	sizebuffer = ft_strlen(buff_file);
	if (ft_strchr(buff_file, NL))
	{
		sizeline = ft_strchr(buff_file, NL) - buff_file + 1;
		ret = ft_substr(buff_file, sizeline, sizebuffer - sizeline);
		free (buff_file);
		if (!ret)
			return (NULL);
		return (ret);
	}
	else
	{
		if (ft_strlen(buff_file) == 0)
			free (buff_file);
		return (NULL);
	}
}

static char	*read_next_line(char *b_file, int fd)
{
	char	*line;
	char	*tmp;
	int		numchars;

	line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (NULL);
	numchars = 1;
	while (numchars > 0 && !ft_strchr(b_file, NL))
	{
		numchars = read(fd, line, BUFFER_SIZE);
		if (numchars == -1)
		{
			free (b_file);
			free (line);
			return (NULL);
		}
		line[numchars] = '\0';
		tmp = ft_strjoin(b_file, line);
		free (b_file);
		b_file = tmp;
	}
	free (line);
	return (b_file);
}

char	*get_next_line(int fd)
{
	static char	*buff_file[OPEN_MAX];
	char		*ret_line;

	if (fd < 0 || BUFFER_SIZE < 0 || fd > OPEN_MAX)
		return (NULL);
	if (!buff_file[fd])
	{
		buff_file[fd] = (char *)malloc(sizeof(char));
		if (!buff_file[fd])
			return (NULL);
		buff_file[fd][0] = 0;
	}
	buff_file[fd] = read_next_line(buff_file[fd], fd);
	if (!buff_file[fd])
		return (NULL);
	ret_line = get_return_line(buff_file[fd]);
	buff_file[fd] = clear_buffer(buff_file[fd]);
	return (ret_line);
}
