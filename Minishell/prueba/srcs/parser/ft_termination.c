/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termination.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:17:51 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/13 17:44:07 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

struct cmd	*terminate(struct cmd *cmd)
{
	struct doexec	*execcmd;
	struct doredir	*redircmd;
	struct dopipe	*pipecmd;
	int				iter;

	if (!cmd)
		return (0);
	if (cmd->type == EXEC)
	{
		iter = 0;
		execcmd = (struct doexec *)cmd;
		while (execcmd->names[iter])
		{
			*execcmd->end_names[iter] = 0;
			iter++;
		}
	}
	else if (cmd->type == REDIR)
	{
		redircmd = (struct doredir *)cmd;
		terminate(redircmd->cmd);
		*redircmd->efile = 0;
	}
	else if (cmd->type == PIPE)
	{
		pipecmd = (struct dopipe *)cmd;
		terminate(pipecmd->left);
		terminate(pipecmd->right);
	}
	return (cmd);
}

int	ft_setcmd(struct doexec **cmd, char *ftoken, char *eftoken, int sign)
{
	static int	i = 0;

	if (sign == 1)
	{
		(*cmd)->names[i] = 0;
		(*cmd)->end_names[i] = 0;
		i = 0;
		return (i);
	}
	(*cmd)->names[i] = ftoken;
	(*cmd)->end_names[i] = eftoken;
	i++;
	if (i >= MAXARGS)
		ft_error("too many arguments", 1);
	return (i);
}
