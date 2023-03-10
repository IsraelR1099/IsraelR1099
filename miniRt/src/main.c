/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:21:31 by irifarac          #+#    #+#             */
/*   Updated: 2023/03/10 10:25:11 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"
#include "parser/parser.h"
#include "../mlx/mlx.h"

static char	*ft_delnul(char **ret, int len)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		exit(ft_error("Malloc error", -1));
	i = 0;
	j = 0;
	k = 0;
	while (ret[i])
	{
		while (ret[i][j])
		{
			str[k] = ret[i][j];
			if (str[k] == 10)
				str[k] = 32;
			k++;
			j++;
		}
		j = 0;
		i++;
	}
	str[k] = '\0';
	return (str);
}

static int	ft_len(int fd, int *bytes)
{
	int		nbr_bytes;
	int		len;
	char	tmp[BUFFER_SIZE + 1];

	len = 0;
	nbr_bytes = read(fd, tmp, BUFFER_SIZE);
	while (nbr_bytes > 0)
	{
		tmp[nbr_bytes] = '\0';
		*bytes += nbr_bytes;
		if (ft_strchr(tmp, '\n'))
			len++;
		nbr_bytes = read(fd, tmp, BUFFER_SIZE);
	}
	close(fd);
	return (len);
}

char	*ft_lines(char *str,int fd)
{
	char	**ret;
	int		i;
	int		len;
	int		bytes;
	char	*new_str;

	bytes = 0;
	len = ft_len(fd, &bytes);
	fd = open(str, O_RDONLY);
	if (fd < 0)
		exit(ft_error("Open error", -1));
	ret = malloc(sizeof(char *) * (len + 1));
	if (!ret)
		exit(ft_error("Malloc error", -1));
	i = 0;
	while (len--)
	{
		ret[i] = ft_get_next_line(fd);
		i++;
	}
	ret[i] = NULL;
	new_str = ft_delnul(ret, bytes);
	return (new_str);
}


int	main(int counter, char **str)
{
	t_ambient	*amb;
	t_object	*objs;
	int			fd;

	if (counter == 2)
	{
		if (ft_check_error(str) >= 0)
		{
			fd = open(str[1], O_RDONLY);
			if (fd < 0)
				return (ft_error("Open error", -1));
			amb = ft_parseamb(ft_lines(str[1], fd));
			close(fd);
			fd = open(str[1], O_RDONLY);
			if (fd < 0)
				return (ft_error("Open error", -1));
			objs = ft_parseobj(ft_lines(str[1], fd));
			close(fd);
			ft_init(amb, objs);
		}
	}
	else
		printf("Wrong number of arguments\n");
	return (0);
}
