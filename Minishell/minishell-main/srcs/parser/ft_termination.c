/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termination.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:17:51 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/21 21:47:53 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ft_redir_ft_terminate(t_cmd *cmd)
{
	t_doredir	*redircmd;

	redircmd = (t_doredir *)cmd;
	ft_terminate(redircmd->cmd);
	*redircmd->efile = 0;
}

t_cmd	*ft_terminate(t_cmd *cmd)
{
	t_doexec	*execcmd;
	t_dopipe	*pipecmd;
	int			iter;

	if (!cmd)
		return (0);
	if (cmd->type == EXEC)
	{
		iter = 0;
		execcmd = (t_doexec *)cmd;
		while (execcmd->names[iter])
		{
			*execcmd->end_names[iter] = 0;
			iter++;
		}
	}
	else if (cmd->type == REDIR)
		ft_redir_ft_terminate(cmd);
	else if (cmd->type == PIPE)
	{
		pipecmd = (t_dopipe *)cmd;
		ft_terminate(pipecmd->left);
		ft_terminate(pipecmd->right);
	}
	return (cmd);
}

int	ft_setcmd(t_doexec **cmd, char *ftoken, char *eftoken, int sign)
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
