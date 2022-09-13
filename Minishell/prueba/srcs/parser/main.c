/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:17:47 by irifarac          #+#    #+#             */
/*   Updated: 2022/09/13 13:25:38 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../Libft/libft.h"

static int	getcmd(char **buf, int size)
{
	ft_memset(*buf, 0, size);
	*buf = readline("$ ");
	add_history(*buf);
	if (ft_strncmp(*buf, "exit", ft_strlen(*buf)) == 0)
		return (-1);
	return (0);
}

int	main(void)
{
	static char	*buf;

	buf = (char *)malloc(sizeof(char) * 100);
	if (!buf)
		exit (-1);
	while (getcmd(&buf, sizeof(buf)) >= 0)
	{
		if (buf[0] == 'c' && buf[1] == 'd' && buf[2] == ' ')
		{
			buf[ft_strlen(buf)] = 0;
			if (chdir(buf + 3) < 0)
				printf("cd: no such file or directory: %s\n", buf + 3);
			continue ;
		}
		if (fork1() == 0)
		{
			ft_runcmd(parsecmd(buf));
		}
		printf("returned value %d\n", WEXITSTATUS(0));
		wait(0);
	}
	return (0);
}
