/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsecmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:11:23 by irifarac          #+#    #+#             */
/*   Updated: 2023/07/21 14:37:10 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

static t_cmd	*ft_parseexec(char **str, char *estr)
{
	t_cmd		*ret;
	t_execcmd	*cmd;
	char		*ftoken;
	char		*eftoken;
	int			token;
	int			argc;

	ret = ft_buildexec();
	cmd = (t_execcmd *)ret;
	argc = 0;
	while (!ft_find(str, estr, "|"))
	{
		token = ft_gettoken(str, estr, &ftoken, &eftoken);
		printf("ftoken: %s y token %c\n", ftoken, (char)token);
		if (token == 0)
			break ;
		if (token != 'z')
			ft_error("syntax", 1);
		cmd->argv[argc] = ftoken;
		cmd->eargv[argc] = eftoken;
		argc++;
		if (argc == MAXARGS)
			ft_error("too many arguments", 1);
	}
	cmd->argv[argc] = 0;
	cmd->eargv[argc] = 0;
	return (ret);
}

static t_cmd	*ft_parsepipe(char **str, char *estr)
{
	t_cmd	*cmd;

	cmd = ft_parseexec(str, estr);
	if (ft_find(str, estr, "|"))
	{
		ft_gettoken(str, estr, 0, 0);
		cmd = ft_buildpipe(cmd, ft_parsepipe(str, estr));
	}
	return (cmd);
}

static t_cmd	*ft_parseline(char **str, char *estr)
{
	t_cmd	*cmd;

	cmd = ft_parsepipe(str, estr);
	if (ft_find(str, estr, ";"))
	{
		ft_gettoken(str, estr, 0, 0);
		cmd = ft_buildback(cmd);
	}
	return (cmd);
}

static t_cmd	*ft_nulterminate(t_cmd *cmd)
{
	t_execcmd	*exec;
	t_pipecmd	*pipe;
	t_backcmd	*back;
	int			i;

	if (cmd == 0)
		return (0);
	if (cmd->type == EXEC)
	{
		exec = (t_execcmd *)cmd;
		i = 0;
		while (exec->argv[i])
		{
			*exec->eargv[i] = 0;
			i++;
		}
	}
	else if (cmd->type == PIPE)
	{
		pipe = (t_pipecmd *)cmd;
		ft_nulterminate(pipe->left);
		ft_nulterminate(pipe->right);
	}
	else if (cmd->type == BACK)
	{
		back = (t_backcmd *)cmd;
		ft_nulterminate(back->cmd);
	}
	return (cmd);
}

t_cmd	*ft_parsecmd(char *str)
{
	char	*estr;
	t_cmd	*cmd;

	estr = ft_strlen(str) + str;
	cmd = ft_parseline(&str, estr);
	ft_find(&str, estr, "");
	if (str != estr)
	{
		ft_error("syntax", 1);
	}
	ft_nulterminate(cmd);
	return (cmd);
}
