/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:05:05 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/23 22:08:12 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../Libft/libft.h"

static int	getbuf(char **buf, int size, char *delimit)
{
	ft_memset(*buf, 0, size);
	*buf = readline("> ");
	if (ft_strncmp(*buf, delimit, ft_strlen(*buf)) == 0)
		return (-1);
	return (0);
}

void	ft_heredoc(t_cmd *cmd, t_env *env)
{
	char			*buf;
	t_doredir		*redircmd;

	buf = (char *)malloc(sizeof(char) * 200);
	if (!buf)
		ft_error("malloc error", 1);
	redircmd = (t_doredir *)cmd;
	if ((open(".tmp", redircmd->right, 0600)) < 0)
		ft_error("open error", 1);
	while (getbuf(&buf, sizeof(buf), redircmd->file) >= 0)
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
	ft_runcmd(redircmd->cmd, env);
}
