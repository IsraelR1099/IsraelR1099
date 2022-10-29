/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:05:05 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/29 18:24:33 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../Libft/libft.h"

static int	getbuf(char **buf, char *delimit)
{
	*buf = readline("> ");
	if (ft_strncmp(*buf, delimit, ft_strlen(*buf)) == 0)
		return (-1);
	return (0);
}

void	ft_heredoc(struct cmd *cmd)
{
	char			*buf;
	struct doredir	*redircmd;

	redircmd = (struct doredir *)cmd;
	if ((open(".tmp", redircmd->right, 0600)) < 0)
		ft_error("open error", 1);
	while (getbuf(&buf, redircmd->file) >= 0)
	{
		if ((write(3, buf, ft_strlen(buf)) < 0))
			ft_error("write error", 1);
		if ((write(3, "\n", 1) < 0))
			ft_error("write error", 1);
	}
	if ((open(".tmp", O_RDONLY)) < 0)
		ft_error("open error", 1);
	close(3),
	unlink(".tmp");
	dup2(4, 0);
	close(4);
	free(buf);
	ft_runcmd(redircmd->cmd);
}
