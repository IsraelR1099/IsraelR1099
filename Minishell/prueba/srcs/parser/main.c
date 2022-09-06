/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:17:47 by irifarac          #+#    #+#             */
/*   Updated: 2022/09/06 20:34:04 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../Libft/libft.h"

static int	getcmd(char **buf, int size)
{
	ft_memset(*buf, 0, size); //Change to ft_memset
	*buf = readline("$ ");
	add_history(*buf);
	if (ft_strcmp(*buf, "exit") == 0) //Change to ft_strcmp
		return (-1);
	return (0);
}

int	main(void)
{
	char	*buf;

	buf = (char *)malloc(sizeof(char) * 100);
	if (!buf)
		exit (-1);
	while(getcmd(&buf, sizeof(buf)) >= 0)
	{
		if (buf[0] == 'c' && buf[1] == 'd' && buf[2] == ' ')
		{
			printf("entro en cd\n");
			buf[ft_strlen(buf)] = 0;
			printf("strlen %lu y directorio %s\n", ft_strlen(buf), buf + 3);
			if (chdir(buf + 3) < 0)
				printf("cd: no such file or directory: %s\n", buf + 3);
			continue ;
		}
		if (fork1() == 0)
		{
			printf("hola\n");
			parsecmd(buf);
		}
		wait(NULL);
		printf("%s\n", buf);
	}
	return (0);
}
