/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 20:11:59 by irifarac          #+#    #+#             */
/*   Updated: 2023/07/26 17:23:26 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

static int	ft_len(char **str, int counter)
{
	int i;
	int j;
	int len;

	if (counter <= 1 || !str)
		return (0);
	i = 1;
	j = 0;
	len = 0;
	while (str[i][j] != '\0')
	{
		j++;
		len++;
		if (str[i][j] == '\0')
		{
			i++;
			if (i == counter)
				break ;
			len++;
			j = 0;
		}
	}
	return (len);
}

static char	*ft_changestr(char **str, char *buf, int counter)
{
	int	i;
	int	j;
	int	k;

	if (!str || counter <= 1)
		return (0);
	i = 1;
	j = 0;
	k = 0;
	while (str[i][j] != '\0')
	{
		buf[k] = str[i][j];
		j++;
		k++;
		if (str[i][j] == '\0')
		{
			i++;
			if (i == counter)
				break ;
			buf[k] = ' ';
			j = 0;
			k++;
		}
	}
	return (buf);
}

int	main(int counter, char **str, char **env)
{
	static char	*buf;
	int			len;
	int			status;

	if (counter <= 1)
		return (0);
	len = ft_len(str, counter);
	buf = malloc(sizeof(char) * len + 1);
	if (!buf)
		return (0);
	ft_memset(buf, 0, len + 1);
	buf = ft_changestr(str, buf, counter);
	printf("buf: %s\n", buf);
	if (buf[0] == 'c' && buf[1] == 'd' && buf[2] == ' ')
	{
		buf[ft_strlen(buf)] = 0;
		if (chdir(buf + 3) < 0)
			ft_error("cd: no such file or directory: ", buf + 3);
		free(buf);
		exit(0);
	}
	if (ft_fork1() == 0)
		ft_runcmd(ft_parsecmd(buf), env);
	waitpid(0, &status, 0);
	free(buf);
	return (0);
}
