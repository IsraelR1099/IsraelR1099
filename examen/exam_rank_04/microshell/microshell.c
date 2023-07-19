/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:06:10 by irifarac          #+#    #+#             */
/*   Updated: 2023/07/19 12:52:41 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

static int	ft_len(char **str, int counter)
{
	int	len;
	int	i;
	int	j;

	if (counter == 1)
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

static char	*ft_changestr(char **str, int counter)
{
	int		i;
	int		j;
	int		k;
	char	*buf;
	int		len;

	len = ft_len(str, counter);
	printf("len es %d\n", len);
	if (!len)
		return (NULL);
	buf = malloc(sizeof(char) * len + 1);
	if (!buf)
		return (NULL);
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
			k++;
			if (i == counter)
				break ;
			j = 0;
			buf[k] = ' ';
		}
	}
	return (buf);
}

int	main(int counter, char **str)
{
	static char	*buf;
	int			status;

	buf = ft_changestr(str, counter);
	if (!buf)
		return (-1);
	printf("str es |%s|\n", buf);
	if (buf[0] == 'c' && buf[1] == 'd' && buf[2] == ' ')
	{
		buf[ft_strlen(buf)] = 0;
		if (chdir(buf + 3) < 0)
			ft_error("error:cd: cannot change directory", -1);
	}
	if (ft_fork1() == 0)
		ft_runcmd(ft_parsecmd(buf));
	waitpid(0, &status, 0);
	free(buf);
	return (0);
}
