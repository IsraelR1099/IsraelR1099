/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 09:31:46 by irifarac          #+#    #+#             */
/*   Updated: 2022/08/26 13:36:21 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<readline/readline.h>
#include<readline/history.h>
#include <string.h>

int	getcmd(char **buf, int size)
{
	memset(*buf, 0, size);
	*buf = readline("$ ");
	printf("cmd %s size %lu\n", *buf, strlen(*buf));
	add_history(*buf);
	if (strcmp(*buf, "exit") == 0) //EOF
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
			buf[strlen(buf)] = 0;
			printf("strlen %lu y directorio %s\n", strlen(buf), buf + 3);
			/*char	*arg_list[] = {
				"pwd",
				NULL
			};*/
			if (chdir(buf + 3) < 0)
				printf("cd: no such file or directory: %s\n", buf + 3);
			//execvp("pwd", arg_list);
			continue ;
		}
		printf("%s\n", buf);
	}
	return (0);
}
