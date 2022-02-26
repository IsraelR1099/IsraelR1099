/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:56:53 by irifarac          #+#    #+#             */
/*   Updated: 2022/02/26 14:20:16 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "tc2.h"

static char	*ft_line(char *str, char c)
{
//	static char	*buffer = NULL;
	char		*token;
	//int			position;

	printf("str es al principio de line %p !!!!%s!!!\n", str, str);
	token = str;
	if (!*str)
	{
		str = 0;
		//free(buffer);
		return (0);
	}
	while (*str && *str != c)
		str += 1;
	if (*str)
	{
		*str = 0;
		str += 1;
	}
	printf("str es %p !!!!%s!!!\n", str, str);
	printf("token es |/%s|\n", token);
	return (token);
}

static char	*ft_read_file(char *temp_str, int fd)
{
	static char	*whole_str = NULL;
	char		*token2;
	int			nbr_bytes;
	static int	counter;

	if (!whole_str)
		whole_str = ft_strdup("");
	nbr_bytes = 1;
	printf("whole str al principio es %p ###%s##\n", whole_str, whole_str);
	while (!ft_strchr(temp_str, '\n') && nbr_bytes > 0)
	{
		nbr_bytes = read(fd, temp_str, BUFFER_SIZE);
		if (nbr_bytes == -1)
		{
			free(temp_str);
			free(whole_str);
			return (0);
		}
		temp_str[nbr_bytes] = '\0';
		printf("%s-----read file----%s\n", TC_YEL, TC_NRM);
		printf("whole str antes es ||%s||\n", whole_str);
		whole_str = ft_strjoin(whole_str, temp_str);
		printf("whole str es ||%s||\n", whole_str);
		printf("%s-----read file end----%s\n", TC_YEL, TC_NRM);
	}
	printf("*********\n");
	printf("----whole str es %p ||%s||\n", whole_str, whole_str);
	token2 = ft_strdup(whole_str);
	counter = 0;
	while (*whole_str && *whole_str != '\n')
	{
		counter ++;
		whole_str += 1;
	}
	if (*whole_str)
	{
		counter++;
		whole_str += 1;
	}
	return (token2);
}

char	*get_next_line(int fd)
{
	char		*temp_str;
	char		*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 10)
		return (0);
	temp_str = (char *)malloc(sizeof(*temp_str) * (BUFFER_SIZE + 1));
	if (!temp_str)
	{
		free(temp_str);
		return (0);
	}
	temp_str[0] = 0;
	str = ft_read_file(temp_str, fd);
	if (!str)
		return (0);
	printf("str address is %p\n", str);
	line = ft_line(str, '\n');
	if (!line)
		return (0);
	return (line);
}
