/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsuzanne <jsuzanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:27:53 by jsuzanne          #+#    #+#             */
/*   Updated: 2022/01/21 12:46:45 by jsuzanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		buff[BUFFER_SIZE + 1];
	char		*line;
	int			ret;
	int			nl;

	if (!tmp)
		tmp = ft_strdup("");
	ret = read(fd, buff, BUFFER_SIZE);
	while (ret >= 0)
	{
		buff[ret] = '\0';
		tmp = ft_strjoin(tmp, buff);
		nl = check_newline(tmp);
		if (nl != -1)
			return (up_to_new(&line, &tmp, nl));
		if (!ret && !tmp[0])
			break ;
		if (!ret)
			return (get_reminder(&tmp, 0));
		ret = read(fd, buff, BUFFER_SIZE);
	}
	free(tmp);
	tmp = NULL;
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
