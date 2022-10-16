/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 20:04:56 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/16 20:26:37 by irifarac         ###   ########.fr       */
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

struct cmd	*buildredir(struct cmd *scmd, char *file,
char *efile, int right, int fd)
{
	struct doredir	*cmd;

//	printf("buildredir address scmd %p y size es %ld\n", scmd, sizeof(*cmd));
//	printf("sizeof of scmd %ld\n", sizeof(*scmd));
	cmd = malloc(sizeof(*cmd));
	if (!cmd)
		return (NULL);
	ft_memset(cmd, 0, sizeof(*cmd));
	cmd->type = REDIR;
	cmd->cmd = scmd;
	cmd->file = file;
	cmd->efile = efile;
	cmd->right = right;
	cmd->fd = fd;
//	printf("cmd doreadir address %p\n", cmd);
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
