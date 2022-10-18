/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 20:39:31 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/18 20:49:55 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../Libft/libft.h"

void	p_struct(struct cmd *cmd, struct cmd *srcmd[])
{
	struct cmd		*tmp;
	struct doredir	*tmpredir;
	int				i;

	i = 0;
	tmp = cmd;
	while (tmp->type == 2 || tmp->type == 1)
	{
		tmpredir = (struct doredir *)tmp;
		srcmd[i] = tmp;
		tmp = tmpredir->cmd;
		i++;
		if (i >= _POSIX_OPEN_MAX)
			ft_error("maximum number of open files exceed", 1);
	}
}

void	ft_redir_exec(struct cmd *cmd)
{
	struct doredir	*redircmd;

	redircmd = (struct doredir *)cmd;
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
}

void	ft_simple_redir(struct cmd *cmd, char *array[2], char file[20], int operator)
{
	printf("entro en simple file es %s\n", file);
	if (operator == '<')
		cmd = buildredir(cmd, array[0], array[1], O_RDONLY, 0);
	else if (operator == '>')
	{
		if (access(file, F_OK) == 0)
		cmd = buildredir(cmd, array[0], array[1], O_WRONLY |
		O_APPEND, 1);
		else
			cmd = buildredir(cmd, array[0], array[1], O_WRONLY | O_CREAT
			| O_TRUNC, 1);
	}
}
