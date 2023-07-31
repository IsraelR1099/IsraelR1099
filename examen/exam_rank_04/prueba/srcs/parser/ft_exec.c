/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:24:22 by irifarac          #+#    #+#             */
/*   Updated: 2023/07/31 13:47:51 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../Libft/libft.h"

static void	ft_close(int file_d[2])
{
	close(file_d[0]);
	close(file_d[1]);
}

static void	ft_runpipecmd(struct cmd *cmd)
{
	struct dopipe	*pipecmd;
	int				file_d[2];
	int				pid1;
	int				pid2;

	pipecmd = (struct dopipe *)cmd;
	if (pipe(file_d) < 0)
		ft_error("pipe error", 1);
	pid1 = fork1();
	if (pid1== 0)
	{
		close(1);
		dup(file_d[1]);
		close(file_d[0]);
		close(file_d[1]);
		ft_runcmd(pipecmd->left);
	}
	pid2 = fork1();
	if (pid2 == 0)
	{
		close(0);
		dup(file_d[0]);
		close(file_d[0]);
		close(file_d[1]);
		ft_runcmd(pipecmd->right);
	}
	ft_close(file_d);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

static void	ft_runredir(struct cmd *cmd)
{
	struct doredir	*redircmd;
	struct cmd		*srcmd[_POSIX_OPEN_MAX];
	int				j;

	j = 1;
	p_struct(cmd, srcmd);
	redircmd = (struct doredir *)srcmd[0];
	if (redircmd->right & O_RDWR)
		ft_heredoc(cmd);
	redircmd = (struct doredir *)srcmd[j];
	while (redircmd->type == 2)
	{
		redircmd = (struct doredir *)srcmd[j];
		if ((access(redircmd->file, F_OK)) == 0)
		{
			if (open(redircmd->file, redircmd->right) < 0)
				ft_error("open failed", 1);
		}
		else
			if ((open(redircmd->file, redircmd->right, RWRR)) < 0)
				ft_error("open error", 1);
		redircmd = (struct doredir *)srcmd[++j];
	}
	ft_redir_exec(srcmd[0]);
	ft_runcmd(srcmd[j]);
}

void	ft_runcmd(struct cmd *cmd)
{
	struct doexec	*execcmd;

	if (cmd == 0)
		exit (1);
	printf("type es %d\n", cmd->type);
	if (cmd->type == EXEC)
	{
		execcmd = (struct doexec *)cmd;
		if (execcmd->names[0] == 0)
			exit (1);
		ft_execvp(execcmd->names[0], execcmd->names, NULL);
		printf("exec %s failed\n", execcmd->names[0]);
	}
	else if (cmd->type == REDIR)
		ft_runredir(cmd);
	else if (cmd->type == PIPE)
		ft_runpipecmd(cmd);
	exit (0);
}