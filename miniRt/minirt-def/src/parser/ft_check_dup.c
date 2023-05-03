/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:40:02 by irifarac          #+#    #+#             */
/*   Updated: 2023/05/03 09:48:40 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	ft_len(int fd)
{
	char	tmp[BUFFER_SIZE + 1];
	int		len;
	int		nbr_bytes;

	len = 0;
	nbr_bytes = read(fd, tmp, BUFFER_SIZE);
	while (nbr_bytes > 0)
	{
		tmp[nbr_bytes] = '\0';
		if (ft_strchr(tmp, '\n'))
			len++;
		nbr_bytes = read(fd, tmp, BUFFER_SIZE);
	}
	close(fd);
	return (len);
}

static void	ft_free(char **str)
{
	char	*tmp;
	int		i;

	i = 0;
	while (str[i])
	{
		tmp = str[i];
		free(tmp);
		i++;
	}
	free(str);
}

static int	ft_counter(char **lines, char type)
{
	char	**tmp;
	int		i;
	int		j;
	int		counter;

	i = 0;
	counter = 0;
	tmp = lines;
	while (tmp[i] != NULL)
	{
		j = 0;
		while (tmp[i][j])
		{
			if (tmp[i][j] == type)
				counter++;
			j++;
		}
		i++;
	}
	return (counter);
}

static int	ft_check(char **lines)
{
	int	count_alight;
	int	count_camera;

	count_alight = ft_counter(lines, 'A');
	count_camera = ft_counter(lines, 'C');
	printf("alight %d camera %d\n", count_alight, count_camera);
	if (count_alight == 0 || count_alight > 1)
		return (-1);
	if (count_camera == 0 || count_camera > 1)
		return (-1);
	return (0);
}

int	ft_check_id(char *str)
{
	char	**lines;
	int		i;
	int		len;
	int		fd;

	fd = open(str, O_RDONLY);
	len = ft_len(fd);
	fd = open(str, O_RDONLY);
	i = 0;
	lines = malloc(sizeof(char *) * (len + 1));
	if (!lines)
		return (-1);
	while (len--)
	{
		lines[i] = ft_get_next_line(fd);
		i++;
	}
	lines[i] = NULL;
	if (ft_check(lines) < 0)
	{
		ft_free(lines);
		return (-1);
	}
	ft_free(lines);
	return (0);
}
