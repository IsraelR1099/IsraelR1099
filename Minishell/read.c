/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 09:31:46 by irifarac          #+#    #+#             */
/*   Updated: 2022/08/28 14:31:10 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<readline/readline.h>
#include<readline/history.h>
#include <string.h>

struct cmd	*parsecmd(char *s);

void	panic(char *str)
{
	write(2, str, strlen(str) + 1);
	exit (1);
}

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

int	fork1(void)
{
	int	pid;

	printf("entro en fork1\n");
	pid = fork();
	if (pid == -1)
		panic("fork");
	return (pid);
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
			if (chdir(buf + 3) < 0)
				printf("cd: no such file or directory: %s\n", buf + 3);
			continue ;
		}
		if (fork1() == 0)
		{
			parsecmd(buf);
		}
		wait(NULL);
		printf("%s\n", buf);
	}
	return (0);
}

struct cmd	*parsecmd(char *s)
{
	char	*es;
	struct cmd	*cmd;

	es = s + strlen(s);
	cmd = parseline(&s, es);
	peek(&s, es, "");
	if (s != es)
	{
		printf("leftovers: %s\n", s);
		panic("syntax");
	}
	nulterminate(cmd);
	return (cmd);
}
