/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_runcmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:29:40 by irifarac          #+#    #+#             */
/*   Updated: 2023/07/25 18:40:54 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

void	ft_runcmd(t_cmd *cmd, char **env)
{
	t_execcmd	*execcmd;
	t_pipecmd	*pipecmd;
	t_backcmd	*backcmd;
	int			p[2];

	if (cmd == 0)
		exit(1);
	if (cmd->type == EXEC)
	{
		execcmd = (t_execcmd *)cmd;
		if (execcmd->argv[0] == 0)
			exit(1);
		printf("execcmd->argv[0] = |%s|\n", execcmd->argv[0]);
		printf("execcmd->argv[1] = |%s|\n", execcmd->argv[1]);
		if (execve(execcmd->argv[0], execcmd->argv, env) < 0)
		{
			printf("errno = %d\n", errno);
		}
	}
	else if (cmd->type == PIPE)
	{
		pipecmd = (t_pipecmd *)cmd;
		if (pipe(p) < 0)
			ft_error("pipe failed", 1);
		if (ft_fork1() == 0)
		{
			close(1);
			dup(p[1]);
			close(p[0]);
			close(p[1]);
			ft_runcmd(pipecmd->left, env);
		}
		if (ft_fork1() == 0)
		{
			close(0);
			dup(p[0]);
			close(p[0]);
			close(p[1]);
			ft_runcmd(pipecmd->right, env);
		}
		close(p[0]);
		close(p[1]);
		wait(0);
		wait(0);
	}
	else if (cmd->type == BACK)
	{
		backcmd = (t_backcmd *)cmd;
		if (ft_fork1() == 0)
			ft_runcmd(backcmd->cmd, env);
	}
	exit(0);
}
