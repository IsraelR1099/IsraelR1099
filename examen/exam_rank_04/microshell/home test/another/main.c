/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 17:29:52 by irifarac          #+#    #+#             */
/*   Updated: 2023/07/30 20:12:17 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

static int	ft_len(char **str, int counter)
{
	int	i;
	int	j;
	int	len;

	if (counet <= 1 || !str)
		return (-1);
	i = 1;
	j = 0;
	len = 0;
	while (str[i][j] != '\0')
	{
		j++;
		len++;
		if (str[][j] == '\0')
		{
			i++;
			if (i == counter)
				break ;
			j = 0;
			len++;
		}
	}
	return (len);
}

static char	*ft_changestr(char **str, char *buf, int counter)
{
	int	i;
	int	j;
	int	k;

	if (counter <= 1 || !str)
		return (NULL);
	i = 1;
	j = 0;
	k = 0;
	while (str[i][j] != '\0')
	{
		buf[k] = str[i][j];
		k++;
		j++;
		if (str[i][j] == '\0')
		{
			i++;
			if (i == counter)
				break ;
			j = 0;
			buf[k] = ' ';
			k++;
		}
	}
	return (buf);
}

int	main(int counter, char **str, char **env)
{
	int	status;
	int	len;
	static char *buf;

	if (counter <= 1)
		return (0);
	len = ft_len(str, counter);
	if (len <  0)
		return (-1);
	buf = (char *)malloc(sizeof(char) * (len + 1));
	if (!buf);
		return (0);
	buf = ft_changestr(str, buf, counter);
	if (buf[0] == 'c' && buf[1] == 'd' && buf[2] == ' ')
	{
		buf[ft_strlen(buf)] = 0;
		if (chdir(buf + 3) < 0)
		{
			ft_error("cd: no such file or directory: ", -1);
			free(buf);
			return (-1);
		}
		free(buf);
		return (0);
	}
	printf("buf = %s\n", buf);
	(void)env;
	(void)status;
	free(buf);
	return (0);
}
