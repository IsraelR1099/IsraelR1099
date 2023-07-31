/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsecmd3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:21:54 by irifarac          #+#    #+#             */
/*   Updated: 2023/07/31 13:19:55 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

static t_cmd	*ft_parseexec(char **pstr, char *estr)
{
	t_cmd		*ret;
	t_execcmd	*cmd;
	int			token;
	int			argc;
	char		*ftoken;
	char		*eftoken;

	ret = ft_buildexec();
	cmd = (t_execcmd *)ret;
	while (!ft_find(pstr, estr, "|"))
	{
		token = ft_gettoken(pstr, estr, &ftoken, &eftoken);
		if (token == 0)
			break ;
		if (token != 'a')
			ft_error("syntax error", 258);
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

static t_cmd	*ft_parsepipe(char **pstr, char *estr)
{
	t_cmd	*cmd;

	cmd = ft_parseexec(pstr, estr);
	if (ft_find(pstr, estr, "|"))
	{
		ft_gettoken(pstr, estr, 0, 0);
		cmd = ft_buildpipe(cmd, ft_parsepipe(pstr, estr));
	}
	return (cmd);
}

static t_cmd	*ft_parseline(char **pstr, char *estr)
{
	t_cmd	*cmd;

	cmd = ft_parsepipe(pstr, estr);
	if (ft_find(pstr, estr, ";"))
	{
		ft_gettoken(pstr, estr, 0, 0);
		cmd = ft_buildlist(cmd, ft_parseline(pstr, estr));
	}
	return (cmd);
}

static t_cmd	*ft_nullterminate(t_cmd *cmd)
{
	t_execcmd	*exec;
	t_pipecmd	*pipe;
	t_listcmd	*list;
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
		ft_nullterminate(pipe->left);
		ft_nullterminate(pipe->right);
	}
	else if (cmd->type == LIST)
	{
		list = (t_listcmd *)cmd;
		ft_nullterminate(list->left);
		ft_nullterminate(list->right);
	}
	return (cmd);
}

t_cmd	*ft_parsecmd(char *str)
{
	t_cmd	*cmd;
	char	*estr;

	estr = str + ft_strlen(str);
	cmd = ft_parseline(&str, estr);
	ft_find(str, estr, "");
	if (str != estr)
		ft_error("syntax", 258);
	ft_nullterminate(cmd);
	return (cmd);
}
