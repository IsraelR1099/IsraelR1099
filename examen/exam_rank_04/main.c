/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 18:08:15 by irifarac          #+#    #+#             */
/*   Updated: 2023/06/25 20:44:59 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int ft_getcmd(char **str, int counter)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	while (str[i][j] != '\0')
	{
		j++;
		len++;
		if (str[i][j] == '\0')
		{
			i++;
			if(i == counter)
				break ;
			len++;
			j = 0;
		}
	}
	return (len);
}

int	main(int counter, char **str)
{
	char	*buf;
	int		len;

	len = ft_getcmd(str, counter);
	buf = (char *)malloc(sizeof(char) * len);
	if (!buf)
		return (0);
	buf[len] = '\0';
	if (buf[0] == 'c' && buf[1] == 'd' && buf[2] == ' ')
	{
		buf[ft_strlen(buf)] = 0;
		if (chdir(buf + 3) < 0)
			printf("cd: no such file or directory: %s\n", buf + 3);
	}
	printf("buf = %s\n", buf);
	free(buf);
	return (0);
}
