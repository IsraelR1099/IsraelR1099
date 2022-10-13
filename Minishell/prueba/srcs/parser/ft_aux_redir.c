/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 20:39:31 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/13 17:41:29 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../Libft/libft.h"
#include <errno.h>

static int	getbuf(char **buf, int size, char *delimit)
{
	ft_memset(*buf, 0, size);
	*buf = readline("> ");
	if (ft_strncmp(*buf, delimit, ft_strlen(*buf)) == 0)
		return (-1);
	return (0);
}

void	p_struct(struct cmd *cmd, struct cmd *srcmd[])
{
	struct cmd		*tmp;
	struct doredir	*tmpredir;
	int				i;

//	printf("entro en pstruct\n");
	i = 0;
	tmp = cmd;
	while (tmp->type == 2 || tmp->type == 1)
	{
//		printf("entro en bucle pstruct tmp: %p\n", tmp);
		tmpredir = (struct doredir *)tmp;
		srcmd[i] = tmp;
		tmp = tmpredir->cmd;
		i++;
		if (i >= _POSIX_OPEN_MAX)
			ft_error("maximum number of open files exceed", 1);
	}
}

static void	*ft_change(void *file)
{
	ft_memcpy(file, ".tmp2", 5);
	return (file);
}

void	ft_heredoc(struct cmd *cmd)
{
	char			*buf;
	char			file[20] = ".tmp";
	struct doredir	*redircmd;
	int				fd;

//	printf("entro en heredoc\n");
	buf = (char *)malloc(sizeof(char) * 200);
	if (!buf)
		ft_error("malloc error", 1);
	if ((access(file, F_OK) == 0))
	{
		ft_change(file);
	}
	redircmd = (struct doredir *)cmd;
	if ((fd = open(file, redircmd->right, 0600)) < 0)
	{
		printf("errno es %d\n", errno);
		ft_error("open error", 1);
	}
//	printf("fd es %d\n", fd);
	while (getbuf(&buf, sizeof(buf), redircmd->file) >= 0)
	{
		if ((write(3, buf, ft_strlen(buf)) < 0))
			ft_error("write error", 1);
		if ((write(3, "\n", 1) < 0))
			ft_error("write error", 1);
	}
	if ((open(file, O_RDONLY)) < 0)
		ft_error("open error", 1);
	close(3),
	unlink(file);
	dup2(4, 0);
	close(4);
	free(buf);
	ft_runcmd(redircmd->cmd);
}
