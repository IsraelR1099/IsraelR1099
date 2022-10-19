/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 20:39:31 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/19 13:58:55 by irifarac         ###   ########.fr       */
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

void	ft_simple_redir(struct cmd *cmd, char **ftoken, char **eftoken, int operator)
{
	char	file[20];
	int		pointers[2];

	printf("operator %d, *ftoken %s, *eftoken %s\n", operator, *ftoken, *eftoken);
	printf("cmd address: %p\n", cmd);
	ft_memset(file, 0, sizeof(file));
	ft_memcpy(file, *ftoken, *eftoken - *ftoken);
	file[*eftoken - *ftoken] = '\0';
	printf("entro en simple file es %s, fotken %s\n", file, *ftoken);
	if (operator == '<')
	{
		pointers[0] = O_RDONLY;
		pointers[1] = 0;
		cmd = buildredir(cmd, *ftoken, *eftoken, pointers[0], pointers[1]);
		//cmd = buildredir(cmd, *ftoken, *eftoken, O_RDONLY, 0);
	}
	else if (operator == '>')
	{
		if (access(file, F_OK) == 0)
		cmd = buildredir(cmd, *ftoken, *eftoken, O_WRONLY | O_APPEND, 1);
		else
			cmd = buildredir(cmd, *ftoken, *eftoken, O_WRONLY | O_CREAT | O_TRUNC, 1);
	}
}
