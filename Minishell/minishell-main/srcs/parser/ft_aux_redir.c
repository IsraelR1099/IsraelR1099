/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 20:39:31 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/21 21:47:26 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../Libft/libft.h"

void	ft_p_struct(t_cmd *cmd, t_cmd *srcmd[])
{
	t_cmd		*tmp;
	t_doredir	*tmpredir;
	int			i;

	i = 0;
	tmp = cmd;
	while (tmp->type == 2 || tmp->type == 1)
	{
		tmpredir = (t_doredir *)tmp;
		srcmd[i] = tmp;
		tmp = tmpredir->cmd;
		i++;
		if (i >= _POSIX_OPEN_MAX)
			ft_error("maximum number of open files exceed", 1);
	}
}

void	ft_redir_exec(t_cmd *cmd)
{
	t_doredir	*redircmd;

	redircmd = (t_doredir *)cmd;
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

static void	ft_file(char *ftoken, char *eftoken, char *file)
{
	ft_memset(file, 0, sizeof(file));
	ft_memcpy(file, ftoken, eftoken - ftoken);
	file[eftoken - ftoken] = '\0';
}

t_cmd	*ft_simple_redir(t_cmd *cmd, char **ftoken,
char **eftoken, int operator)
{
	char	file[20];
	int		pointers[2];

	ft_file(*ftoken, *eftoken, file);
	if (operator == '<')
	{
		pointers[0] = O_RDONLY;
		pointers[1] = 0;
		cmd = ft_buildredir(cmd, *ftoken, *eftoken, pointers);
	}
	else if (operator == '>')
	{
		pointers[1] = 1;
		if (access(file, F_OK) == 0)
		{
			pointers[0] = O_WRONLY | O_APPEND;
			cmd = ft_buildredir(cmd, *ftoken, *eftoken, pointers);
		}
		else
		{
			pointers[0] = O_WRONLY | O_CREAT | O_TRUNC;
			cmd = ft_buildredir(cmd, *ftoken, *eftoken, pointers);
		}
	}
	return (cmd);
}

t_cmd	*ft_double_redir(t_cmd *cmd, char **ftoken,
char **eftoken, int operator)
{
	char	file[20];
	int		pointers[2];

	ft_memset(file, 0, sizeof(file));
	ft_memcpy(file, *ftoken, *eftoken - *ftoken);
	file[*eftoken - *ftoken] = '\0';
	pointers[1] = 1;
	if (operator == '+')
	{
		pointers[0] = WCA;
		if (access(file, F_OK) == 0)
			cmd = ft_buildredir(cmd, *ftoken, *eftoken, pointers);
		else
			cmd = ft_buildredir(cmd, *ftoken, *eftoken, pointers);
	}
	else if (operator == '-')
	{
		pointers[0] = RDCE;
		cmd = ft_buildredir(cmd, *ftoken, *eftoken, pointers);
	}
	return (cmd);
}
