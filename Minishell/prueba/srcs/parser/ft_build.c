/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 20:04:56 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/28 12:06:31 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../Libft/libft.h"

struct cmd	*buildexec(void)
{
	struct doexec	*cmd;

	cmd = malloc(sizeof(*cmd));
	if (!cmd)
		return (NULL);
	ft_memset(cmd, 0, sizeof(*cmd));
	cmd->type = EXEC;
	return ((struct cmd *)cmd);
}

struct cmd	*buildredir(struct cmd *scmd, char *file, char *efile,
int pointers[2])
{
	struct doredir	*cmd;

	cmd = malloc(sizeof(*cmd));
	if (!cmd)
		return (NULL);
	ft_memset(cmd, 0, sizeof(*cmd));
	cmd->type = REDIR;
	cmd->cmd = scmd;
	cmd->file = file;
	cmd->efile = efile;
	cmd->right = pointers[0];
	cmd->fd = pointers[1];
	return ((struct cmd *)cmd);
}

struct cmd	*buildpipe(struct cmd *left, struct cmd *right)
{
	struct dopipe	*cmd;

	cmd = malloc(sizeof(*cmd));
	if (!cmd)
		return (NULL);
	ft_memset(cmd, 0, sizeof(*cmd));
	cmd->type = PIPE;
	cmd->left = left;
	cmd->right = right;
	return ((struct cmd *)cmd);
}
