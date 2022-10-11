/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:24:22 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/10 20:46:11 by irifarac         ###   ########.fr       */
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

/*static void	ft_runredir(struct cmd *cmd)
{
	struct doredir	*redircmd;
	struct doredir	*rcmd;
	int				fd;
//	struct stat		buf;

	redircmd = (struct doredir *)cmd;
	rcmd = (struct doredir *)cmd;
	printf("ftoken es %s y cmd %d\n", rcmd->file, rcmd->cmd->type);
	if (access(redircmd->file, F_OK) == 0)
	{
		printf("entro en redir fd 1\n");
		close(redircmd->fd);
		if ((fd = open(redircmd->file, redircmd->right)) < 0)
			ft_error("open failed", 1);
	}
	else
	{
		var++;
		printf("entro en redir fd 2 y file es %s y type %d y var %d address %p\n", redircmd->file, redircmd->cmd->type, var, redircmd);
		close(redircmd->fd);
		if ((fd = open(redircmd->file, redircmd->right, RWRR)) < 0)
			ft_error("open error", 1);
	}
	printf("fd es %d\n", fd);
	ft_runcmd(redircmd->cmd);
}
*/

static int	getbuf(char **buf, int size, char *delimit)
{
	ft_memset(*buf, 0, size);
//	printf("delimit es |%s|\n", delimit);
	*buf = readline("> ");
//	printf("buf es %s\n", *buf);
	if (ft_strncmp(*buf, delimit, ft_strlen(*buf)) == 0)
		return (-1);
//	printf("devuelvo 0\n");
	return (0);
}

static void	ft_runredir(struct cmd *cmd)
{
	struct doredir	*redircmd;
	struct cmd		*srcmd[_POSIX_OPEN_MAX];
	int				j;
	char			*buf;

	j = 1;
	buf = (char *)malloc(sizeof(char) * 200);
	if (!buf)
		ft_error("malloc error", 1);
	p_struct(cmd, srcmd);
	redircmd = (struct doredir *)srcmd[j];
	while (redircmd->type == 2)
	{
		redircmd = (struct doredir *)srcmd[j];
		printf("redircmd address: %p\n", redircmd);
		if ((access(redircmd->file, F_OK)) == 0)
		{
			if(open(redircmd->file, redircmd->right) < 0)
				ft_error("open failed", 1);
		}
		else
		{
			if ((open(redircmd->file, redircmd->right, RWRR)) < 0)
				ft_error("open error", 1);
		}
		j++;
		redircmd = (struct doredir *)srcmd[j];
	}
	redircmd = (struct doredir *)srcmd[0];
	if (redircmd->right & O_RDWR)
	{
		printf("entro en if file es %s\n", redircmd->file);
		if ((open(".tmp", redircmd->right, 0600)) < 0)
			ft_error("open error", 1);
		//while (ft_strncmp(buf, redircmd->file, ft_strlen(buf)) != 0)
		while (getbuf(&buf, sizeof(buf), redircmd->file) >= 0)
		{
		//	printf("entro en readline");
			if ((write(3, buf, ft_strlen(buf)) < 0))
				ft_error("write error", 1);
			if ((write(3, "\n", 1) < 0))
				ft_error("write error", 1);
		}
		write(1, "salgo\n", 6);
		printf("salgo de if\n");
	}
	if (access(redircmd->file, F_OK) == 0)
	{
		close(redircmd->fd);
		if ((open(redircmd->file, redircmd->right)) < 0)
			ft_error("open failed", 1);
	}
	else
	{
		close(redircmd->fd);
		if ((open(redircmd->file, redircmd->right, RWRR)) < 0)
			ft_error("open error", 1);
	}
	ft_runcmd(srcmd[(j)]);
}


void	ft_runcmd(struct cmd *cmd)
{
	struct doexec	*execcmd;
//	struct doredir	*redircmd;
	struct doexec	*exec;

	printf("cmd address runcmd es %p\n", cmd);
	exec = (struct doexec *)cmd;
	printf("names es %s y address: %p y type %d\n", exec->names[0], exec, exec->type);
	//	printf("names es 2 %s\n", exec->names[1]);
//	printf("names 3 es %s\n", exec->names[2]);
//	printf("names 4 es %s\n", exec->names[3]);
	if (cmd == 0)
		exit (1);
	if (cmd->type == EXEC)
	{
		printf("entro en exec runcmd\n");
		execcmd = (struct doexec *)cmd;
		if (execcmd->names[0] == 0)
			exit (1);
		ft_execvp(execcmd->names[0], execcmd->names, NULL);
		printf("exec %s failed\n", execcmd->names[0]);
	}
	else if (cmd->type == REDIR)
	{
	/*	redircmd = (struct doredir *)cmd;
		if (access(redircmd->file, F_OK) == 0)
		{
			close(redircmd->fd);
			if (open(redircmd->file, redircmd->right) < 0)
			{
				printf("redir %s failed\n", redircmd->file);
				exit (1);
			}
		}
		else
		{
			close(redircmd->fd);
			if (open(redircmd->file, redircmd->right, RWRR) < 0)
				ft_error("open error", 1);
		}
		ft_runcmd(redircmd->cmd);*/
		ft_runredir(cmd);
	}
	else if (cmd->type == PIPE)
		ft_runpipecmd(cmd);
	exit (0);
}
