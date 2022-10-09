/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termination.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:17:51 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/07 21:54:16 by irifarac         ###   ########.fr       */
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
		printf("entro en sign\n");
		(*cmd)->names[i] = 0;
		(*cmd)->end_names[i] = 0;
		i = 0;
		return (i);
	}
	printf("names es %s\n", (*cmd)->names[i]);
	(*cmd)->names[i] = ftoken;
	(*cmd)->end_names[i] = eftoken;
	i++;
	if (i >= MAXARGS)
		ft_error("too many arguments", 1);
	return (i);
}

void	ft_reverse(struct cmd *cmd)
{
	struct cmd		*tmp;
	struct cmd		*array_cmd[_POSIX_OPEN_MAX];
	struct doredir	*tmpredir;
	struct doredir	*new;
	int				i;


	tmp = cmd;
	while (tmp->type != 1)
	{
		tmpredir = (struct doredir *)tmp;
		tmp = tmpredir->cmd;
	}
	printf("tmp address last %p\n", tmp);
	i = 0;
	tmp = cmd;
	while (tmp->type == 2 || tmp->type == 1)
	{
		tmpredir = (struct doredir *)tmp;
		array_cmd[i] = tmp;
		tmp = tmpredir->cmd;
		i++;
	}
	new = (struct doredir *)cmd;
	printf("new address %p\n", new);
	new->cmd = array_cmd[i];
	cmd = array_cmd[1];
	tmpredir = (struct doredir *)cmd;
	tmpredir->cmd = (struct cmd *)new;
	i = 0;
	while (i < 3)
	{
		printf("address before %d: %p\n", i, array_cmd[i]);
		i++;
	}

	i = 0;
	tmp = cmd;
	while (tmp->type == 2 || tmp->type == 1)
	{
		tmpredir = (struct doredir *)tmp;
		array_cmd[i] = tmp;
		tmp = tmpredir->cmd;
		i++;
	}
	i = 0;
	while (i < 3)
	{
		printf("address %d: %p\n", i, array_cmd[i]);
		i++;
	}
}
