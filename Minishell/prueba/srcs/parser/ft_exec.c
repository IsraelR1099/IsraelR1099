/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:24:22 by irifarac          #+#    #+#             */
/*   Updated: 2022/09/19 14:05:34 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../Libft/libft.h"

static void	ft_runpipecmd(struct cmd *cmd)
{
	struct dopipe	*pipecmd;
	int				file_d[2];

	pipecmd = (struct dopipe *)cmd;
	if (pipe(file_d) < 0)
		ft_error("pipe error", 1);
	if (fork1() == 0)
	{
		close(1); // first child closes stdout fd
		dup(file_d[1]); // changes the stdout by the file_d[1].
		close(file_d[0]);
		close(file_d[1]);
		ft_runcmd(pipecmd->left);
	}
	if (fork1() == 0)
	{
		close(0); // second child closes stdin fd
		dup(file_d[0]);
		close(file_d[0]);
		close(file_d[1]);
		ft_runcmd(pipecmd->right);
	}
	close(file_d[0]); //close fd of parent process
	close(file_d[1]);
	wait(0); // the parent process waits for the two children process
	wait(0);
}

static char	*ft_strchrnul(const char *s, int c)
{
	while (*s)
	{
		if (c == *s)
			break ;
		s++;
	}
	return ((char *)s);
}

static int	ft_execve(char *file, char *argv[], char *envp[])
{
	char	*path;
	char	tstr[126];
	char	*pstr;
	char	*cpath;

	path = getenv("PATH");
	cpath = path;

	while (cpath)
	{
		pstr = ft_strchrnul(cpath, ':');
		ft_memcpy(tstr, cpath, pstr - cpath);
		tstr[pstr - cpath] = '/';
		ft_memcpy(tstr + (pstr - cpath) + (pstr>cpath), file, ft_strlen(file + 1));
		execve(tstr, argv, envp);
		cpath = pstr + 1;
	}
	return (0);
}

static int	ft_execvp(char *file, char *argv[], char *envp[])
{
	return (ft_execve(file, argv, envp));
}

void	ft_runcmd(struct cmd *cmd)
{
	struct doexec	*execcmd;
	struct doredir	*redircmd;

	if (cmd == 0)
		exit (1);
	if (cmd->type == EXEC)
	{
		execcmd = (struct doexec *)cmd;
		if (execcmd->names[0] == 0)
			exit (1);
		ft_execvp(execcmd->names[0], execcmd->names, NULL);
		printf("exec %s failed\n", execcmd->names[0]);
	}
	else if (cmd->type == REDIR)
	{
		redircmd = (struct doredir *)cmd;
		close(redircmd->fd);
		if (open(redircmd->file, redircmd->right) < 0)
			printf("redir %s failed\n", redircmd->file);
		ft_runcmd(redircmd->cmd);
		exit (1);
	}
	else if (cmd->type == PIPE)
		ft_runpipecmd(cmd);
	exit (0);
}
