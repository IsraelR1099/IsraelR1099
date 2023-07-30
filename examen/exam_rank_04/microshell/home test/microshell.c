/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:06:10 by irifarac          #+#    #+#             */
/*   Updated: 2023/07/25 18:57:25 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

static int	ft_len(char **str, int counter)
{
	int	len;
	int	i;
	int	j;

	len = 0;
	if (counter <= 1 || !str )
		return (0);
	i = 1;
	j = 0;
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

static char	*ft_changestr(char **str, int counter)
{
	int		i;
	int		j;
	int		k;
	char	*buf;
	int		len;

	len = ft_len(str, counter);
	if (!len)
		return (NULL);
	buf = malloc(sizeof(char) * len + 1);
	if (!buf)
		return (NULL);
	ft_memset(buf, 0, len + 1);
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
			j = 0;
			buf[k] = ' ';
			k++;
		}
	}
	return (buf);
}

int	main(int counter, char **str, char **env)
{
	static char	*buf;
	int			status;

	buf = ft_changestr(str, counter);
	if (!buf)
		return (-1);
	if (buf[0] == 'c' && buf[1] == 'd' && buf[2] == ' ')
	{
		buf[ft_strlen(buf)] = 0;
		if (chdir(buf + 3) < 0)
			ft_error("error:cd: cannot change directory", -1);
		free(buf);
		exit(0);
	}
	if (ft_fork1() == 0)
		ft_runcmd(ft_parsecmd(buf), env);
	waitpid(0, &status, 0);
	free(buf);
	return (0);
}
