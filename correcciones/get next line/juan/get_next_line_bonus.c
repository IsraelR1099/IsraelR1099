/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuzanne <jsuzanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:27:53 by jsuzanne          #+#    #+#             */
/*   Updated: 2022/02/02 14:33:32 by jsuzanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*tmp[8192];
	char		buff[BUFFER_SIZE + 1];
	char		*line;
	int			ret;
	int			nl;

	if (!tmp[fd])
		tmp[fd] = ft_strdup("");
	ret = read(fd, buff, BUFFER_SIZE);
	while (ret >= 0)
	{
		buff[ret] = '\0';
		tmp[fd] = ft_strjoin(tmp[fd], buff);
		nl = check_newline(tmp[fd]);
		if (nl != -1)
			return (up_to_new(&line, &tmp[fd], nl));
		if (!ret && !tmp[fd][0])
			break ;
		if (!ret)
			return (get_reminder(&tmp[fd], 0));
		ret = read(fd, buff, BUFFER_SIZE);
	}
	free(tmp[fd]);
	tmp[fd] = NULL;
	return (NULL);
}

// Divide tmp to \n return to print, and set tmp to the position after de \n
char	*up_to_new(char **line, char **tmp, int nl)
{
	*line = ft_substr(*tmp, 0, nl + 1);
	*tmp = get_reminder(tmp, nl + 1);
	return (*line);
}

// Returns string 
char	*get_reminder(char **str, int nl)
{
	char	*reminder;
	int		rlen;

	rlen = ft_strlen(*str + nl);
	reminder = ft_substr(*str, nl, rlen);
	free(*str);
	*str = NULL;
	return (reminder);
}

int	check_newline(char *buff)
{
	int	i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}
