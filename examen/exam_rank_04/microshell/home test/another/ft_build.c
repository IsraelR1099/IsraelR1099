/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:25:10 by irifarac          #+#    #+#             */
/*   Updated: 2023/07/31 13:29:38 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

t_cmd	*ft_buildexec(void)
{
	t_execcmd	*cmd;

	cmd = malloc(sizeof(*cmd));
	if (!cmd)
		return (0);
	ft_memset(cmd, 0, sizeof(*cmd));
	cmd->type = EXEC;
	return ((t_cmd *)cmd);
}

t_cmd	*ft_buildpipe(t_cmd *left, t_cmd *right)
{
	t_pipecmd	*cmd;

	cmd = malloc(sizeof(*cmd));
	if (!cmd)
		return (0);
	ft_memset(cmd, 0, sizeof(*cmd));
	cmd->type = PIPE;
	cmd->left = left;
	cmd->right = right;
	return ((t_cmd *)cmd);
}

t_cmd	*ft_buildlist(t_cmd *left, t_cmd *right)
{
	t_listcmd	*cmd;

	cmd = malloc(sizeof(*cmd));
	if (!cmd)
		return (0);
	ft_memset(cmd, 0, sizeof(*cmd));
	cmd->type = LIST;
	cmd->left = left;
	cmd->right = right;
	return ((t_cmd *)cmd);
}
