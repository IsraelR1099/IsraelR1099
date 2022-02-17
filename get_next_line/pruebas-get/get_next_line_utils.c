/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:02:20 by irifarac          #+#    #+#             */
/*   Updated: 2022/02/17 13:44:10 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	position;

	position = 0;
	while (str[position] != '\0')
		position++;
	return (position);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

char	*ft_strchr(const char *str, int ch)
{
	int	position;

	position = 0;
	while (str[position] != '\0')
	{
		if (str[position] == (char)ch)
			return ((char *)str + position);
		position++;
	}
	if (str[position] == (char)ch)
		return ((char *)str + position);
	return (0);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	position;
	int				len_src;

	len_src = ft_strlen(src);
	position = 0;
	if (size != 0)
	{
		while (src[position] != '\0' && position < (size - 1))
		{
			dest[position] = src[position];
			position++;
		}
		dest[position] = '\0';
	}
	return (len_src);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;

	dest = malloc (ft_strlen((char *)s1) + 1);
	if (dest == NULL)
		return (0);
	ft_strlcpy(dest, s1, ft_strlen((char *)s1) + 1);
	return (dest);
}



char	*ft_read_file(int fd)
{
	char	*whole_str;
	int		nbr_bytes;
	char	*line;

	whole_str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!whole_str)
		return (0);
	nbr_bytes = 1;
	while (!(ft_strchr(whole_str, '\n')) && nbr_bytes != 0)
	{
		nbr_bytes = read(fd, whole_str, BUFFER_SIZE);
		printf("nbr bytes es %d\n", nbr_bytes);
		if (nbr_bytes == -1)
		{
			free(whole_str);
			return (0);
		}
		printf("-----whole str en ft read line es %s------\n", whole_str);
		whole_str[nbr_bytes] = '\0';
	}
	printf("?????whole str en ft read line es %s--------\n", whole_str);
	line = ft_line(whole_str, '\n');
	free(whole_str);
	return (line);
}

char	*ft_line(char *s, char c)
{
	static char	*buffer = NULL;
	char		*token;
	char		*dup_token;

	printf("++++line en ft line es %s\n", s);
	if (!buffer)
		buffer = s;
	token = buffer;
	if (!*buffer)
	{
		buffer = 0;
		return (0);
	}
	while (*buffer == c)
		buffer += 1;
	while (*buffer && *buffer != c)
		buffer += 1;
	if (*buffer)
	{
			*buffer = 0;
			buffer += 1;
	}
	while (*token == c)
		token += 1;
	dup_token = ft_strdup(token);
	return (dup_token);
}



